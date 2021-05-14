
# GENERATOR
# Generator functions are functions which use yield instead of return statement. What yield does is that, it allows us to pause and resume
# function execution from point where it was previously paused. The generator function is said to have lazy execution (producing items only 
# when asked for).
# Advantages
# 1.  Memory Efficient
# A normal function to return a sequence will create the entire sequence in memory before returning the result. This is an overkill, if the 
# number of items in the sequence is very large. Generator implementation of such sequences is memory friendly and is preferred since it 
# only produces one item at a time.
#
# 2. Represent Infinite Stream
# Generators are excellent mediums to represent an infinite stream of data. Infinite streams cannot be stored in memory, and since generators 
# produce only one item at a time, they can represent an infinite stream of data.
#
# 3. Pipelining Generators
# Multiple generators can be used to pipeline a series of operations. This is best illustrated using an example.
# Suppose we have a generator that produces the numbers in the Fibonacci series. And we have another generator for squaring numbers.
# If we want to find out the sum of squares of numbers in the Fibonacci series, we can do it in the following way by pipelining the output of
# generator functions together. SEE FIBONACCI EXAMPLE
#
# Generator Expression Example and FIBONACCI Example uses generator expressions create anonymous generator functions. Similar to the lambda 
# functions which create anonymous functions. Simple Generator Example does not uses generator expression.

# A simple generator function
def my_gen():
    n = 1
    print('This is printed first')
    # Generator function contains yield statements
    yield n

    n += 1
    print('This is printed second')
    yield n

    n += 1
    print('This is printed at last')
    yield n


def fibonacci_numbers(nums):
    x, y = 0, 1
    for _ in range(nums):
        x, y = y, x+y
        yield x

def square(nums):
    for num in nums:
        yield num**2


# Simple Generator Example          * Ex.1 *
print("\nSimple Generator example:")
for item in my_gen():
    print(item)


# Generator Expression Example      * Ex.2 *
print("\nGenerator Expression example:")
# Initialize the list
my_list = [1, 3, 6, 10]
# square each term using list comprehension
list_ = [x**2 for x in my_list]
# same thing can be done using a generator expression
# generator expressions are surrounded by parenthesis ()
generator = (x**2 for x in my_list)
#Prints all at once
print(list_)
#Prints one-by-one
print(next(generator))  # "print(generator)" This will give obj address
print(next(generator))
print(next(generator))
print(next(generator))


# FIBONACCI Example                 * Ex.3 *
print("\nFibonacci example:")
print(sum(square(fibonacci_numbers(10))))


