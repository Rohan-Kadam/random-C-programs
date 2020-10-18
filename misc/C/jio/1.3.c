#include <stdio.h>

// Define macro to check maximum and minimum
#define MAX(x, y) \
	x++	
/*
	(x > y ? 0 : y++) \
*/
/*
	if (x++ < y) \
        { y\
        printf("GeeksQuiz\n"); \
        continue; \
        }                  
*/

#define MIN(x, y) (x < y ? x : y)

int main()
{
    int num1, num2;
	if(num1++<num2){
		printf("1");
	}
	else{
		printf("0");
	}
    // Input numbers from user
    printf("Enter any two number to check max and min: ");
    scanf("%d%d", &num1, &num2);

    printf("MAX(%d, %d) = %d\n", num1, num2, MAX(num1, num2));
    printf("MIN(%d, %d) = %d\n", num1, num2, MIN(num1, num2));

    return 0;
}
