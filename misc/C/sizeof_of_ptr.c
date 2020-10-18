#include <stdio.h>

int main(){

  void *a;
  char *b;
  int *c;
  int cint;
  float *d;

  //The size of pointer's is platform dependent.
  //Platform and pointer size:
  //Platform – 16 bit : 2 bytes
  //Platform – 32 bit : 4 bytes
  //Platform – 64 bit : 8 bytes
  
  printf("Size - void pointer:%d\n",sizeof(a));
  printf("Size - char pointer:%d\n",sizeof(b));
  printf("Size - int pointer:%d\n",sizeof(c));
  printf("Size - float pointer:%d\n",sizeof(d));

  //32 bit machine has 4-Byte int instead of 2-Byte, to match the word size. So 64-bit machine should have 8-Byte int (8*4=32, 8*8=64)
  //There is nothing stopping compilers from using an 8-byte int other than the fact that it would probably break tons of existing code.
  printf("Size - int:%d\n",sizeof(cint));

  return 0;

}
