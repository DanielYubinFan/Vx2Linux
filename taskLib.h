/*
 * task_spawn.h
 *
 *  Created on: Jul 5, 2018
 *      Author: sun
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define LOCAL static
#define STATUS int
#define IMPORT extern
#define FAST register

typedef struct task_item TASK;
typedef struct task_list LIST;
typedef void (*FUNCPTR)(void *arg);
//typedef void (*process_job)(void *arg);

//thread info
struct task_item {
	pthread_t threadID;
	char *name;
	int priority;
	int option;
	int stackSize;
	FUNCPTR task_func;
	int arg[10];
};

//this task_list is to record threadID which has been created
//we have to thread_join all the threadID at the end of main function
struct task_list{
	TASK* task;
	LIST* next;
};

TASK* taskCreate(void);

TASK* taskSpawn(char *t_name, int t_priority, int t_option, int t_stackSize, FUNCPTR t_task_func, int t_arg0,
		int t_arg1, int t_arg2, int t_arg3, int t_arg4, int t_arg5, int t_arg6, int t_arg7, int t_arg8, int t_arg9);

LIST* taskDelete(LIST* list, TASK* task);

LIST* listAdd(TASK* task, LIST* list);
LIST* listDel(LIST* list, unsigned long int tid);
void listClear(LIST* list);




