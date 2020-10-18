/*
 * Explaination
 *
 * To use the sizeof(), we can take the value using a variable x, using &x, it will print the address of it. 
 * Now if we increase the value of &x then it may increase in different way. 
 * If only one byte is increased, that means it is character, if the increased value is 4, then it is int or float and so on. 
 * So by taking the difference between &x + 1 and &x, we can get the size of x.
 *
 * Here we will use macro as the datatype is not defined in the function. 
 * And one more thing, we are casting using (char*) so, it will tell us that how many character type data can be placed in that place. 
 * As the character takes one byte of data.
 *
 * */

#include <stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

int main(void) {

	int x = 10;
	char y = 'f';
	double z = 254748.23;
	float f = 3.14;

	printf("size of x: %d\n", my_sizeof(x));
	printf("size of y: %d\n", my_sizeof(y));
	printf("size of z: %d\n", my_sizeof(z));
	printf("size of f: %d\n", my_sizeof(f));

	return 0;
}
