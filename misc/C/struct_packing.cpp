//
//  
//When a modern computer reads from or writes to a memory address, it will do this in word sized chunks (e.g. 4 byte chunks on a 32-bit system) or larger. Data alignment means putting the data at a memory address equal to some multiple of the word size, which increases the system’s performance due to the way the CPU handles memory. To align the data, it may be necessary to insert some meaningless bytes between the end of the last data structure and the start of the next, which is data structure padding.
//
// What is Packing
// Packing, on the other hand prevents compiler from doing padding means remove the unallocated space allocated by structure.
//
// Slow processing due to uneven jumps, but avoid unnecessary enlargement in size



#include <iostream>
 
/*
 * Use __attribute__((__packed__)) or this commented code, both will pack the data structure.
 *
 *
# pragma pack (1)

struct school
{
	double a;
	int b;
	char h;
	int c;
	char d;
};
 
 * 
 */




struct __attribute__((__packed__)) school
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
