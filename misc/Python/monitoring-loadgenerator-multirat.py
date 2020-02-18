# For delay
import time
# For seed and pseudorandom number generator
from random import random
from random import seed
# For json 
import json

sample = []
max = 10
min = 1
# seed random number generator
seed(1)

while 1:
    for _ in range(5):
        value = random()
        scaled_value = min + (value * (max - min))
        scaled_value = round(scaled_value,4)
        sample.append(scaled_value)
    
    print(sample)
    json_sample = json.dumps(sample)
    print(json_sample)
    sample.clear()
    time.sleep(1)
