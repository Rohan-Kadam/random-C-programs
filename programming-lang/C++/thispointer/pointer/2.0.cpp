// - ref always initialize while declaration
// - ref to NULL, no no
// - ref to ref, nope
// - ref increment or decrement, not possible
// - ref addr = pointing var addr; ptr addr != pointing var addr (ptr value = pointing var addr)
// - no leakage problem, mostly due to above restrictions (no ref inc/dec, no ref to ref)

#include<iostream>

int main(){
int abc = 7;
int xyz = 10;
int & ref = abc; // Correct
int & ref2 = ref; // Not ref 2 ref, its ref to same place basically
//int & ref3 = &ref2; //ref 2 ref. Gives error: cannot bind rvalue ‘(int)(& ref2)’ to ‘int&’
//int & y; // Wrong , won't compile
int * ptr ; // Correct
ptr = NULL; // Correct
//ref = NULL; // Wrong Won't compile
ref = ref2; 
//ref = &ref2; //ref 2 ref
//&(ref+2) = 12; //ref increment or decrement
}
