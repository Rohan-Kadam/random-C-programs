
#include <iostream>
using namespace std;
class XYZ {
private:
   int num=100;
   char ch='Z';
public:
   //Without friend, outside func named disp cannot access XYZ's private vars
   friend void disp(XYZ obj);
};
//Global Function
void disp(XYZ obj){
   cout<<obj.num<<endl;
   cout<<obj.ch<<endl;
}
int main() {
   XYZ obj;
   disp(obj);
   return 0;
}
