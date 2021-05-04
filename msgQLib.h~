#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>

#define maxMsgLen 256

typedef int MSG_Q_ID;
typedef unsigned int UINT;

struct  msgbuf
{
	long    mtype;
	char    mdata[maxMsgLen];
};


MSG_Q_ID msgQCreate(int maxMsgs, int maxMsgLength, int options);

void msgQDelete(MSG_Q_ID msgQId);

void msgQSend(MSG_Q_ID msgQId, char * buffer, UINT nBytes, int timeout, int priority);

int msgQReceive(MSG_Q_ID msgQId, char * buffer, UINT maxNBytes, int timeout);
