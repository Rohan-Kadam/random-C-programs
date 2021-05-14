
# COLLECTIONS : Tuple ()
#-------------------------------------------------------------------------------------------------------
# There are four collection data types in the Python programming language:

#    List is a collection which is ordered and changeable. Allows duplicate members.
#    Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
#    Set is a collection which is unordered and unindexed. No duplicate members.
#    Dictionary is a collection which is unordered, changeable and indexed. No duplicate members.

myTuple = (1, "Hello", 3.4)
print(myTuple)
print("Hello" in myTuple)

#Built-in tuple method
#count()	Returns the number of times a specified value occurs in a tuple
#index()	Searches the tuple for a specified value and returns the position of where it was found

#Using Tuple over List
#   --  If you have data that doesn't change, implementing it as tuple will guarantee that it remains write-protected.
#   --  Since tuples are immutable, iterating through a tuple is faster than with list. So there is a slight performance boost.
