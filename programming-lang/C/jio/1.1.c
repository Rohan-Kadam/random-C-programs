
#include <stdio.h>

static inline void print(int i, int limit){
	do{
	if(i++<limit){
		printf("Hello\n");
		continue;
	}
	}while(1);
}


#define PRINT(i, limit) do \
                        { \
                            if (i < limit) \
                            { i++;\
				    printf("GeeksQuiz\n"); \
				    continue; \
                            } \
                        }while(1)

int main()
{
//	print(0,3);
	//int i=0;
    PRINT(0, 3);
    return 0;
}

