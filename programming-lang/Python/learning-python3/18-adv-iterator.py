
# ITERATOR
# Iterator in Python is simply an object that can be iterated upon. An object which will return data, one element at a time.
# Technically, a Python iterator object must implement two spl methods, __iter__() and __next__(), collectively called the iterator protocol.
# An object is called iterable if we can get an iterator from it. Most built-in containers like: list, tuple, string etc. are iterables.
# The iter() function (which in turn calls the __iter__() method) returns an iterator from them.

# For loop which is iterable is implementated using infinite while loop and iterator

# FOR
#for element in iterable:
#    # do something with element

# FOR using WHILE
## create an iterator object from that iterable
#iter_obj = iter(iterable)
#
## infinite loop
#while True:
#    try:
#        # get the next item
#        element = next(iter_obj)
#        # do something with element
#    except StopIteration:
#        # if StopIteration is raised, break from loop
#        break


# Remove max check, to make it infinite iterator
class PowTwo:
    """Class to implement an iterator
    of powers of two"""

    def __init__(self, max=0):
        self.max = max

    def __iter__(self):
        self.n = 0
        return self

    def __next__(self):
        if self.n <= self.max:
            result = 2 ** self.n
            self.n += 1
            return result
        else:
            raise StopIteration


# In-built Iterator (+1)
my_list = [4, 7, 0, 3]
# get an iterator using iter()
my_iter = iter(my_list)
# iterate through it using next(),__next__
print(next(my_iter))
print(next(my_iter))
print(my_iter.__next__())
print(my_iter.__next__())
#next(my_iter) # This will raise error, no items left


# Custom Iterator (+powerOf2)
# create an object
numbers = PowTwo(5)
# create an iterable from the object
i = iter(numbers)
# Using next to get to the next iterator element
print(next(i))
print(next(i))
print(next(i))
print(next(i))
print(next(i))


