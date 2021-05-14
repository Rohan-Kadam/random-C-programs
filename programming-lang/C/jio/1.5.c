#include <stdio.h>
#include <stdlib.h>

#define ADD(X, Y) (X++);\
	if(X++<Y){\
	printf("qwerty %d\n",X);\
	}
#define SUBTRACT(X, Y) (X - Y)
#define MULTIPLY(X, Y) (X * Y)
#define DIVIDE(X, Y) (X/Y)

int main()
{
int a,b; /* variable declaration and initialization */

int addition,subtraction,mul,division;

addition = subtraction = mul = division = 0;

/* Reading Input values */

printf("Enter two numbers:\n");
scanf("%d",&a); 
scanf("%d",&b);

/* Compute */

addition = ADD(a, b);
subtraction = SUBTRACT(a, b);
mul = MULTIPLY(a, b);
division = DIVIDE(a, b);

/* printing outputs */

printf("\n");
printf("_________________________\n");
printf("Addition = %d\n",addition);
printf("Subtraction = %d\n",subtraction);
printf("Multiplication = %d\n",mul);
printf("Division = %d\n",division);

return 0;
}
