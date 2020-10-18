#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

typedef struct data
{
 char name[10];
 int age;
}data;

void sig_func(int sig)
{
 write(1, "Caught signal 11\n", sig);
 //Setting alarm here for 5 seconds, won't wake up the thread.
 //Need to call pthread_kill() with corresponding thread id and signal
 //alarm(5);
}

void func(data *p)
{

while(1)
{
 fprintf(stderr, "This is from thread function\n");
 strcpy(p->name,"Rohan");
 p->age=21;
 sleep(10); // Sleep to catch the signal
 //The thread shall wake-up on getting SIGALRM from main thread using pthread_kill.
 //But setting alarm to 5 seconds, just executes the signal handler and DOES NOT wake up the thread.
 fprintf(stderr, "Thread woke up!!\n");
}
}

int main()
{
 pthread_t tid;
 pthread_attr_t attr;
 data d;
 data *ptr = &d;

 signal(SIGALRM,sig_func); // Register signal handler before going multithread
 //Setting alarm for 5 seconds, won't wake up the thread.
 //alarm(5);
 pthread_attr_init(&attr);
 pthread_create(&tid,&attr,(void*)func,ptr);
 sleep(1); // Leave time for initialisation of struct data
 
 //Send signal to thread safely.
 pthread_kill(tid,SIGALRM);

 pthread_join(tid,NULL);
 fprintf(stderr, "Name:%s\n",ptr->name);
 fprintf(stderr, "Age:%d\n",ptr->age);
}
