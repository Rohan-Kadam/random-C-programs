
class Person:
    "This is a person class"
    age = 10

    def greet(self):
        print('Hello')

# DOC:-
print(Person.__doc__)


# SELF:-
# create a new object of Person class
harry = Person()

# Output: <function Person.greet>
print(Person.greet)

# Output: <bound method Person.greet of <__main__.Person object>>
print(harry.greet)

# Calling object's greet() method
# Output: Hello
harry.greet()

# This is because, whenever an object calls its method, the object itself is passed as the first argument.
# So, harry.greet() translates into Person.greet(harry)
# For these reasons, the first argument of the function in class must be the object itself. This is conventionally called self. 
# It can be named otherwise but we highly recommend to follow the convention.


# DEL
print('Person.age = %d' %Person.age)
print('Deleting Person.age and then trying to access Person.age\n')
del Person.age
print(Person.age)

# Here we deleted attr. We can delete objects also, but GC in python does delete it automatically.
