#include <iostream>
#include <unistd.h>
#include "timer.h"

cTimer::handler_type_int hdlr(cTimer::timer_id tid){
	fprintf(stderr, "Inside timer handler\n");
	fprintf(stderr, "Exiting from timer handler\n");
	exit(0);
}

int main(){
	cTimer c;
	cTimer::timer_id tid;
	
	tid = c.fStartTimer(2, hdlr, tid);
	sleep(1);
	//c.fStopTimer(tid);
	while(1);
	fprintf(stderr, "Exiting from main...\n");

	return 0;
}