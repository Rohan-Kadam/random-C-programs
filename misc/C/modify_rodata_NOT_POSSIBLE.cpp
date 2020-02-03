#include<stdio.h>

int main()
{
	
/*	
	char a[20]={'S','t','r','i','n','g'};		//1 element accessible
	printf("%s\n",a);
	printf("%c\n",a[1]);
	a[1]='T';
	printf("%c\n",a[1]);
	printf("%s\n",a);
*/


/*
	char * a = "String literal";		//Cannot change        
						//USE const to send it to rodata sec {SAFE}  (//rodata string literals)
	printf("%s\n",a);			// char * a used       since char a can store only one byte 'S'
	a = "STring literal";
	printf("%s\n",a);
*/

/*
	char a = 'T';				//not a string,its char and char can be accessed (i.e. changed)
	printf("%c\n",a);
	a = 't';
	printf("%c\n",a);
*/

const int a[5]={10,20,30,40,50};		//rodata (argc,argv)
int i;

	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");



/*
	a[1]=100;				//writing on rodata directly  [ACCESS DENIED]


	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
*/


int * ptr = a;										
* (ptr+1) = 100;				//writing on rodata through pointer		[FAILED]

	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

//final conclusion		-------->		rodata can never be varied neither directly nor using pointers.

return 0;


}
