
# Overloading plus operator and also manually taking point input instead of auto point i.e.p = (1,1)
class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    # Without this print(p1) will give memory address of p1
    def __str__(self):
        return "({0},{1})".format(self.x, self.y)

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        #Return the added 2D point to print function, which then calls __str__
        return Point(x, y)


# Default way of point is p = (1,1) and on print(p) we get (1,1)
p1 = Point(1, 2)
p2 = Point(2, 3)

# Adding two 2D points
print(p1+p2)
