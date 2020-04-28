#! /usr/bin/env python3

from scapy.all import sniff

# create packet list
packets = []

# custom action function
def customAction(packet):
    packet[Ether].dst = "00:11:22:aa:bb:cc"
    packet[Ether].src = "00:11:22:aa:bb:cc"

for sniffed_packet in sniff(offline='filename.cap', prn=customAction):
    packets.append(sniffed_packet)

# See edited MAC addresses in packet 'Ether' layer
packets[0][Ether].summary()
packets[0][Ether].show()

