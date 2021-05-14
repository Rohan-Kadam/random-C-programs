#include <stdio.h>
 
// function prototype
int subtract(int x, int y);
 
// function implementation
int subtract(int x, int y) {
	return x - y;
}
 
// calling from main
int main() {

	//Return type is int	
	int (*subtractPtr)(int, int) = subtract;

	//We will be passing args as well
	int y = (*subtractPtr)(10, 2);
	printf("Subtract gives: %d\n", y);

	//Executing the function pointer as a regular function.
	int z = subtractPtr(10, 2);
	printf("Subtract gives: %d\n", z);
}
