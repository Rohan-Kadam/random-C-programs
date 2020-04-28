#! /usr/bin/env python3

from scapy.all import sniff

packets =  sniff(offline='filename.cap')
packets
packets.summary()
