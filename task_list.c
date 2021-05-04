/*
 * task_list.c
 *
 *  Created on: Jul 10, 2018
 *      Author: sun
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "taskLib.h"

LIST* listAdd(TASK* task, LIST* list){
	LIST* new = NULL;
	new = (LIST*)malloc(sizeof(LIST));
	if(!new){
		printf("memory allocate error\n");
		return NULL;
	}
	new->task = task;
	new->next = NULL;
	if(list == NULL){
		list = new;
	}
	else{
		list->next = new;
	}
	return list;
}

LIST* listDel(LIST* list, unsigned long int tid){
	LIST* curr_ptr = NULL;
	curr_ptr = (LIST*)malloc(sizeof(LIST));
	LIST* prev_ptr = NULL;
	prev_ptr = (LIST*)malloc(sizeof(LIST));

	if(!curr_ptr){
		printf("memory allocate error\n");
		return NULL;
	}

	curr_ptr = list;
	if(curr_ptr->task->threadID == tid){
		pthread_cancel(curr_ptr->task->threadID);
		list = curr_ptr ->next;
		free(curr_ptr);
		return list;
	}
	prev_ptr = curr_ptr;
	curr_ptr = curr_ptr->next;
	while(curr_ptr != NULL){
		if(curr_ptr->task->threadID == tid){
			pthread_cancel(curr_ptr->task->threadID);
			prev_ptr->next = curr_ptr->next;
			free(curr_ptr);
			return list;
		}
		curr_ptr = curr_ptr->next;
		prev_ptr = prev_ptr->next;
	}
	printf("task_list has no such taskID\n");
	return list;
}

void listClear(LIST* list){
	LIST* curr_ptr = NULL;
	curr_ptr = (LIST*)malloc(sizeof(LIST));
	if(!curr_ptr){
		printf("memory allocate error\n");
		return;
	}

	curr_ptr = list;

	if(curr_ptr == NULL){
		return;
	}

	while(curr_ptr != NULL){
		int task_join;
		task_join = pthread_join(curr_ptr->task->threadID, NULL);
		if (task_join != 0){
			printf("thread join error\n");
			return;
		}
		curr_ptr = curr_ptr->next;
	}
}

