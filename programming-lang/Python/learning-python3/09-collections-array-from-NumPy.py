
# COLLECTIONS : List []
#-------------------------------------------------------------------------------------------------------

#    List is a collection which is ordered and changeable. Allows duplicate members.
#    Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
#    Set is a collection which is unordered and unindexed. No duplicate members.
#    Dictionary is a collection which is unordered, changeable and indexed. No duplicate members.

#    Array 

import numpy as np

arr = np.array([1, 2, 3, 4, 5])
print(arr)
print(type(arr))

arr3d = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
print(arr3d[0, 1, 2])


# COPY and VIEW
# Changes in copy, no affect on original
# Changes in view, affect on original and vice-versa
arrC = np.array([1, 2, 3, 4, 5])
xC = arrC.copy()
arrC[0] = 42
print(arrC)
print(xC) 
xC[0] = 31
print(arr)
print(xC) 

arrV = np.array([1, 2, 3, 4, 5])
xV = arr.view()
arrV[0] = 42
print(arrV)
print(xV)
xV[0] = 31
print(arr)
print(xV)


# BASE
# Used to check who own's data, that returns None if the array owns the data 
# Otherwise, the base  attribute refers to the original objec
arrB = np.array([1, 2, 3, 4, 5])
xB = arrB.copy()
yB = arrB.view()
print(xB.base)
print(yB.base)

