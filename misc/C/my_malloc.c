#include <stdio.h>

static unsigned char our_memory[1024 * 1024]; //reserve 1 MB for malloc
static size_t next_index = 0;

void *my_malloc(size_t sz){
	void *mem;

	if(sizeof our_memory - next_index < sz)
		return NULL;

	mem = &our_memory[next_index];
	next_index += sz;

	return mem;
}

void free(void *mem){
   //we cheat, and don't free anything.
}

int main(int argc, char **argv){

	printf("Running %s...\n",argv[0]);
	char *ptr;

	//This will cause Seg Fault, coz ptr is not allotted any memory
	//*ptr = 'H';

	ptr = my_malloc(atoi(argv[1]));
	//ptr = my_malloc(2);
	
	ptr[0]='A';
	ptr[1]='B';
	//This line should cause Seg Fault, it will not since ptr is pointing to our_memory in stack which is 1MB. 
	//So OS won't generate Seg Fault as as per OS we are not accessing any unallocated memory
	//ptr[2]='C';
	printf("Ptr[1] = %c\nPtr[2] = %c\n",ptr[0],ptr[1]);

	*ptr = 'X';
	*(ptr+1) = 'Y';
	printf("Ptr[2] = %c\nPtr[1] = %c\n",*ptr,*ptr++);
	//This line will print ptr[2] twice, since printf starts execution from last arg.
	//printf("Ptr[1] = %c\nPtr[2] = %c\n",*ptr,*++ptr);
	
	ptr--;
	printf("Addr Ptr[2] = %d\nAddr Ptr[1] = %d\n",ptr,ptr++);
	//This line will print ptr[2] twice, since printf starts execution from last arg.
	//printf("Addr Ptr[1] = %d\nAddr Ptr[2] = %d\n",ptr,++ptr);

	//This line is not working for some reason
	printf("Size of ptr = \n",sizeof(ptr));

	return 0;
}


