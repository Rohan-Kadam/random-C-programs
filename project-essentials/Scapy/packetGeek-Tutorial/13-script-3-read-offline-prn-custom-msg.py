#! /usr/bin/env python3

from scapy.all import sniff

def customAction(packet):
    return f"{packet[0][1].src} ==> {packet[0][1].dst}"

packets =  sniff(offline='filename.cap', prn=customAction)
packets
packets.summary()
