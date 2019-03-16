#include<stdio.h>
#include<string.h>

int main()
{
    char *str1[2];
    str1[0]=(char *)malloc(10);
    str1[1]=(char *)malloc(10);
    int i = 10;
    float j = 20.01f;
    sprintf(str1[0],"%d",i);
    sprintf(str1[1],"%f",j);
    
    printf("\n%s%s\n",str1[0],str1[1]);
    free(str1[0]);
    free(str1[1]);
    return 0;
}