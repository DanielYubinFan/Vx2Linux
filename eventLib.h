#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "taskLib.h"

#define VXE01 1
#define VXE02 2


int eventSend (TASK* task_id , int event);

int eventReceive(int event, int options, int wait_time, uint32_t* event_table);

int eventClear(uint32_t* event_table);
