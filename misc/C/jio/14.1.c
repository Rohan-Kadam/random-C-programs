#include<iostream>
int main()
{

int* ptr=(int*) malloc(10*sizeof(int));
printf("%lu\n",ptr);
ptr=NULL;
printf("%lu\n",ptr);
free(ptr);

printf("%lu\n",ptr);
 


}

