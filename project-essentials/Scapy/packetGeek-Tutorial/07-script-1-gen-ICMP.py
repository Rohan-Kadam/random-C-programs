#! /usr/bin/env python3
# To run this code use following command
# sudo chmod +x <filename>.py
# sudo python <filename>.py

from scapy.all import ICMP, sr1, IP, srloop, conf
#from scapy.all import *

#print("Hello World")
conf.iface="wlp3s0"
print(sr1(IP(dst="192.168.0.1")/ICMP()).summary())

resp = srloop(IP(dst="192.168.0.1",ttl=202)/ICMP(), count=5)
print("Ping response received")
print(resp[0])
