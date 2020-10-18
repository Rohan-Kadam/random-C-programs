
# 1 : Type Casting
# 2 : IO
# 3 : Names

# Section 1 : Type
# We will see Implicit type allocation and then Explicit conversion to another type

def implicit():
    num_int = 123
    num_flo = 1.23
    num_str = "456"
    
    print("datatype of num_int:",type(num_int))
    print("datatype of num_flo:",type(num_flo))
    print("Data type of num_str:",type(num_str))
    
    #Auto upcasted to Float (i.e. Implicit type conversion)
    num_new = num_int + num_flo
    print("Value of num_new:",num_new)
    print("datatype of num_new:",type(num_new))
    
    #No auto upcasted here (i.e. No Implicit type conversion)
    #Below line will give error on uncommenting
    #print(num_int+num_str)

def explicit():
    
    num_int = 123
    num_str = "456"

    print("Data type of num_int:",type(num_int))
    print("Data type of num_str before Type Casting:",type(num_str))

    #Manual type cast to int (i.e. Explicit type conversion)
    num_str = int(num_str)
    print("Data type of num_str after Type Casting:",type(num_str))

    num_sum = num_int + num_str
    print("Sum of num_int and num_str:",num_sum)
    print("Data type of the sum:",type(num_sum))


# Section 2 : IO
# Printf and scanf of Python

def printf():
    x = 12.3456789
    print('The value of x is %3.2f' %x , x)
    print('The value of x is %3.4f' %x)

def scanf():
    num = input('Enter a number: ')
    print('Entered number = ', num)
    #Direct print+typecast not working?
    #print('Entered number = %s %d %f' %num,%(int(num)),%(float(num)))



# Section 3 : Names
# Name is simply a name given to objects. Everything in Python is an object. Name is a way to access the underlying object.
# Namespace is basically the scope of name. Local var has higher preference than Global/Outer ones, unless we use global identifier

def name():
    a = 2
    print('id(a) =', id(a))

    a = a+1
    print('id(a) =', id(a))

    print('id(3) =', id(3))

    b = 2
    print('id(b) =', id(b))
    print('id(2) =', id(2))
    #This is efficient as Python does not have to create a new duplicate object. 
    #This dynamic nature of name binding makes Python powerful; a name could refer to any type of object.


def printHello():
    print("Hello")
    #This is like function pointer


def outer_function():
    a = 20
    def inner_function():
        a = 30
        print('a =', a)
    inner_function()
    print('a =', a)

def namespace():
    a = 10
    outer_function()
    print('a =', a)


print("\n\nSection 1 \'Type cast\' Example 1:-")
implicit()
print("\n\nSection 1 \'Type cast\' Example 2:-")
explicit()
print("\n\nSection 2 \'IO\' Example 1:-")
printf()
scanf()
print("\n\nSection 3 \'name\' Example 1:-")
name()
print("\n\nSection 3 \'name\' Example 2:-")
a = printHello
a()
print("\n\nSection 3 \'namespace\' Example 1:-")
namespace()
