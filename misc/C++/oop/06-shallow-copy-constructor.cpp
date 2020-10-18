//
//Stack separate and common heap => Shallow copy constructor [TO VERIFY]
//object memory layout??
//

#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{

	int x;

    char *s_copy;
    public:
    CopyConstructor (const char *sam,int xVal)
    {
        s_copy = new char[16];  //Dynamic memory alocation
		x = xVal;
        strcpy(s_copy, sam);
    }
    
    /* Shallow copy constructor basically means no copy constructor. Here we directly copy obj1 to obj2. Since the class has allocated memory
     * to obj 1, same memory gets allocated to obj 2. Hence they pointing to same memory (i.e. Shallow copy)
     * Changes in one reflected in other
     *
     * Useful: 
     *
    CopyConstructor (const CopyConstructor &sam)
    {
        s_copy = new char[16]; //Dynamic memory alocation
		x = sam.x;
        strcpy(s_copy, sam.s_copy);
    }
    */
    
    void concatenate(const char *str)
    {
        strcat(s_copy, str); //Concatenating two strings
	this->x = 100;
    }

    void display()
    {
	cout<<x<<endl;
        cout<<s_copy<<endl;
    }
};
/* main function */
int main()
{
    CopyConstructor c1("Copy",10);
    CopyConstructor c2 = c1;    //copy constructor
    c1.display();
    c2.display();
    cout<<"-----------------------------"<<endl<<endl;
    c1.concatenate("Constructor");    //c1 is invoking concatenate()
    c1.display();
    c2.display();
    return 0;
}
