#! /usr/bin/env python3

from scapy.all import wrpcap,sniff

packets = sniff(count=10)
packets
wrpcap('sniffed.pcap', packets)
