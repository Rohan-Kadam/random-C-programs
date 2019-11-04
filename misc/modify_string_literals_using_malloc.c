#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *str1[2]={"123","456"};
    char *str2[2]={"abc","xyz"};

    str1[0]=(char *)malloc(1);
    str1[1]=(char *)malloc(1);
    int i = 10;
    float j = 20.01f;
    sprintf(str1[0],"%d",i);
    sprintf(str1[1],"%f",j);

    //Enabling following line shall give Run-time ERROR: Segmentation fault.
    //>> Since we are modifing string literal i.e. ro-data
    //>> Hence a malloc is used if you need to modify char * later. 
    //>> Which stores string in heap region instead of ro-data, making modifications possible.
    //
    //sprintf(str2[0],"%d",i);
    
    printf("String 1 ====================================\n");
    printf("Value = %s %s\n",str1[0],str1[1]);
    printf("Lenght of string pointed by arrray element = %ld %ld\n",strlen(str1[0]),strlen(str1[1]));
    printf("Size of array element = %ld\n\n",sizeof(str1[0]));

    printf("String 2 ====================================\n");
    printf("Value = %s %s\n",str2[0],str2[1]);
    printf("Lenght of string pointed by arrray element = %ld %ld\n",strlen(str2[0]),strlen(str2[1]));
    printf("Size of array element = %ld\n\n",sizeof(str2[0]));    
    
    free(str1[0]);
    free(str1[1]);
    return 0;
}
