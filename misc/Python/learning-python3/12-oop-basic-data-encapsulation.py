
# Data encapsulation: This prevents data from direct modification which is called encapsulation. Restrictive access using _ or __ prefix

class Computer:

    # __maxprice is private attr/encapsulated data
    def __init__(self):
        self.__maxprice = 900

    def sell(self):
        print("Selling Price: {}".format(self.__maxprice))

    def setMaxPrice(self, price):
        self.__maxprice = price

c = Computer()
c.sell()

# Trying to access private attribute, we will observe no change
# change the price
c.__maxprice = 1000
c.sell()

# using setter function
c.setMaxPrice(1000)
c.sell()
