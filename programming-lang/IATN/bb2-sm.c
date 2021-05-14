// ALL abt State, Events and Event Handlers
// Implemented using func ptr and 2D array

#include <stdio.h>

// Using enums for listing different States and Events
// make code more readable
typedef enum
{
    Stop_State,
    Ready_State,
    Go_State,
    last_State
} eState;

typedef enum
{
    Switch_On_Red_Light_Event,
    Switch_On_Yellow_Light_Event,
    Switch_On_Green_Light_Event,
    last_Event
} eEvent;

#define MAX_EVENTS last_Event
#define MAX_STATES last_State

typedef int (*fptr)(void);
//fptr a[100];
//struct a[100];
//int a[100];


// Below we have different event handler to perform necessary actions
// We can perform more actions in event handler based on the application
// Return type is eState, as our FSM should enter next state after completing
// the action in event handler
// 
eState Red_Light_EventHandler(void)
{
	// Here we can switch ON the Red LED 
	// And incase of failure to switch Red LED ON, we can return
	// previous state to continue proper functioning (Error handling code
	// not included in this code)
    return Stop_State;
}

eState Yellow_Light_EventHandler(void)
{			
	printf("in EV\n");
    return Ready_State;
}

eState Green_Light_EventHandler(void)
{
    return Go_State;
}

int main(int argc, char *argv[])
{
	//We can create multiple, and maintain status for each traffic signal
	//separately
    eState trafficSignal_01_State;
    eEvent trafficSignal_01_Prev_Event;

	// Lets map the valid pairs of States and Events to their
	// corresponding Event hanlders
	// This entity is common for all traffic signals in town
    // We can have larger FSMs with multiple input states and events
    // Eg. use 3d array for FSM which has dependence on 2 states when
    // an event occurs. That way both states + event can be use to select
    // a event hanlder 
    // This is array of function ptrs,
    // Just like array of integers store int at each index
    // Just like array of structure stores a particular struct on each index.
    static fptr trafficSignal_FSM[MAX_STATES][MAX_EVENTS];

    // Init all to NULL, to avoid random address access
    // A safer address can be allotted instead of NULL
    // to avoid NULL ptr deref error.
	for (int i = 0; i < MAX_STATES; ++i){
    	for (int j = 0; j < MAX_EVENTS; ++j){
    		trafficSignal_FSM[i][j] = NULL;
    	}
    }
    trafficSignal_FSM[Go_State][Switch_On_Red_Light_Event] = Red_Light_EventHandler;
    trafficSignal_FSM[Stop_State][Switch_On_Yellow_Light_Event] = Yellow_Light_EventHandler;
    trafficSignal_FSM[Ready_State][Switch_On_Green_Light_Event] = Green_Light_EventHandler;
    
    trafficSignal_01_State = Stop_State;
    //trafficSignal_01_Prev_Event = ANY;
    char buf[10] = {0};
   	while(1)
    {
        // assume api to read the next event
        eEvent trafficSignal_01_Next_Event = Switch_On_Yellow_Light_Event;
		trafficSignal_01_State = Stop_State;
		printf("Type \"next\" and press RETURN\n");
		
		int ret = fgets(buf,6,stdin);
		if (ret == NULL)
		{
			return 1;
		};
		fflush(stdin);
		if (strcmp(buf,"next") == 0)
		{
		
			printf("stdin worked\n");
	        //Check NULL pointer and array boundary
	        if( ( trafficSignal_01_State < last_State) && (trafficSignal_01_Next_Event < last_Event) && trafficSignal_FSM[trafficSignal_01_State][trafficSignal_01_Next_Event]!= NULL)
	        {
	        	printf("sdf\n");
	            // function call as per the state and event and return the next state of the finite state machine
	            trafficSignal_01_State = (*trafficSignal_FSM[trafficSignal_01_State][trafficSignal_01_Next_Event])();
	        }
	        else
	        {
	            //Invalid
	        }
	    }
    }
    return 0;
}

