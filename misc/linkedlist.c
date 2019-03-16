#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * next ;
}node;

void ins_beg(int);
void ins_end(int);
void display();
struct node * pstart =	NULL;

int main()
{
	int n,val_main;
	static int flag = 0;
	while(1)
	{
		printf("\nMore nodes??\n");
		printf("\n1 == YES\n0 == NO\n");
		scanf("%d",&n);
		if(n)
		{
			if(flag == 0)
			{
				printf("Enter data\n");
				scanf("%d",&val_main);				
				ins_beg(val_main);
				flag ++;
				display();
			}
			else
			{
				printf("Enter data\n");
				scanf("%d",&val_main);				
				ins_end(val_main);
				display();
			}
		}
		else
		{
			break;
		}	
	}
	printf("Entered Linked list\n");
	display();

}


void ins_beg(int val)
{
	struct node * ptemp;
	ptemp = malloc (sizeof(struct node));
	ptemp->data = val;

	ptemp->next = pstart;
	pstart = ptemp;
}

void ins_end(int val)
{
	struct node * ptemp;
	struct node * pcurr;
	ptemp = malloc (sizeof(struct node));
	ptemp->data = val;
	ptemp->next = NULL;
	pcurr = pstart;
	while(pcurr->next)
	{
		pcurr = pcurr->next;
	}
	pcurr->next = ptemp ;
		
}

void display()
{
	struct node * pcurr;
	pcurr = pstart;
	while(pcurr != NULL)
	{
		//printf("\n-----------\n", );
		printf("%d\n",pcurr->data);
		pcurr = pcurr->next;	
	} 
}











