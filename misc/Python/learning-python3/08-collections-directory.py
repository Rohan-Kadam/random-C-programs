
# COLLECTIONS : Dictionary {:}
#-------------------------------------------------------------------------------------------------------
# There are four collection data types in the Python programming language:

#    List is a collection which is ordered and changeable. Allows duplicate members.
#    Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
#    Set is a collection which is unordered and unindexed. No duplicate members.
#    Dictionary is a collection which is unordered, changeable and indexed. No duplicate members.

myDict = {'name': 'Jack', 'age': 26}
print(myDict)
print(myDict.get('age'))
myDict['age'] = 27
print(myDict)
print(myDict.pop('age'))
print(myDict)

#Built-in dict methods
#clear()	Removes all the elements from the dictionary
#copy()	        Returns a copy of the dictionary
#fromkeys()	Returns a dictionary with the specified keys and value
#get()	        Returns the value of the specified key
#items()	Returns a list containing a tuple for each key value pair
#keys()	        Returns a list containing the dictionary's keys
#pop()	        Removes the element with the specified key
#popitem()	Removes the last inserted key-value pair
#setdefault()	Returns the value of the specified key. If the key does not exist: insert the key, with the specified value
#update()	Updates the dictionary with the specified key-value pairs
#values()	Returns a list of all the values in the dictionary
