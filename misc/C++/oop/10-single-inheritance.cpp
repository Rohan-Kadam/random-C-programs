/*
 *
 * B inherits A
 *
 */

#include <iostream>
using namespace std;
class A {
public:
  A(){
     cout<<"Constructor of A class"<<endl;
  }
};
class B: public A {
public:
  B(){
     cout<<"Constructor of B class"<<endl;
  }
};
int main() {
   //Creating object of class B
   B obj;
   cout<<"B --> A"<<endl;
   return 0;
}
