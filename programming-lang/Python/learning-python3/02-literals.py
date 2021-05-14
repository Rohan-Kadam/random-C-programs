# Literals = Raw data

a = 0b1010 #Binary Literals
b = 100 #Decimal Literal
c = 0o310 #Octal Literal
d = 0x12c #Hexadecimal Literal

#Float Literal
float_1 = 10.5
float_2 = 1.5e2

#Complex Literal
x = 3.14j

#String and Char Literal
strings = "This is Python"
char = "C"

#Multiline String Literal
#Below line wont work on removing triple double quotes
multiline_str = """This is a multiline string wit
h more than one line code."""

#Unicode and Raw Literals
#Unicode is a superset of ASCII, ASCII define 128 characters whereas UNICODE defines 2^21 characters
#Raw string literal will allow you to print \n as normal character, Normal string would add a next line there.
unicode = u"\u00dcnic\u00f6de"
raw_str = r"raw \n string"

#Boolean Literals
x = (1 == True)
y = (1 == False)
a = True + 4
b = False + 10

print(a, b, c, d)
print(float_1, float_2)
print(x, x.imag, x.real)
print(strings)
print(char)
print(multiline_str)
print(unicode)
print(raw_str)
print("x is", x)
print("y is", y)
print("a:", a)
print("b:", b)


