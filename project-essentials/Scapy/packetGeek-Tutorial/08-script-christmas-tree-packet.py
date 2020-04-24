#! /usr/bin/env python3

from random import randint
from scapy.all import IP, TCP, send

# Create the skeleton of our packet
template = IP(dst="192.168.0.1")/TCP()

# Start lighting up those bits!
# Here UFP means the bits in TCP field
# U = Urgent
# F = FIN
# P = Push
template[TCP].flags = 'UFP'

# Create a list with a large number of packets to send
# Each packet will have a random TCP dest port for attack obfuscation
xmas = []
for pktNum in range(0,100):
  xmas.extend(template)
  xmas[pktNum][TCP].dport = randint(1,65535)

# Send the list of packets
send(xmas)
