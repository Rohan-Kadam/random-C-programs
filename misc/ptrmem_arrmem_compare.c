#include<stdio.h>

int main()
{
    int i=0;
    //printf("Hello");
    char arr[]="India";
    //arr==Space alloted , India==No separate space
    //India chars within space allocated to arr

    for(i=0;arr[i]!='\0';i++)
    {
      //  printf("Hello");
        printf("[ARRAY] Addr of %dth element: %x , %c\n",i,&arr[i],arr[i]);
    }
    printf("\n::::\n");
    char*ptr="India";
    //ptr==Space alloted , India==@Separate space
    //ptr points to space addr allocated to India
    
    for(i=0;(*ptr)!='\0';ptr++)
    {
        printf("[POINTER] Addr of %d th element: %x , %c\n",i,ptr,*ptr);
        i++;
    }
    return 0;
}