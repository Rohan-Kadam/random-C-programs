#include <stdio.h>

int main(int argc, char *argv[])
{
	ssize_t input;
	if(argc < 2)
	{
		printf("Please enter an interger\n");
		return 0;
	}

	printf("Input = %s\n",argv[1]);
	input = atoi(argv[1]);
		
	printf("Signum of (%ld) = %ld\n", input, signum(input));

	return 0;
}
