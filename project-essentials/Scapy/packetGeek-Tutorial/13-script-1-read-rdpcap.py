#! /usr/bin/env python3

from scapy.all import rdpcap

packets = rdpcap('filename.cap')
packets
packets.summary()
