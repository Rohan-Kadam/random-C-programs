/*
    Hardcore C Memory Management
    9/6/16
 
    NOT SAFE. For god's sake: use glibc's malloc set.
 
    This is purely for learning purposes. 0/10 would
    _never_ recommend for production, unless you're
    planning on developing a memory management library.
 
    But, really. Are you a better C programmer than
    the guys at the GNU Project?
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
int main(void) {
 
    void *proc_break = sbrk(0);
   
    printf("Boundary: %p\n", proc_break);
   
    // should increase by 4 bytes
    if (brk(proc_break + 4) < 0) {
        perror("Couldn't Allocate Memory!!!\n");
        exit(1);
    }
   
    int *int_ptr = (int*)proc_break;
    *int_ptr = 16;
   
    printf("This is stored at %p : %i\n", int_ptr, *int_ptr ); 
    printf("Boundary: %p\n", sbrk(0));
 
    float *f_ptr = (float*)proc_break;
    *f_ptr = 0.1;
    printf("And now %p holds a float %.30f\n", f_ptr, *f_ptr);
   
    printf("Now I'm \"freeing\" that memory...\nsbrk(0) returns %p\n", sbrk(0));
    if (brk(proc_break+1) < 0) {
        perror("Couldn't Deallocate!!!\n");
        exit(2);
    }
 
    printf("But now it returns... %p [ROHAN: Cannot get back to %p for some reason, %c remains in that 1 byte block]\n"
		    ,sbrk(0),proc_break,*(char *)proc_break);
    printf("Now let's allocate for 'hello world'\n");
 
    char *feed = "hello world"; // we're gonna copy this literal to the heap!
 
    if (brk(proc_break + strlen(feed)+1 ) < 0) {
        perror("Couldn't Allocate Memory!!!\n");
        exit(3);
    }
 
    printf("Boundary: %p\n", sbrk(0));
    char *c_ptr = (char*)proc_break;
   
    for (int i = 0; i < strlen(feed) + 1; i++)
        c_ptr[i] = feed[i];
 
    printf("c_ptr = %p and holds %s\n", c_ptr, c_ptr);
 
    brk(proc_break+1);
 
    printf("Boundary: %p\n", sbrk(0));
    printf("But now it returns... %p [ROHAN: Cannot get back to %p for some reason, %c remains in that 1 byte block]\n"
		    ,sbrk(0),proc_break,*(char *)proc_break);
    
    printf("\n\nROHAN:\n");
    printf("Tried valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./a.out \
		\nNo leak detected!!?!\n\n");

    return 0;
}
