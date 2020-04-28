#include <stdio.h>

//Minus 1 is necessary coz we call 0 bit as 1st first
//Confusion is cause when we think arg bit can be 0. No it can't be coz we are not saying the bit number here. 
//Here we say bit first,second,...., so no 0th bit
#define SetBit(number,bit) 	(number|=(1<<bit-1))		 
#define ClearBit(number,bit) 	(number&=(~(1<<bit-1)))
#define Toggle(number,bit) 	(number ^ (1<<bit-1))

//Max number that can be handled by this func is 63
void bin(unsigned n)
{
    unsigned i;
    for (i = (1 << 31) ; i > 0; i = (i>>1))
        if(n & i)
			printf("1");
		else
			printf("0");
}

int main(){

	int i=7;
	printf("\n Binary of 7 is      : ");
	bin(i);
	
	i=SetBit(i,4);	
	printf("\n\n Set 4th bit of 7    : ");
	bin(i);
	
	i=ClearBit(i,4);	
	printf("\n\n Clear 4th bit of 7  : ");
	bin(i);
 
	i=Toggle(i,1);	
	printf("\n\n Toggle 1st bit of 7 : ");
	bin(i);

	printf("\n");
	return 0;
}
