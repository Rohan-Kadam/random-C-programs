
# Polymorphism : Polymorphism is an ability (in OOP) to use a common interface for multiple forms (data types).
# Suppose, we need to color a shape, there are multiple shape options (rectangle, square, circle). 
# However we could use the same method to color any shape. This concept is called Polymorphism.

class Parrot:

    def fly(self):
        print("Parrot can fly")

    def swim(self):
        print("Parrot can't swim")

class Penguin:

    def fly(self):
        print("Penguin can't fly")

    def swim(self):
        print("Penguin can swim")

# common interface = polymorphed method (Note:not a class, just function with argument)
def flying_test(birdasdf):
    # object was passed as argument, and classes of both object have fly. So flytest_test calls correct fly using object passed as argument
    birdasdf.fly()

#instantiate objects
blu = Parrot()
peggy = Penguin()

# passing the object
flying_test(blu)
flying_test(peggy)
