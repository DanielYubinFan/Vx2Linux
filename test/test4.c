#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>


void eventRoute1(void* param)
{
     int task_id = (int)param;
     eventSend(task_id , VXEV01);

}
void tryEvent()
{
     int id = taskIdSelf();
     taskSpawn("vxEvent1", 150, VX_FP_TASK, 30000, (FUNCPTR)eventRoute1, id,0,0,0,0,0,0,0,0,0 );
     eventReceive(VXEV01, EVENTS_WAIT_ALL, WAIT_FOREVER, 0);

}
