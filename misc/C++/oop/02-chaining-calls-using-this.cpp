/*
 * Another example of using this pointer is to return the reference of current object so that you can chain function calls, 
 * this way you can call all the functions for the current object in one go. 
 *
 * Another important point to note in this program is that I have incremented the value of object’s num in the second function 
 * and you can see in the output that it actually incremented the value that we have set in the first function call. This shows
 * that the chaining is sequential and the changes made to the object’s data members retains for further chaining calls.
 *
 */



#include <iostream>
using namespace std;
class Demo {
private:
  int num;
  char ch;
public:
  Demo &setNum(int num){
    this->num =num;
    return *this;
  }
  Demo &setCh(char ch){
    this->num++;
    this->ch =ch;
    return *this;
  }
  void displayMyValues(){
    cout<<num<<endl;
    cout<<ch;
  }
};
int main(){
  Demo obj;
  //Chaining calls (setCh is called second after setNum sets num and returns object address)
  obj.setNum(100).setCh('A');
  obj.displayMyValues();
  return 0;
}
