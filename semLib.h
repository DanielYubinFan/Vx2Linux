/*
 * semLib.h
 *
 *  Created on: Jul 11, 2018
 *      Author: sun
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SEM_FULL 1
#define WAIT_FOREVER 1
#define SEM_Q_FIFO 1

typedef sem_t SEM_ID;

typedef int SEM_B_STATE;

SEM_ID* semBCreate (SEM_ID* sem, int options, SEM_B_STATE initialState); //binary semaphore
SEM_ID semMCreate (int options, SEM_B_STATE initialState); //mutex semaphore
SEM_ID semCCreate(int options, int initialCount); //counting semaphore

void semDelete(SEM_ID* semId);

void semTake(SEM_ID* semId, int wait_time);//take the sem

void semGive(SEM_ID* semId);//release the sem

void semFlush(SEM_ID* semId);
