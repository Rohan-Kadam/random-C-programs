#! /usr/bin/env python3

from collections import Counter
from scapy.all import sniff

## Create a Packet Counter
packet_counts = Counter()

## Define our Custom Action function
def custom_action(packet):
    # Create tuple of Src/Dst in sorted order
    key = tuple(sorted([packet[0][1].src, packet[0][1].dst]))
    packet_counts.update([key])
    print(packet_counts)
    return f"Packet #{sum(packet_counts.values())}: {packet[0][1].src} ==> {packet[0][1].dst}"

## Setup sniff, filtering for IP traffic
sniff(filter="ip", prn=custom_action, count=10)

# Print packet counter dict (2 keys and corresponding counts)
print("\n""sniff complete")
print(packet_counts)

## Print out packet count per A <--> Z address pair
print("\n".join(packet_counts.items()))
print("\n".join(f"{f'{key[0]} <--> {key[1]}'}: {count}" for key, count in packet_counts.items()))

