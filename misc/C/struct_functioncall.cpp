#include<stdio.h>


typedef struct id{
	const char * name;
	int roll_no;
	int age;	
}ID;

//void display (ID * int);



void display_ptr(ID * i)
{
	i->age++;	
	printf("%d\n",i->age);
	
}

void display(ID i)
{
	i.age++;	
	printf("%d\n",i.age);
	
}


int main()
{
	ID a = {"Rohan" , 84, 21};
	display(a);
	//display_ptr(&a);	
	printf("%d\n",a.age);
	
	return 0;
}
