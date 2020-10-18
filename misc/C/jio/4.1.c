#include<iostream>

int main(){

	  int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr; //&arr[0]
    int *ptr2 = arr + 5;
//    printf("%d %d\n\n",*(arr+5),arr[5]);
//    printf("%d\n\n",arr[1]+5);
 	printf("%lu %lu\n",ptr2,ptr1);
    printf ("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
 	printf("%lu %lu\n",(char*)ptr2,(char*)ptr1);
    printf ("(char*)ptr2 - (char*) ptr1 = %d", (char*)ptr2 - (char*)ptr1);


	return 0;
}
