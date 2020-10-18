/*
 * What is virtual function
 * Derived classes or funcs, become virtually base class or funcs.
 * When we declare a function as virtual in a class, all the sub classes that override this function have their function implementation 
 * as virtual by default (whether they mark them virtual or not).
 *
 *
 * Why is it needed?
 * Previously we saw in section 21,
 * //Calling Overridden (parent) function using child obj
   obj2.BaseClass::dispXYZ();

   //Calling Overridding (child) function using parent obj
   //Check Virtual functions

 * So we want to call child class func from parent class object. Virtual keyword helps us. See the [Problem] comment
 * Solution without virtual = Create Dog(child) object instead of Animal(parent) in main(). This will call animalSound from Dog(child)
 * i.e. Calling Overriding (child) function using child obj
 *
 * Solution with virtual = Add virtual keyword to overridden (parent) func
 * i.e. Calling Overriding (child) function using parent obj
 *
 *
 * Why is overrding (child) func call from overridden (Parent) object important?
 *
 * You may be thinking why I have created the pointer, I could have simply created the object of child class like this: Dog obj; and 
 * assigned the Dog instance to it. 
 * Well, in this example I have only one child class but when we a big project having several child classes, creating the object of 
 * child class separately is not recommended as it increases the complexity and the code become error prone. 
 *
 */

#include<iostream>
using namespace std;
//Parent class or super class or base class
class Animal{
public:
   //Removing virtual shall call overridden (parent) func instead of overridding (child) func. 
   //This will print "This is a generic function" [PROBLEM]
   virtual void animalSound(){
      cout<<"This is a generic Function";
   }
};
//child class or sub class or derived class
class Dog : public Animal{
public:
   void animalSound(){ 
      cout<<"Woof";
   }
};
int main(){
   Animal *obj;
   obj = new Dog();
   //Add resolve to call parent func
   obj->animalSound();
   return 0;
}
