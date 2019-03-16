// C program to implement one side of FIFO 
// This side writes first, then reads 

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <errno.h>
  
int main() 
{ 

    int fd, ret = 0, len = 0;
	char inputChar; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  	
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
	ret = mkfifo(myfifo, 0666); 
  	if(ret == -1)
	{
		printf("Return value = %d, %s\n",ret,strerror(errno));
	}
    char arr1[80], arr2[80]; 
	printf("Entering while 1\n");    

	while (1) 
    { 
        // Open FIFO for write only 
		printf("Opening fifo\n");
		fd = open(myfifo, O_WRONLY); 
		printf("Descriptor = %d\n",fd);  
        // Take an input arr2ing from user. 
        // 80 is maximum length 
        //fgets(arr2,80, stdin);
		printf("Enter input character\n"); 
        while ( (inputChar = fgetc( stdin ) ) != '\r\n' )
		{
			printf("%c\n",inputChar);
			arr2[len++]=inputChar;
		}
		arr2[len]='\0';
		printf("Wrting input to pipe\n");
		// Write the input arr2ing on FIFO 
        // and close it 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open(myfifo, O_RDONLY); 
  
        // Read from FIFO 
        read(fd, arr1, sizeof(arr1)); 
  
        // Print the read message 
        printf("User2: %s\n", arr1); 
        close(fd); 
    }
 
    return 0; 
} 

