//
// Enum vs Macro
// #define Working 0 
// #define Failed 1 
// #define Freezed 2 
//
// There are multiple advantages of using enum over macro when many related named constants have integral values.
// a) Enums follow scope rules.
// b) Enum variables are automatically assigned values. Following is simpler
// c) Code readablity


#include <stdio.h>
enum State {WORKING = 0, FAILED, FREEZED};
enum State currState = 2;

enum State FindState() {
    return currState;
}

int main() {
   (FindState() == WORKING)? printf("WORKING"): printf("NOT WORKING");
   return 0;
}

