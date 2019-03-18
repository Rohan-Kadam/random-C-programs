#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

typedef struct data
{
 char name[10];
 int age;
}data;

void sig_func(int sig)
{
 //printf("caught signal %d\n",sig);
 write(1, "Caught signal 11\n", 17);
 //signal(SIGALRM,sig_func);
 //alarm(5);
}

void func(data *p)
{

while(1)
{
 fprintf(stderr, "This is from thread function\n");
 strcpy(p->name,"Rohan");
 p->age=21;
 //while(1);
 signal(SIGALRM,sig_func);
 sleep(20); // Sleep to catch the signal
}
}

int main()
{
 pthread_t tid;
 pthread_attr_t attr;
 data d;
 data *ptr = &d;

 signal(SIGALRM,sig_func); // Register signal handler before going multithread
 alarm(5);
 pthread_attr_init(&attr);
 pthread_create(&tid,&attr,(void*)func,ptr);
 sleep(2); // Leave time for initialisation
 pthread_kill(tid,SIGALRM);

 pthread_join(tid,NULL);
 fprintf(stderr, "Name:%s\n",ptr->name);
 fprintf(stderr, "Age:%d\n",ptr->age);
}
