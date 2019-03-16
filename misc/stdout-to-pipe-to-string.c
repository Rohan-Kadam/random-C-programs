#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	int status;
	char path[128],path2[128];


	fp = popen("uname -v", "r");
	if (fp == NULL)
	    /* Handle error */;


	while (fgets(path, 128, fp) != NULL)
	{	
		//sprintf(path2 + strlen(path2),path);
		//printf("OUTPUT IS\n%s", path);
	}
	printf("Final String is : %s\n",path);

	status = pclose(fp);
	if (status == -1) 
	{
    	/* Error reported by pclose() */
    	//...
	} 
	else 
	{
    	/* Use macros described under wait() to inspect `status' in order
   	to determine success/failure of command executed by popen() */
   	//...
	}

	return 0;
}
