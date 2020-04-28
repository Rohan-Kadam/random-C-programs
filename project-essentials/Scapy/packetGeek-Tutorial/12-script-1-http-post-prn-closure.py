#! /usr/bin/env python3

import json
import requests
from collections import Counter
from scapy.all import sniff

# define API options
url = "https://httpbin.org/post"
token = "supersecretusertoken"

# create parent function with passed in arguments
def custom_action(url: str, token: str):

  # uploadPacket function has access to the url & token parameters
  # because they are 'closed' in the nested function
  def upload_packet(packet):
    # upload packet, using passed arguments
    headers = {'content-type': 'application/json'}
    data = {
        'packet': packet.summary(),
        'token': token,
    }
    r = requests.post(url, data=data, headers=headers)
    print(f"After POST, Return value of POST {r}")

  return upload_packet

sniff(prn=custom_action(url, token))

