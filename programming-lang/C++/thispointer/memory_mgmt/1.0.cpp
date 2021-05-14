
//Memory leaks
//Inshort-> Reserve memory unnecessarily/Unusable memory
//How->It happens in application when a programmer allocates the memory from heap for some temporary use and then forgets to delete this 
//after using.
//What->memory leaks are very serious bugs as it can make your application starve for memory i.e. make it very slow in response and
//eventually crashes the application due to lack of memory.

#include <iostream>
void dummy()
{
	//int *p_scalar = new int(5); //allocates an integer, set to 5. (same syntax as constructors)
	//	Since this is a scalar allocation, trying to access arr[1] or to free the memory using delete[] 
	//	would lead to undefined behaviour.
	//int *p_array = new int[5];  //allocates an array of 5 adjacent integers. (undefined values)
	//
	//delete should be used to avoid memory leak. 
	//Also check delete vs delete[] --> new int[] then delete[] used as done in 2d/3d pointer example

    int * ptr = new int(5);
}
int main()
{
    dummy();
    return 0;
}
