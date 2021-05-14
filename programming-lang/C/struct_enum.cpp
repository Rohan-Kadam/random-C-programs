//
// - All enum constants must be unique in their scope
// Cannot have enum day2 with any same element
//
#include <stdio.h> 
enum day {sunday = 1, monday, tuesday = 5, 
          wednesday, thursday = 10, friday, saturday}; 
  
int main() 
{ 
	enum day d = thursday; 
	printf("The day number stored in d is %d\n", d); 
	
	printf("%d %d %d %d %d %d %d", sunday, monday, tuesday, 
            wednesday, thursday, friday, saturday); 

    return 0; 
} 

