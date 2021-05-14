#include <stdio.h>

int main(int argc, char **argv){

	if(argc != 2){
	
		printf("Number of arguments is not equal to 2\n");
		exit(0);
	}
	
	printf("Argument = %s\n",argv[1]);

	return 0;
}
