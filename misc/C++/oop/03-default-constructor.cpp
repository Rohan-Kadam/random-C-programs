
/*
 * Constructor vs Member Functions
 *
1) Constructor doesn’t have a return type. Member function has a return type.
2) Constructor is automatically called when we create the object of the class. Member function needs to be called explicitly using object of class.
3) When we do not create any constructor in our class, C++ compiler generates a default constructor and insert it into our code. The same does not apply to member functions.
 *
 */


#include <iostream>
using namespace std;
class constructorDemo{
public:
   int num;
   char ch;
   /* This is a default constructor of the
    * class, do note that it's name is same as
    * class name and it doesn't have return type.
    */
   constructorDemo() {
      num = 100; ch = 'A';
   }
};
int main(){
   /* This is how we create the object of class,
    * I have given the object name as obj, you can
    * give any name, just remember the syntax:
    * class_name object_name;
    */
   constructorDemo obj;

   /* This is how we access data members using object
    * we are just checking that the value we have
    * initialized in constructor are reflecting or not.
    */
   cout<<"num: "<<obj.num<<endl;
   cout<<"ch: "<<obj.ch;
   return 0;
}
