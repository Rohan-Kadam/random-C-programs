#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){

	long *arr = (long *) calloc(1,sizeof(long));
	
	long count=1, p=3, n=10;
	long answer;
	long *pElem;
	pElem = arr;
	printf("arr_index_addr = %0x",arr);
	
	for(long i=1; i<=n; i++){
		printf("\n\nNumber=%d. Size of dynamic array = %d\n",i,malloc_usable_size(arr));
		
		if(1){
		//if(n%i == 0){
			printf("Filtered fact = %d is stored at index = %d ****\n",i, count);
			*(arr+count) = i;
			arr = (int*) realloc(arr,count);
			//arr = (long*) realloc(arr,count*sizeof(long));
			++count;
		}
		//printf("last_fact = %d last_filtered_fact = %d, arr_index = %d, last_arr_index_addr = %0x\n",i,*(arr+count),count,arr+count-1);

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
