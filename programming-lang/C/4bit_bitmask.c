#include <stdio.h>

int main () 
{
	char storage,no = 39;
	char tmp1,tmp2;	
	storage = no%10;
	tmp1 = storage & 0x0F;
	tmp2 = ((no/10)<<4) & 0xF0;

	//General statement:
	//value = (value & ~mask) | (newvalue & mask)
	
	storage = (storage & 0x0F) | (((no/10)<<4) & 0xF0);

	printf("char storage = %d %d %d\n",storage,tmp1,tmp2);
	return 0;
}
