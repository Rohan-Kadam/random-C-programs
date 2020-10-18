#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <linux/in.h>
#include <sys/socket.h>
#include <stdio.h>

//Global entities used by udp socket
struct sockaddr_in saddr;
struct sockaddr_in caddr;
socklen_t clen;
int ssd;



int socket_init()
{
        //===========================================socket
        int sport,ret;
        ssd = socket(AF_INET,SOCK_DGRAM,0);
        if(ssd<0)
        {
                perror("Socket init failed\n");
                exit(1);
        }
        //==========================================bind
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(0);
        saddr.sin_addr.s_addr = INADDR_ANY;
        bzero(&saddr.sin_zero,sizeof(saddr.sin_zero));

        ret = bind(ssd,(struct sockaddr *)&saddr,sizeof(saddr));
        if(ret<0)
        {
                perror("Bind failed\n");
                exit(2);
        }
        caddr.sin_family = AF_INET;
        caddr.sin_port = htons(1500);//*ptr);
        caddr.sin_addr.s_addr = inet_addr("127.0.0.1");//(argv[1]);
        bzero(&caddr.sin_zero,sizeof(caddr.sin_zero));

        clen = sizeof(caddr);

        return 0;
}

int main()
{
	FILE *fp;
	int status,ret;
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

	 //Adding UDP Socket code here
                ret = socket_init();
                if(ret != 0)
                {
                        perror("UDP Socket Initialization Failed\n");
                        exit(3);
                }

                //char str[128]="Hello";

                //==========================================Send data to controller over UDP
                //while(1)
                {
                        //printf("\nEnter data to sent:------------server  ");
                        //scanf("%[^\n]s",str);
                        //gets(str);
                        int nbytes = sendto(ssd, path, strlen(path), 0,(struct sockaddr*)&caddr,clen);
                        //str[nbytes]='\0';     
                        if(nbytes < 0)
                        {
                                perror("Send failed");
                                exit(4);
                        }
                        //if(strncmp("exit",str,4)==0)
                        //{
                        //        printf("Exiting server send\n");
                        //        break;
                        //}
                }


	return 0;
}
