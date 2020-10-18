#include<linux/in.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>



int main(int argc,char *argv[])
{
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;

	if(argc != 3)
	{
		perror("Too few arguments\n");
		exit(1);
	}
	//===========================================Socket
	int csd,ret;
	char *ptr;
	csd = socket(AF_INET,SOCK_DGRAM,0);
	if(csd<0)
	{
		perror("Socket init failed\n");
		exit(1);
	}
	//===========================================Bind
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(5000);
	caddr.sin_addr.s_addr = inet_addr("0.0.0.0");//INADDR_ANY;
	bzero(&caddr.sin_zero,sizeof(caddr.sin_zero));
	ret = bind(csd,(struct sockaddr *)&caddr,sizeof(caddr));
	if(ret<0)
        {
                perror("Bind failed\n");
                exit(2);
        }


	//===========================================Connect
	/*strtoul(argv[2], &ptr, 10);
	
*/
	socklen_t slen = sizeof(saddr);
	char str[100];
	char buf[128];
        
	//===========================================Recv
	while(1)
	{
	        int nbytes = recvfrom(csd, buf, 128,0,(struct sockaddr*)&saddr,&slen);
		printf("\nData received from Server----------------------------client\n");
	        if(nbytes < 0)
	        {
	                perror("Recv failed");
	                exit(6);
	        }	
		//buf1 = buf;
		write(1,buf,nbytes);	
		if(strncmp("exit",buf,4)==0)
		{
			printf("Exiting client recv\n");
			break;
		}
	}


}
