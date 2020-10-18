#include<stdio.h>

int main(){

   char *x,y;
    x=NULL;
    y='A';
    x=&y;
    printf("%c %lu %lu\n",*x,x,&y);
    return 0;
}
