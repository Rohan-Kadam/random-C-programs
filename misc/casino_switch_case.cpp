#include<stdio.h>

int main()
{
	int flag = 0,count = 0;
	while(flag == 0)
	{
		int n = 0;
		printf("Enter 1 for HIGH card\nK,Q,J,10\nEnter 2 for LOW card\n3,4,5,6\n");
		scanf("%d",&n);
		switch(n) 
		{
			case 1:{
				count--;
				break;
			}
			case 2:{
				count++;
				break;
			}
			default:{
				printf("NO Changes\n");
				break;
			}
		}
		printf("More cards??\n1 = yes\n2 = no\n");
		scanf("%d",&n);
		if(n==1)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
		//clrscr();
		int x;
    	for ( x = 0; x < 10	; x++ ) 
    	{
        	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    	}
	}
		
	printf("\n\nFinal Count=%d\n",count);

	return 0;
}
