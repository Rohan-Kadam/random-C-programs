#include <iostream>

void fun(int *p)
{
    int q = 10;
    
    printf("%d addr p=%lu\n\n",*p,p);
    *p = q;
    printf("%d addr p=%lu addr q=%lu\n\n",*p,p,&q);
}    
   
int main()
{
    int r = 20;
    int *p = &r;
    printf("addr p =%lu addr r=%lu\n\n\n",p,&r);
    fun(p);
    printf("%d ,%d  addr p=%lu", *p,r,p);
    return 0;
}

