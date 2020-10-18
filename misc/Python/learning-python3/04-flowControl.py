
# if-else
# for
# while
# Other keywords->  break and continue same as C. 
#                   pass used to fill empty loops/funcs with NOP instruction. Empty loops give error
#                   - pass used when loop or a function that is not implemented yet, but we want to implement it in the future
#                   - pass = NOPS and comment = ignored


def ifelif1():
    num = 3.4
    if num > 0:
        print("Positive number")
    elif num == 0:
        print("Zero")
    else:
        print("Negative number")

def for1():
    genre = ['pop', 'rock', 'jazz']
    for i in range(len(genre)):
        print("I like", genre[i])

def for2():
    genre = ['pop', 'rock', 'jazz']
    for i in genre:
        print("I like", i)

def while1():
    n = 10
    sum = 0
    i = 1
    
    while i <= n:
        sum = sum + i
        i = i+1 
    print("The sum is", sum)

print('\n\nif-else Example')
ifelif1()
print('\n\nfor Examples')
for1()
for2()
print('\n\nwhile Examples')
while1()
