#include<iostream>
#include<cstring>

using namespace std;

int main()
{
char p[20];
char test[20]={'h','e'};
char *s = "string";
int length = strlen(s);
int i;
for (i = 0; i < length; i++){
    p[i] = s[length - i];
    printf("%c",p[i]);

printf("%s",p);   
}
test[2]='A';
printf("%s",test);   
}

