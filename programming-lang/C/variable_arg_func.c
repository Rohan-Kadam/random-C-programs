/*
 * Check my_printf for understanding va_list, va_start, va_arg, va_end
 *
 * Q1: How can I find how many arguments a function was passed? 
 * A--> Pass number of args as argument or add sentinel arg as last arg, to detect end of args
 *
 * Q2: Is this allowed ? void function(…..)
 * A--> No! Standard C requires at least one fixed argument, in part so that you can hand it to va_start().
 *
 * Q3: How do I get floating point numbers passed as arguments?
 * A--> Do not use float, short, char
 *
 */

#include <stdio.h>
#include <stdarg.h>
 
// Add all the arguments and return sum  untill zero(0) appear
int SumArgs(int first_arg, ...)
{
	int i,sum=0;
	
	va_list args;
	va_start(args, first_arg); 
	
	for (i = first_arg; i > 0; i = va_arg(args, int))
	{
		sum+=i;
	}
	
	va_end(args);
	
	return sum;
}
 
int main(void)
{
   printf("%d\n",SumArgs(10,10,10,0));
 
   return 0;
}
