#! /usr/bin/env python3
# Changed IP layer dst field to gateway IP
# Changed Domain name 

from scapy.all import DNS, DNSQR, IP, sr1, UDP

dns_req = IP(dst='192.168.0.1')/UDP(dport=53)/DNS(rd=1, qd=DNSQR(qname='www.google.com'))
answer = sr1(dns_req, verbose=0)

print(answer[DNS].summary())
print("---------------------------\n");
print(answer[DNS].show())
