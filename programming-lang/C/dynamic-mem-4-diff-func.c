// 
// Data structure => STACK
// --
// -- Operation: creation,traverse,insertbegin,insertmid(by value after, by value before, by position after, by position before),
// 		 insertend, deletebegin, deletemid (same 4 cases as insertmid), deleteend, reverse 
// -- Application:
// 

#include <stdio.h>
#include <stdlib.h>

struct node{

	int value;
	struct node *next;
};

//malloc in different function: https://stackoverflow.com/questions/2838038/c-programming-malloc-inside-another-function
/*
void creation(struct node **ps){

	*ps = NULL;
	*ps = (struct node *)malloc(sizeof(struct node));
}
*/
//OR
void * creation(){

	void *ps = NULL;
	ps = (struct node *)malloc(sizeof(struct node));
	return ps;
}

void traverse(struct node *ps, struct node *pc){

	pc = ps;
	while(pc != NULL){
		printf("%d ",(int *)pc->value);
		pc = pc->next;
	}
	printf("\n");
}

int main(){

	struct node *pstart = NULL;
	struct node *pcurr = NULL;
	struct node *ptmp = NULL;

	//creation(&pstart);
	//OR
	pstart = creation();

	pstart->value = 10;
	pstart->next = NULL;

	traverse(pstart,pcurr);
	

	return 0;
}

