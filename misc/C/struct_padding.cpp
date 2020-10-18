//
//  
//When a modern computer reads from or writes to a memory address, it will do this in word sized chunks (e.g. 4 byte chunks on a 32-bit system) or larger. Data alignment means putting the data at a memory address equal to some multiple of the word size, which increases the system’s performance due to the way the CPU handles memory. To align the data, it may be necessary to insert some meaningless bytes between the end of the last data structure and the start of the next, which is data structure padding.
//
//What is Padding
//In order to align the data in memory,  one or more empty bytes (addresses) are inserted (or left empty) between memory addresses which are allocated for other structure members while memory allocation. This concept is called structure padding.
//
//Because of this structure padding concept in C, size of the structure is always not same as what we think.
//
//Fast processing due to std mem jumps for processor but size increases


#include <iostream>
 
struct school
{
	double a;
	int b;
	char h;	
	int c;
	char d;	
};
 
int main()
{
	school students;
	
	printf("size of struct %d \n",sizeof(students));
	return 0;
	
}
