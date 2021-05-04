#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

#include "msgQLib.h"


MSG_Q_ID msgQCreate(int maxMsgs, int maxMsgLength, int options){
	key_t key = ftok(".",123);
	int msid;
	msid = msgget(key, IPC_CREAT|IPC_EXCL, 0666);
	if(msid == -1){
		printf("msgQ create error\n");
		return -1;
	}
	return msid;
}

void msgQSend(MSG_Q_ID msgQId, char* buffer, UINT nBytes, int timeout, int priority){
	struct msgbuf msg;
	memcpy(&msg.mdata, buffer, nBytes);
//	msg.mtype = 0;
	if(msgsnd(msgQId, &msg, nBytes, 0) == -1){
		printf("msgQ send fail\n");
		return;
	}
}

int msgQReceive(MSG_Q_ID msgQId, char* buffer, UINT maxNBytes, int timeout){
	struct msgbuf msg;
	memset(&msg, 0, sizeof(msg));
	int size;
	size = msgrcv(msgQId, &msg, sizeof(msg.mdata), 0, 0);
	if(size == -1){
		printf("msgQ receive fail\n");
		return -1;
	}
	//printf("%s\n", msg.mdata);
	memcpy(buffer, &msg.mdata, sizeof(msg.mdata));
//	buffer = msg.mdata;
//	printf("%p\n", &buffer);
	return size;
}
