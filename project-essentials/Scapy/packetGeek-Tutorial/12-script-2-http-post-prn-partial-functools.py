#! /usr/bin/env python3

import json
import requests
from collections import Counter
from functools import partial
from scapy.all import sniff

# define API options
url = "https://httpbin.org/post"
token = "supersecretusertoken"


def upload_packet(api_endpoint: str, api_token: str, packet):
    # upload packet, using passed arguments
    headers = {'content-type': 'application/json'}
    data = {
        'packet': packet.summary(),
        'token': api_token,
    }
    r = requests.post(api_endpoint, data=data, headers=headers)
    print(f"After POST, Return value of POST {r}")

sniff(prn=partial(upload_packet, url, token))


