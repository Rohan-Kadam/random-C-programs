#! /usr/bin/env python3
# Use following command in scapy interactive interface to generate ARP
# p = Ether(dst="18:5e:0f:12:f2:c3")/ARP()
# sendp(p)

from scapy.all import sniff

pkts = sniff(filter="arp", count=3)
print(pkts.summary())
