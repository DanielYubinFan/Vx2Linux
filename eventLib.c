#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "taskLib.h"
#include "eventLib.h"

int eventSend (TASK* task_id , int event)
{



	return 1;
}

int eventReceive (int event, int options, int wait_time, uint32_t* event_table)
{

}

int eventClear (uint32_t* event_table)
{

}
