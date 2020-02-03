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
 //printf("caught signal %d\n",sig);
 write(1, "Caught signal 11\n", 17);
 //signal(SIGSEGV,sig_func);
}

void func(data *p)
{


 fprintf(stderr, "This is from thread function\n");
 strcpy(p->name,"Rohan");
 p->age=21;
 //while(1);
 sleep(10); // Sleep to catch the signal

}

int main()
{
 pthread_t tid;
 pthread_attr_t attr;
 data d;
 data *ptr = &d;

 signal(SIGSEGV,sig_func); // Register signal handler before going multithread
 pthread_attr_init(&attr);
 pthread_create(&tid,&attr,(void*)func,ptr);
 sleep(2); // Leave time for initialisation
 pthread_kill(tid,SIGSEGV);

 pthread_join(tid,NULL);
 fprintf(stderr, "Name:%s\n",ptr->name);
 fprintf(stderr, "Age:%d\n",ptr->age);
}
