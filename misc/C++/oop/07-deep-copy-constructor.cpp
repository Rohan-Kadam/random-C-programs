
/*
 * DEEP COPY CONSTRUCTOR
 *
 * A deep copy copies all fields, and makes copies of dynamically allocated memory pointed to by the fields. 
 * To make a deep copy, you must write a copy constructor and overload the assignment operator, 
 * otherwise the copy will point to the original, with disasterous consequences. 
 *
 */

#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{
	private:
	int x;

    char *s_copy;
    public:
    CopyConstructor (const char *sam,int xVal)
    {
        s_copy = new char[16];  //Dynamic memory alocation
		x = xVal;
        strcpy(s_copy, sam);
    }
    
    //Copy constructor + assignment operator overloaded?(two new funcs? so two separate mem location?)
    CopyConstructor (const CopyConstructor &sam)
    {
        s_copy = new char[16]; //Dynamic memory alocation
		x = sam.x;
        strcpy(s_copy, sam.s_copy);
    }
    
    void concatenate(const char *str)
    {
        strcat(s_copy, str); //Concatenating two strings
	x = 100;
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
