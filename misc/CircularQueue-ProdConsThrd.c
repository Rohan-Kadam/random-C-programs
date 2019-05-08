#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
#define max 5
char queue[max][80], data[80]= "hello";
pthread_mutex_t lock; 

//Determine the filled slots in queue
int qCounter;

//Queue Pointers
int front, rear, reply;
front = 0; rear = 0;

  
//exponential interval time for poisson
double ran_expo(double lambda)
{
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return -log(1- u) / lambda;
}

int insq(char queue[max][80],int *front, int *rear, char data[80])
{
	int f,r;
	
	//For Linear Queue
	//if(*rear == max - 1)

	//For Circular Queue
	if(*rear == (*front -1))
		return(-1);
	else
	{
      		if(*rear == max-1)
		{
			*rear = 0;
        	}
		else
		{
			*rear= *rear+1;					
		}		
		strcpy(queue[*rear],data);
		++qCounter;
		//printf("WRITER: Queue Filled Slots after writing= %d rear =%d\n",qCounter,*rear);        	
		return(1);
   	}
}

int delq(char queue[max][80],int *front, int *rear, char data[80])
{
        if(*front==*rear)
        	return(-1);
        else
        {
        	--qCounter;
		if(*front == max-1)
		{
			*front = 0;
		}
		else
		{
			(*front)++;
		}		
		//printf("READER: Queue Filled Slots after reading= %d front = %d rear =%d\n",qCounter,*front,*rear);
        			
		//        printf("check: %s", *front);
        	strcpy(data,queue[*front]);
        	return(data);
        }
}

void *del(void *myvar);
void *inst(void *myvar);

// 3 threads running in main

int main (int argc, char **argv)

{ 

	char queue[max][80]; // data[80]= "hello";
	//  int front, rear, reply;
	//  front = rear = -1; 


	pthread_t thread1;
    	pthread_t thread2;
	//   pthread_t thread3;
   	int ref1, ref2, ref3;
    
	if (pthread_mutex_init(&lock, NULL) != 0) 
    	{ 
        	printf("\n mutex init has failed\n"); 
        	return 1; 
    	} 
  
  	ref1 = pthread_create(&thread1,NULL,inst,NULL);     
 	ref2 = pthread_create(&thread2,NULL,del,NULL);
  	//   ref3 = pthread_create(&thread3,NULL, myfunc3,NULL);
 
  	printf("Main function after pthread_create\n");

  	pthread_join(thread1, NULL);
  	pthread_join(thread2, NULL);
	//  pthread_join(thread3, NULL);

	//  pthread_exit(NULL);

  	printf(" 1nd thread ref1 = %d\n", ref1);
	//  printf(" 3rd thread ref3 = %d\n", ref3);
  	printf(" 2nd thread ref2 = %d\n", ref2);

  	pthread_mutex_destroy(&lock); 
  
  	return 0;
}


void *inst(void *myvar)
{
 	// char queue[max][80], data[80]= "hello"; 
  	//pthread_mutex_lock(&lock);

	//   pthread_mutex_lock(&lock); 

  	double lambda = 5;
  	int no_of_users=0;
  	double past_time,user_arrival_time; 
 
while(1) 
{
	past_time = time(0);
        user_arrival_time = ran_expo(lambda); // time arrival duration between two consecutive user arrivals
        printf("WRITER: Poisson Delay = %lf\n",user_arrival_time);

	printf("WRITER: Poisson Delay Sleep -_-\n");
	//Poisson Delay	
	while(1)
   	{
        	if(time(0)-past_time >= user_arrival_time)      // run the while loop until system has run for (user_arrival_time) seconds, i.e, run the timer for that many seconds
                	break;                                  // break the while loop when (user_arrival_time) seconds has been passed
   	}
	printf("WRITER: Poisson Delay Wakeup 0_0\n");
	//  printf("\nEnter string :");
	//  scanf("%s",data);
	pthread_mutex_lock(&lock);
	printf("WRITER: Before Writing to queue, Queue Counter = %d front = %d rear =%d\n",qCounter,front,rear);
	reply=insq(queue,&front,&rear,data);
	printf("WRITER: After Writing to queue, Queue Counter = %d front = %d rear =%d\n",qCounter,front,rear);
	pthread_mutex_unlock(&lock);
  	if(reply == -1)
	{ 
		printf("WRITER: Queue is Full GOTO LONG SLEEP\n");
 		usleep(1000000);
		//rear = front;		
		printf("WRITER: WAKEUP FROM LONG SLEEP\n");
 		//break;
	}
  	else
     		printf("WRITER:'%s' is inserted in queue.\n================> IN\n\n",data);
 	} 

 	//pthread_mutex_unlock(&lock); 
 	return NULL;
}

void *del(void *myvar)
{

	// delete
 	//  char queue[max][80];
	/*  char *msg;
  	msg =  ( char *) myvar; // to convert the void pointer to a char pointer for reading the message
 	pthread_mutex_lock(&lock); 

  	printf("%s\n ",msg );

	*/
  	//pthread_mutex_lock(&lock); 
 
	sleep(1);	

	while(1) 
 	{
		pthread_mutex_lock(&lock); 
		//rear = qCounter;
		printf("READER: Before Reading from queue, Queue Counter = %d front = %d rear =%d\n",qCounter,front,rear);   		
		reply = delq(queue, &front, &rear, data);
		printf("READER: After Reading from queue, Queue Counter = %d front = %d rear =%d\n",qCounter,front,rear);   		
		pthread_mutex_unlock(&lock);
   	
		if( reply == -1 )
  		{    
    
			printf("READER: Queue is Empty GOTO LONG SLEEP\n");
    			usleep(2000000);
			//front = 0;
			printf("READER: WAKEUP FROM LONG SLEEP\n");
			//rear = qCounter;
			//break;
  		}
   		else
		{
        		printf("READER: Deleted String from Queue is : %s\n================> OUT\n\n", reply);
    			char dataToBeWritten[50];
 			strcpy(dataToBeWritten,reply);

 			// Open the existing file hello.c using fopen()
			// in write mode using "w" attribute

 			FILE *filePointer;
 
 			filePointer = fopen ("mine.c" , "w");

 			// check if this file pointer is null
 			// which maybe if the file does not exist

 			if ( filePointer == NULL )
 			{
    				printf ("READER: failed to open");
 			}
 			else
  			{

    			printf("READER: file is opened.\n");
 			// write the dataToBeWritten into the file
    				if ( strlen ( dataToBeWritten ) > 0 )
				{

  				// Write the data into the file

   				fputs(dataToBeWritten, filePointer );
   				fputs("\n",filePointer);

   				}
 				// closing the file using fclose()

  				fclose(filePointer);
	
	  			printf ("READER: Data successfully written in the file \n");
  				printf ("READER: the file in now closed\n\n");

  			}
    
		}
	}//while 1 ends here

   //pthread_mutex_unlock(&lock); 
   return NULL;
}


