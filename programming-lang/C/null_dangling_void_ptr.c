/*
 * NULL Pointer vs Void Pointer
 *
 * NULL pointer and Void pointer are totally different concepts and no need to compare them. 
 * NULL pointer is a value, whereas Void pointer is a type
 * Null pointer is a special reserved value of a pointer and any type of pointer can have reserved value. 
 * Void pointer is a specific pointer type say generic type- void * – a pointer that points to some data location in storage, which doesn’t have any specific type
 *
 * Use of NULL Pointer
 * - Use as a marker -> For example, to indicate a pointer that has not been allocated memory or to check end of a linked list or to check if a tree has any child note or leaf etc.
 * - Malloc failed -> If malloc can’t allocate memory, it returns a null pointer. So, we can check the pointer by comparing with NULL, if a valid memory is allocated. Also, check to free a valid memory etc.  
 *
 * Use of Void Pointer
 * - Point to any storage -> Use typecast when accessing that storage via void pointer. Example: cptr to integer, malloc itself
 *
 * Dangling Pointer is pointer pointing to freed/invalid/garbage address. Its dangerous. Use ASSERT to stop it
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h> 

//Uncomment to disable all assert
//# define NDEBUG

int main(){

	//Declare Pointer
	//=============================================

	int *iPtr = NULL;			//NULL pointer assignment
	void *vPtr;				//Void pointer
	int a=10;

	//vPtr should be garbage value, we can see garbage value on removing =NULL from iPtr declaration line
	printf("vPtr address = %d\n",vPtr);
	printf("iPtr address = %d\n",iPtr);
	
	//Memory allocation
	//==============================================
	//allocate memory for integer
	iPtr = (int *)malloc(sizeof(int));
	if (iPtr == NULL) { 
		printf("Memory not allocated.\n"); 
		perror("Error: ");
		exit(0); 
	} 
	//NOTE: malloc returns void pointer, therefore we use typecast with malloc to store it in respective pointer.


	//Assign value
	//=============================================
	//Do no assign it this way, causes munmap_chunck(invalid pointer)/ Seg Fault
	//iPtr=&a;
	//Adding value directly in allocated memory
	*iPtr=a;
	//Assign address of int a
	//now void pinter is pointing to int data type
	vPtr= &a;


	//Display values stored in them
	//=============================================
	//Check if memory is allocated
	if (iPtr != NULL){
		//print value
		printf("val = %d\n",*iPtr);
	}

	//Retrive back the value of a from void
	//pointer.
	//First we need to type cast void pointer to
	//integer pointer ((int*) vPtr)then access the value
	//by dereferencing it
	int result =  *( (int*) vPtr) ;
	printf("Value of a: %d\n",result);


	//Clean Up
	//=============================================
	//De allocate memory
	free(iPtr); 

	//After freeing memory the iPter is 
	//dangling pointer as store the address but
	//that is invalid now.
	
	//Check if iPtr is NULL, will trigger
	assert(iPtr==NULL);

	//Hence, assing it to NULL to avoid dangling
	iPtr = NULL;
	vPtr = NULL;

	//Check if iPtr is NULL, won't trigger
	//assert(iPtr==NULL);

	return 0;
}

