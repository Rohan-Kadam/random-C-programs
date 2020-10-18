#include <stdio.h>

// function prototype
void sayHello();
 
// function implementation
void sayHello() {
	printf("hello world\n");
}
 
// calling from main
int main() {
	sayHello();

	//Here function name i.e. label is the address, and we are pointing our funcptr to it.
	//Return type of sayHello is void, thus funcptr ret type is also void
	void (*sayHelloPtr)() = sayHello;
	//Its important to have *sayhelloPtr in parenthesis, else it is void ptr instead of pointer to void function
	//Here we are passing no argument, otherwise we can pass args in ()
	(*sayHelloPtr)();

}
