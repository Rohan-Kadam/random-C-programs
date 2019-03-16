#include<stdio.h>

typedef struct id{
	const char * name;
	int roll_no;
	int age;	
}ID;



int main()
{
	ID a = {"Rohan" , 84, 21};
	printf("%d\n",a.roll_no);
	
	a.roll_no=100;
	a.name="Ro1";
	printf("%d\n",a.roll_no);
	printf("%s\n",a.name);	
	
	return 0;
}
