#include <stdio.h>
#include <stdarg.h>

void myerror(char *fmt, ...){
	va_list argp; 
	
	fprintf(stderr, "error: ");
	
	va_start(argp, fmt);
	
	vfprintf(stderr, fmt, argp);
	
	va_end(argp);
	
	fprintf(stderr, "\n");
}

int main(){

	myerror("MY ERROR %d",101);
	return 0;
}
