
# LAMBDA
# Lambda is an anonymous function is a function. While normal functions are defined using the def keyword in Python, anonymous functions are 
# defined using the lambda keyword.
# Syntax: lambda arguments: expression
#
# Lambda is used in filter() and map() built-in functions


def normaldouble(x):
   return x * 2

# Simple Lambda Example             * Ex.1 *
print("\nSimple Lambda example:")
double = lambda x: x * 2
print(double(5))
print(normaldouble(5))

# Filter Example                    * Ex.2 *
# takes in a function and a list as arguments
# returns new list from list for which the function evaluates to True
print("\nFilter example:")
my_list = [1, 5, 4, 6, 8, 11, 3, 12]
new_list = list(filter(lambda x: (x%2 == 0) , my_list))
print(new_list)

# Map Example                       * Ex.3 *
# takes in a function and a list as arguments
# returns new list after applying the function to all list items
print("\nMap example:")
my_list = [1, 5, 4, 6, 8, 11, 3, 12]
new_list = list(map(lambda x: x * 2 , my_list))
print(new_list)

