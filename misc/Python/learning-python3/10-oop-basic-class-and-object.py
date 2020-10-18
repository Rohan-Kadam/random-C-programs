
# OOPs
# One of the popular approaches to solve a programming problem is by creating objects. This is known as Object-Oriented Programming (OOP).
# The concept of OOP in Python focuses on creating reusable code. This concept is also known as DRY (Don't Repeat Yourself).

# Class and Objects

# Class = Structures with functions
class Parrot:

    # class attribute = variables for class only (object need to use __class__ to access it or direct ref class name)
    # These are special since its shared by all objects of type Parrot
    species = "bird"

    # instance attribute = constructor + variables for object instantiated
    # These are unique for each instatiated object of this class
    # No destructor as python has in-built garbage collector, which destroys the object
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # instance method = functions
    def sing(self, song):
        return "{} sings {}".format(self.name, song)

    # instance method = functions
    def dance(self):
        return "{} is now dancing".format(self.name)

# Object = Structure instance
# instantiate the Parrot class
blu = Parrot("Blu", 10)
woo = Parrot("Woo", 15)

# access the class attributes
print("Blu is a {}".format(blu.__class__.species))
print("Woo is also a {}".format(woo.__class__.species))
print("Woo is also a {}".format(Parrot.species))

# access the instance attributes
print("{} is {} years old".format( blu.name, blu.age))
print("{} is {} years old".format( woo.name, woo.age))

# call our instance methods
print(blu.sing("'Happy'"))
print(blu.dance())
