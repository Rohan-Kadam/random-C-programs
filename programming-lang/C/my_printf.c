/*
 * Module 1: Initializing Myprintf’s arguments
 * >> va_list arg : We initialize the arguments of Myprintf() function by using standard argument library.
 * >> va_start(arg, format) : This line initializes arg variable with function’s last fixed argument i.e. format. 
 * va_start() uses this to figure out where the variable arguments begin. 
 *
 * Module 2: Fetching and executing arguments
 * >> i = va_arg(arg,int) : va_arg() fetches the next argument from the argument list. 
 * The second parameter to va_arg() is the data type of the argument we expect. 
 * NOTE: va_arg( ) function will never receive arguments of type char, short int, or float. 
 * va_arg( ) function only accept arguments of type char *, unsigned int, int or double.
 *
 * Module 3: Closing argument list to necessary clean-up
 * va_end(arg) : Finally, when we’re finished processing the all arguments, we call va_end(), which performs any necessary cleanup
 *
 *
 * Original standard printf()
__printf (const char *format, ...){
	va_list arg;
	int done;
	va_start (arg, format);
	done = vfprintf (stdout, format, arg);
	va_end (arg);

	return done;
}
 *
 *
 */


#include <stdio.h>
#include <stdarg.h>						
 
void Myprintf(char *,...); 			//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.
 
 
int main(){ 
	
	Myprintf("HELLO WORLD\n %c \n %s %d %x %o", 'A',"Hello",15,15,15); 
	return 0;
} 
 
 
void Myprintf(char* format,...){ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	
	for(traverse = format; *traverse != '\0'; traverse++) {

		while( *traverse != '%' ) { 
			putchar(*traverse);
			traverse++; 
		} 	
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		switch(*traverse) { 
					
			case 's': s = va_arg(arg,char *); 		//Fetch string
						puts(s); 
						break; 
			
			case 'c': i = va_arg(arg,int);			//Fetch char argument
						putchar(i);
						break; 
				
			case 'd': i = va_arg(arg,int); 			//Fetch Decimal/Integer argument
						if(i<0){ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break; 
						
			case 'o': i = va_arg(arg,unsigned int); 	//Fetch Octal representation
						puts(convert(i,8));
						break; 
						
						
			case 'x': i = va_arg(arg,unsigned int); 	//Fetch Hexadecimal representation
						puts(convert(i,16));
						break; 
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 
 
char *convert(unsigned int num, int base){ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr); 
}

