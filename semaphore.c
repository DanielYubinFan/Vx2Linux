#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "semLib.h"


SEM_ID* semBCreate (SEM_ID* sem, int options, SEM_B_STATE initialState){
	int sem_create;
	sem_create = sem_init(sem, 0, 1);
	if(sem_create == -1){
		printf("sem create error\n");
		exit(0);
	}
	printf("create sem1 is %d\n", sem);
	return sem;
}

SEM_ID semCCreate(int options, int initialCount){
	sem_t sem;
	int sem_create;
	sem_create = sem_init(&sem, 0, initialCount);
	if(sem_create == -1){
		printf("sem create error\n");
		exit(0);
	}
	return sem;
}


void semDelete(SEM_ID* semId){
	int sem_del;
	sem_del = sem_destroy(semId);
	if(sem_del == -1){
		printf("sem delete error\n");
		return;
	}
	return;
}


void semTake(SEM_ID* sem, int wait_time){
	if(sem_wait(sem) == -1){
		printf("sem take error\n");
		return;
	}
}

void semGive(SEM_ID* sem){
	if(sem_post(sem) == -1){
		printf("sem give error\n");
		return;
	}
}

