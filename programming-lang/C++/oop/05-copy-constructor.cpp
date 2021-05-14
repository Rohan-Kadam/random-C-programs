/*
 * Here a second object generated using first one, it has separate memory spaces. We have copied same content in it as well but operation on
 * one won't reflect on another. That happens if we have shallow copy i.e. values of both object stored in same memory space
 *
 * Usual form X (X&) where X is the class name.
 */

#include<iostream>
using namespace std;
class Samplecopyconstructor
{
    private:
    int x, y;   //data members
    
    public:
    Samplecopyconstructor(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    
    /* Copy constructor */
    Samplecopyconstructor (const Samplecopyconstructor &sam)
    {
        x = sam.x;
        y = sam.y;
    }

    void test(){
    	x=999;
    }

    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
};
/* main function */
int main()
{
    Samplecopyconstructor obj1(10, 15);     // Normal constructor
    Samplecopyconstructor obj2 = obj1;      // Copy constructor
    obj2.test();
    cout<<"Normal constructor : ";
    obj1.display();
    cout<<"Copy constructor : ";
    obj2.display();
    return 0;
}
