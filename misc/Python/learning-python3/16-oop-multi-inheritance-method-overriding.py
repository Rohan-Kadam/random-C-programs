
# We will see (1)Multilevel Inheritance, (2)Mutiple Inheritance and (3)Mutiple multilevel Inheritance

# (1)           (2)             (3)
# (A)       (A)     (B)         (X)     (Y)     (Z)
#  |         |       |           |       |       |
# (B)        ---------           -----------------
#  |             |                  (A)     (B)  |
# (C)           (C)                  |__(P)__|___|
#                                       (T)
# All base class further inherit from Object class
# Every class in Python is derived from the object class. It is the most base type in Python.
# So technically, all other classes, either built-in or user-defined, are derived classes and all objects are instances of the object class.
# Check "isinstance(t,object)" in code

class X:
    pass


class Y:
    pass


class Z:
    pass


class A(X, Y):
    pass


class B(Y, Z):
    pass

# Polygon class
class P(B, A, Z):
    def __init__(self, no_of_sides):
        self.n = no_of_sides
        self.sides = [0 for i in range(no_of_sides)]

    def inputSides(self):
        self.sides = [float(input("Enter side "+str(i+1)+" : ")) for i in range(self.n)]

    def dispSides(self):
        for i in range(self.n):
            print("Side",i+1,"is",self.sides[i])    

# Triangle class
class T(P):

    # Overriding: Here we can overriding Class T's init with Class P's init. We can use super as well.
    def __init__(self):
        P.__init__(self,3)

    def findArea(self):
        a, b, c = self.sides
        # calculate the semi-perimeter
        s = (a + b + c) / 2
        area = (s*(s-a)*(s-b)*(s-c)) ** 0.5
        print('The area of the triangle is %0.2f' %area)            

t = T()
t.inputSides()
t.dispSides()
t.findArea()

print(issubclass(P,T))
print(issubclass(T,P))
print(isinstance(t,P))
print(isinstance(t,T))
print(isinstance(t,int))
print(isinstance(t,object))

print(T.mro())



