#include <iostream>

int main(){

int* ptr1=new int[10];
int* ptr2=ptr1+1;
* ptr2 = 99;
printf("%d and %d %d %d\n",ptr1,ptr2,*ptr2,*(ptr1+1));
delete[] ptr1;

return 0;
}
