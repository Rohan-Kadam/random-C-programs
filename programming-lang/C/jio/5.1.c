#include<iostream>

int main(){

	char arr[10]={'H','e'};
char *str="Hello";
str = arr;
    str++;
    *str = 'x';
    printf("%s %c\n",str, arr[1]);

	return 0;
}
