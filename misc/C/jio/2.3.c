#include <iostream>

int main(){

int* ptr1=new int[10];
int* ptr2=ptr1+1;
int* ptr3=ptr1;
ptr1++;

delete[] ptr3;

return 0;
}
