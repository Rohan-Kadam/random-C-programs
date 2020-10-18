#include <iostream>
using namespace std;

//Abstract base class
class Base          
{

	//By default private
	//Can be accessed by mem func, friend func and friend class mem func
	//Base b; //Assuming not a abstract class
	//b.y // Not possible unless its public var.
	int y=99;
    public:
    
	int x=10;
	//virtual class != virtual function. 
	//Virtual class is used to solve diamond problem in inheritance
	//Virtual func is used to create Pure virtual func for abstract class/interface
	    virtual void show() = 0;    // Pure Virtual Function
	    void xyz(){}

};

class Derived:public Base
{
    public:
    //void show();
    //{ 
    //    cout << "Implementation of Virtual Function in Derived class\n"; 
    //}
};

class Child:public Derived
{	
	int z=99;
public:
    void show()
    { 
        cout << "Implementation of Virtual Function in Derived class\n"; 
    }
};

int main()
{
    //Base obj;   //Compile Time Error
    Base *b;
    //Derived d;
    Child d;
    b = &d;
    b->show();
    cout<<"--->"<<b->z<<endl;
}

