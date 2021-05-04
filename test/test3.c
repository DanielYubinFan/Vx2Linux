//Pipe server test
#include "vxWorks.h"
#include "taskLib.h"
#include "stdio.h"
#include "ioLib.h"
#include "pipeDrv.h"

//Message structure
typedef struct
{
	VOIDFUNCPTR routine; //pointer to a function
	int arg;
} MSG_REQUEST;

#define TASK_PRI 254	// tServers task's priority

#define TASK_STACK_SIZE 5000		//tServer task's stack size
#define PIPE_NAME "/pipe/server" 	//name of the pipe device
#define NUM_MSGS 10					//max number of messages in the pipe
LOCAL int pipeFd; 					//File descriptor for the pipe device
LOCAL void pipeServer(); 			//erver task


// serverStart(): init pipeServer and execute the task inside the pipe
STATUS serverStart(){
	if (pipeDevCreate(PIPE_NAME, NUM_MSGS, sizeof(MSG_REQUEST)) == ERROR){
		perror("Error in creating pipe"); 	//print error if pipe is already created, but do not return
	}
// Open the pipe
	if ((pipeFd = open(PIPE_NAME, UPDATE, 0)) == ERROR){
		perror("Error in opening pipe device");
		return (ERROR);
	}
// Spawn the server task
	if(taskSpawn("tServer", TASK_PRI, (FUNCPTR)pipeServer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) == ERROR){
		perror("Error in spawning tServer task");
		close(pipeFd);
		return (ERROR);
	}
	return (OK);
}
// serverSend(): send the pipe message 
STATUS serverSend(VOIDFUNCPTR routine, /* name of the routine to execute*/ int arg /* argument of the routine */){
	MSG_REQUEST msgRequest;
	int status;
	/* Initialize the message structure */
	msgRequest.routine = routine;
	msgRequest.arg = arg;
	/* Send the message and return the results */
	status = write(pipeFd, (char*) &msgRequest, sizeof(MSG_REQUEST));
	return ((status == sizeof(MSG_REQUEST)) ? OK : ERROR);
}

// pipeServer(): read the pipe message, and execute the routine inside the message
LOCAL void pipeServer(){
	MSG_REQUEST msgRequest;
	while (read(pipeFd, (char*) &msgRequest, sizeof(MSG_REQUEST)) > 0)
		(*msgRequest.routine)(msgRequest.arg);
}
