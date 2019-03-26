/**
 *
 * Compile using: gcc application.c null.c -L . -l_myDlib -o sample 
 * Export path using: export LD_LIBRARY_PATH=<file-path>:$LD_LIBRARY_PATH
 * @file application.c
 * @author Rohan-Kadam
 * @date March 7, 2019
 * @brief This is main file of project. Testing doxygen document generator for shared library project.
 *
 * \mainpage Description
 * Add description here
 *  
 * \section library_sec libraries used in this Project 
 * \subsection library1
 * library1 description
 * more description
 *
**/

#include <stdio.h>
#include "null.h"

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
	null_func();		
	printf("Signum of (%ld) = %ld\n", input, signum(input));

	return 0;
}
