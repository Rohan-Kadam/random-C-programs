#include <stdio.h>
#include <string.h>

//#define BUFSIZ 1000

int main()
{
        FILE *stdout_pipe;
	int status;
	char resp[10000]={};
	char output[10000]={};
	char buf[1000];
	char cmd[25]="-p";
	char final_cmd[25]="uname ";
	
	strcat(final_cmd,cmd);
	//stdout_pipe = popen("pstree", "r");
        stdout_pipe = popen(final_cmd , "r");
	if (stdout_pipe == NULL)
        {
        	/* Handle error */;
        }
        
	while (fgets(resp, 10000, stdout_pipe) != NULL)
        {
		//this line prints all lines
        	printf("%s", resp);
		
		//Buffering string "resp" content in a bigger string "output"
		strcat(&output[0],&resp[0]);
		//Reason for not directly putting data from pipe to resp
		//Coz fgets only stores last line from pipe, thus unable to capture multi-line output 
        }

        //this line captures only last line     
        printf("%s\n",output);


	//ALTERNATE SOLUTION 
	/*
	//Using fread instead of fgets
	//Since fread used to read data and fgets used to read single line
	
	//Read one byte at a time, up to BUFSIZ - 1 bytes, the last byte will be used for null termination. 
	//size_t byte_count = fread(buf, 1000 - 1, 1, stdout_pipe);
	
	//Apply null termination so that the read bytes can be treated as a string. 
	//buf[byte_count] = 0;
    	
	//printf("%s\n", buf);
	*/

        status = pclose(stdout_pipe);
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
