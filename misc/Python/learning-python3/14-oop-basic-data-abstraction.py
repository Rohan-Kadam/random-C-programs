
# Abstraction : Hiding the implementation 
# *DONOT* confuse with encapsulation. Encapsulation is hiding the information(i.e. Vars/methods),making information unaccessible. 
# - Objects cannot be created from an abstract base class. (No Animal object in code)
# - You can use an abstract base class to create a blue print. (Cat and Dog inherit from Animal but parent has no implementation, just bp)
# - You can have one more sub classes that inherit from the abstract base class. (same as above. Animal is just for reference. Done right, we
#   can change representation without breaking the code)
# *DONOT* confuse with polymorphism. Polymorphism means reuse with different types.
# Normally in C++ like languages Polymorphism = same func with different arg types. So correct func called based on type of arg passed. In Python since we have no type its a bit different, here we call the correct func based on the object pass as arg to common interface function. This interface (i.e common func) is needed in python, not needed in C++. 

# (obj1)(obj2)->(INTERFACE)->(Class1)(Class2)                           :   Polymorphism (INTERFACE = common function)
# (obj1)->(Class1), (obj2)->(Class2) and (Class1)(Class2)->(INTERFACE)  :   Abstraction  (INTERFACE = abstract(no implementation) base class)

# The word interface creates confusion as interface is generally the abstract base class in other languages (in this case Animal), but the common function used for polymorphism is also reffered as interface. 
# So, remember the flow diagram shown above.
# In Words:- In python polymorphism = interface (i.e common function), which is called with obj type as arg by diff objects, the interface then uses obj to call correct func in respective class(can be derived) based on obj type and abstraction = obj calls derived class func directly that uses its own implementation, interface (i.e.base class) is just for reference. 


class Animal:
    def __init__(self, name):    # Constructor of the class
        self.name = name
    def talk(self):              # Abstract method, defined by convention only
        raise NotImplementedError("Subclass must implement abstract method")

class Cat(Animal):
    def talk(self):
        return 'Meow!'

class Dog(Animal):
    def talk(self):
        return 'Woof! Woof!'

animals = [Cat('Missy'),
           Cat('Mr. Mistoffelees'),
           Dog('Lassie')]

for animal in animals:
    print (animal.name + ': ' + animal.talk())
