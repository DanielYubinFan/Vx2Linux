#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "taskLib.h"

//this list is to record created threads


TASK* taskCreate(void){

	TASK* task = (TASK *) malloc (sizeof(TASK));
		if(!task){
			printf("memory allocation error\n");
			return NULL;
		}

	return task;
}


TASK* taskSpawn(char *t_name, int t_priority, int t_option, int t_stackSize, FUNCPTR t_task_func, int t_arg0,
		int t_arg1, int t_arg2, int t_arg3, int t_arg4, int t_arg5, int t_arg6, int t_arg7, int t_arg8, int t_arg9){

	TASK* task = taskCreate();

	task->threadID = (unsigned long int)task;
	task->name = t_name;
	task->priority = t_priority;
	task->option = t_option;
	task->stackSize = t_stackSize;
	task->task_func = t_task_func;

	task->arg[0] = t_arg0;
	task->arg[1] = t_arg1;
	task->arg[2] = t_arg2;
	task->arg[3] = t_arg3;
	task->arg[4] = t_arg4;
	task->arg[5] = t_arg5;
	task->arg[6] = t_arg6;
	task->arg[7] = t_arg7;
	task->arg[7] = t_arg7;
	task->arg[8] = t_arg8;
	task->arg[9] = t_arg9;
	//set thread priority and scheduling model as FIFO
	//SCHED_FIFO support FIFO and priority race

	struct sched_param param;
	printf("hello\n");
	param.sched_priority = task->priority;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setstacksize(&attr, task->stackSize);
	pthread_attr_setschedpolicy (&attr, SCHED_FIFO);
	pthread_attr_setschedparam (&attr, &param) ;
	pthread_attr_setinheritsched (&attr, PTHREAD_EXPLICIT_SCHED) ;//let priority schedule works

	int task_exe;
//	printf("hello\n");

	task_exe = pthread_create(&(task->threadID), &attr, task->task_func, task->arg);
	if (task_exe != 0){
		printf("task_exe is %d\n", task_exe);
		printf("thread create error\n");
		return NULL;
	}
//	pthread_detach(task->threadID);
//	list = listAdd(task, list);
	return task;
}

/*
LIST* taskDelete(LIST* list, TASK* task){
	unsigned long int tid = (unsigned long int)task;
	list =  listDel(list, tid);
	return list;
}*/

/*
FUNCPTR task_func1(void * arg){
	int policy;
	struct sched_param param;
	pthread_getschedparam(pthread_self( ) , &policy, &param) ;
	if(policy == SCHED_OTHER)
		printf ("SCHED_OTHER\n");
	if(policy == SCHED_RR)
	    printf ("SCHED_RR\n");
	if(policy == SCHED_FIFO)
	    printf ("SCHED_FIFO\n");

	int *argv = (int *)arg;
	int i = 0;
	for (i = 0; i < 10; i++){
		printf("func1 argv[%d] is %d\n", i, argv[i]);
	}
	return NULL;
}

FUNCPTR task_func2(void * arg){
	int policy;
	struct sched_param param;
	pthread_getschedparam(pthread_self( ), &policy, &param) ;
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
	return NULL;

}

int main(void){
	LIST* list = NULL;
	TASK* task1 = NULL;
	TASK* task2 = NULL;

	task1 = taskSpawn("myTask1", 2, 8, 2000, (FUNCPTR)task_func1,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	list = listAdd(task1, list);
	task2 = taskSpawn("myTask2", 3, 8, 2000, (FUNCPTR)task_func2,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	list = listAdd(task2, list);

//	task3 = taskSpawn("myTask3", 3, 8, 2000, (FUNCPTR)task_func2,
//			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, list);

//	pthread_join(task1->threadID, NULL);
//	pthread_join(task2->threadID, NULL);
//	pthread_join(task3->threadID, NULL);
//	list =  taskDelete(list, task1);
	listClear(list);
}
*/
