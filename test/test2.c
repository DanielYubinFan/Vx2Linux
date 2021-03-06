#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "taskLib.h"
#include "msgQLib.h"

MSG_Q_ID msid;

FUNCPTR task_func1(void * arg){
	char* msgchar = "hello how r u\0";

	msgQSend(msid, msgchar, strlen(msgchar), 0, 0);
	printf("send\n");
	printf("%s\n", msgchar);
	return NULL;
}

FUNCPTR task_func2(void * arg){
	printf("receive\n");

	char *buffer = NULL;
	buffer = (char *) malloc(maxMsgLen);
	int size = msgQReceive(msid, buffer, maxMsgLen, 0);

	printf("length is %d\n", size);
	printf("%s\n", buffer);
//	printf("%p\n", &buffer);
	return NULL;

}

int main(void){

	TASK* task1 = NULL;
	TASK* task2 = NULL;
	TASK* task3 = NULL;

	msid = msgQCreate(0, 0, 0);


	task1 = taskSpawn("myTask1", 2, 8, 2000, (FUNCPTR)task_func1,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	sleep(1);

	task2 = taskSpawn("myTask2", 3, 8, 2000, (FUNCPTR)task_func2,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

	while(1){
		;
	}
}


