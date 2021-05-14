#include <iostream>

int main(){

int* ptr1=new int[10];
int* ptr2=ptr1+1;
delete[] ptr2;

return 0;
}
