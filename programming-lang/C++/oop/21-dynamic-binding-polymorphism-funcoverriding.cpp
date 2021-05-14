/*
 * Polymorphism is a feature of OOPs that allows the object to behave differently in different conditions
 *
 * Type 2
 * Run Time Polymorphism = Dynamic binding = Late binding = Function overridding
 *
 */

#include <iostream>
using namespace std;
class BaseClass {
public:
   
   //Overridden Function
   void disp(){
      cout<<"Function of Parent Class"<<endl;  
   }

   void dispXYZ(){
      cout<<"FunctionXYZ of Parent Class"<<endl;
   }
};
class DerivedClass: public BaseClass{
public:
  
   //Overridding Function
   void disp() {
      cout<<"Function of Child Class"<<endl;
   }

   void dispXYZ(){
      cout<<"FunctionXYZ of Child Class"<<endl;
   }
};
int main() {
   /* Reference of base class pointing to
    * the object of child class.
    *
    * Calling Overridden (parent) function using parent obj
    */

   BaseClass obj = BaseClass();
   //below line also has same effect?
   //BaseClass obj = DerivedClass();
   obj.disp();

   //Calling Overriding (child) function using child obj
   DerivedClass obj2 = DerivedClass();
   obj2.disp();
   
   //Calling Overridden (parent) function using child obj
   obj2.BaseClass::dispXYZ();

   //Calling Overridding (child) function using parent obj
   //Check Virtual functions
    
   return 0;
}
