#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){

	//Not used
	int *arrf = (int *) malloc(1);
	free(arrf);

	// calloc intializes allocated heap memory with zeros	
	int *arr = (int *) calloc(1,sizeof(int));
	
	int count=1, p=3, n=10;
	int answer;
	int *pElem;
	pElem = arr;
	printf("arr_index_addr = %0x",arr);
	
	for(int i=1; i<=n; i++){
		printf("\n\nNumber=%d. Size of dynamic array = %d\n",i,malloc_usable_size(arr));
		
		if(n%i == 0){
			printf("Filtered fact = %d is stored at index = %d ****\n",i, count);
			*(arr+count) = i;
			//realloc = free old + malloc new; shouldn't be used this way??
			arr = (int*) realloc(arr,count);
			//arr = (long*) realloc(arr,count*sizeof(long));
			++count;
		}
		printf("last_fact = %d last_filtered_fact = %d, arr_index = %d, last_arr_index_addr = %0x\n",i,*(arr+count),count,arr+count-1);

	}

	printf("*************************************\n");
	//pElem = arr;
	printf("\n\n%x %x\n\n",pElem,arr);
	answer = *(pElem+p);
	printf("\n===>%d\n\n",answer);

	for(int i=1; i<count ; i++){
		printf("%d ",*(pElem+i));
	}
	printf("\n");

	free(arr);
/*	
	answer = *(pElem+0);
	printf("\n===>%d\n\n",answer);

	answer = *(pElem+1);
	printf("\n===>%d\n\n",answer);

	answer = *(pElem+2);
	printf("\n===>%d\n\n",answer);
*/


	return 0;
}
