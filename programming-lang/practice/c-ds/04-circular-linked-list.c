// 
// Data structure => STACK
// --
// -- Operation: creation,traverse,insertbegin,insertmid(by value after, by value before, by position after, by position before),
// 		 insertend, deletebegin, deletemid (same 4 cases as insertmid), deleteend, reverse 
// -- Application:
// 

#include <stdio.h>
#include <stdlib.h>

int total_pos = 0;

struct node{

	int value;
	struct node *next;
};

//malloc in different function: https://stackoverflow.com/questions/2838038/c-programming-malloc-inside-another-function
/*
void creation(struct node **ps){

	*ps = NULL;
	*ps = (struct node *)malloc(sizeof(struct node));
	total_pos = 1;
}
*/
//OR
void * creation(){

	void *ps = NULL;
	ps = (struct node *)malloc(sizeof(struct node));
	total_pos = 1;
	return ps;
}

void traverse(struct node *ps, struct node *pc){

	int count = 0;
	pc = ps;
	while(total_pos != count){
		printf("%d ",(int *)pc->value);
		pc = pc->next;
		count++;
	}
	printf("\n");
}

void insertPos(struct node *ps, struct node *pc, struct node *pt, int pos){
	
	pc = ps;
	int count = 1;

	pt = (struct node *)malloc(sizeof(struct node));
	pt->value = 20;
	pt->next = NULL;
	
	if(pos<=total_pos || pos == total_pos + 1){

		while(total_pos+2 != count){
			if(pos == count){
				
				printf("Add\n");
				pt->next = pc->next;
			       	pc->next = pt;
			}
			count++;
			pc = pc->next;
		}
		total_pos++;
	}
}

int main(){

	struct node *pstart = NULL;
	struct node *pcurr = NULL;
	struct node *ptmp = NULL;

	//creation(&pstart);
	//OR
	pstart = creation();

	pstart->value = 10;
	pstart->next = pstart;

	traverse(pstart,pcurr);
	
	insertPos(pstart,pcurr,ptmp,2);

	traverse(pstart,pcurr);
	return 0;
}

