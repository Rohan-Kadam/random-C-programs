#include <stdio.h>

typedef struct node{
        int arr[3];
        int top;
}node;

int MAX = 3;

void push(struct node *,int);
void pop(struct node * );
void display(struct node *);

void push(struct node * p,int val)
{
    if (p->top == MAX - 1)
    {
        printf("Overflow\n");
        //return ;
    }
    p->arr[++p->top] = val;              //val pushed
    //return ;
}


void display(struct node * p)
{
    int i = 0;
    for(i=p->top; i >= 0; i--)
    {
        printf("%d\n",p->arr[i]);
        //printf("\n");
    }
    
}


void pop(struct node * p)
{
    if(p->top == -1)
    {
        printf("Underflow\n");
    //    return ;
    }
    printf("Val Popped%d\n",p->arr[p->top]);         //val inserted    
    --(p->top);          
        
}



int main()
{
    node s;
    s.top = -1;
    int val_main;
    printf("Enter Value\n");
    scanf("%d",&val_main);
    push(&s,val_main);
    
    printf("Enter Value\n");
    scanf("%d",&val_main);
    push(&s,val_main);
    
    display(&s);
    
    pop(&s);
    
    display(&s);
    
    return 0;
}




