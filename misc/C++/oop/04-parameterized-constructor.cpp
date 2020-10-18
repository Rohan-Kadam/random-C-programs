#include <iostream>
using namespace std;
class Add{
public:
   //Parameterized constructor
   Add(int num1, int num2) {
     cout<<(num1+num2)<<endl;
   }
};
int main(void){
   /* One way of creating object. Also
    * known as implicit call to the
    * constructor
    */
   Add obj1(10, 20);
   /* Another way of creating object. This
    * is known as explicit calling the
    * constructor.
    */
   Add obj2 = Add(50, 60);
   return 0;
}
