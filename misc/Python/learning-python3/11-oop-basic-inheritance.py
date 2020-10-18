
# Inheritance: Inheritance is a way of creating a new class for using details of an existing class without modifying it.

# parent class
class Bird:

    birdVar = "birdVar"

    def __init__(self):
        print("Bird is ready with %s class attr" %Bird.birdVar)

    def whoisThis(self):
        print("Bird")

    def swim(self):
        print("Swim faster")

# Inside bracket we specify parent class, and inherit its methods, attr
# child class
class Penguin(Bird):

    def __init__(self):
        # call super() function
        # This is basically calling parent function whenever we call this child function
        super().__init__()
        print("Accessing parent's class attr: %s" %super().birdVar)
        print("Penguin is ready")

    def whoisThis(self):
        print("Penguin")

    def run(self):


        print("Run faster")

peggy = Penguin()
peggy.whoisThis()
peggy.swim()
peggy.run()


