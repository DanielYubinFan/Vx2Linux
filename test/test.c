#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "taskLib.h"
#include "semLib.h"

SEM_ID sem;

FUNCPTR task_func1(void * arg){
	semTake(&sem, WAIT_FOREVER);

	int policy;
	struct sched_param param;
	pthread_getschedparam(pthread_self(), &policy, &param);
	if(policy == SCHED_OTHER)
		printf ("SCHED_OTHER\n");
	if(policy == SCHED_RR)
	    printf ("SCHED_RR\n");
	if(policy == SCHED_FIFO)
		printf("SCHED_FIFO\n");

	int *argv = (int *)arg;
	int i = 0;
	for (i = 0; i < 10; i++){
		printf("func1 argv[%d] is %d\n", i, argv[i]);
	}

	semGive(&sem);
	return NULL;
}

FUNCPTR task_func2(void * arg){
	semTake(&sem, WAIT_FOREVER);

	int policy;
	struct sched_param param;
	pthread_getschedparam(pthread_self(), &policy, &param) ;
	if(policy == SCHED_OTHER)
		printf("SCHED_OTHER\n");
	if(policy == SCHED_RR)
	    printf("SCHED_RR\n");
	if(policy == SCHED_FIFO)
	    printf("SCHED_FIFO\n");

	int *argv = (int *)arg;
	int i = 0;
	for (i = 0; i < 10; i++){
		printf("func2 argv[%d] is %d\n", i, argv[i]);
	}

	semGive(&sem);
	return NULL;
}

int main(void){
	//LIST* list = NULL;
	TASK* task1 = NULL;
	TASK* task2 = NULL;
	TASK* task3 = NULL;


	semBCreate(&sem, SEM_Q_FIFO, SEM_FULL);
	task1 = taskSpawn("myTask1", 2, 8, 2000, (FUNCPTR)task_func1,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

//	list = listAdd(task1, list);

	task2 = taskSpawn("myTask2", 3, 8, 2000, (FUNCPTR)task_func2,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

//	list = listAdd(task2, list);
//	task3 = taskSpawn("myTask3", 3, 8, 2000, (FUNCPTR)task_func2,
//			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, list);

//	pthread_join(task1->threadID, NULL);
//	pthread_join(task2->threadID, NULL);
//	pthread_join(task3->threadID, NULL);
//	list =  taskDelete(list, task1);
//	listClear(list);
	while(1){
		;
	}
}
