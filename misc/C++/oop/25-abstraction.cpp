/*
 *
 * Abstraction is a feature where you show only relevant details to the user and hide irrelevant details.
 *
 * The major advantage of using this feature is that when the code evolves and you need to make some adjustments in the code then
 * you only need to modify the high level class where you have declared the members as private. 
 * Since none class is accessing these data members directly, you do not need to change the low level(user level) class code.
 *
 */

#include <iostream>
using namespace std;
class AbstractionExample{
private:
   /* By making these data members private, I have
    * hidden them from outside world.
    * These data members are not accessible outside
    * the class. The only way to set and get their
    * values is through the public functions.
    */
   int num;
   char ch;

public:
   void setMyValues(int n, char c) {
      num = n; ch = c;
   }
   void getMyValues() {
      cout<<"Numbers is: "<<num<< endl;
      cout<<"Char is: "<<ch<<endl;
   }
};
int main(){
   AbstractionExample obj;
   obj.setMyValues(100, 'X');
   obj.getMyValues();
   return 0;
}
