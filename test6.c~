/*Socket
 * client-server send/receive messages
 * */
#include <stdio.h>    
#include <taskLib.h>   
#include <unistd.h>   
#include <sockLib.h>   
#include <netinet/in.h>   
#include <inetLib.h>   
#include <string.h>   

#define TASK_PRIORITY_A 130   
#define TASK_PRIORITY_B 130   
#define STACK_SIZE 225   
#define PORT 3733   

int taskId_A, taskId_B; 
void taskA(void);  
void taskB(void);    
//IP address of the server  
char ip[]="127.0.0.1";  
//Socket of the vlient and the server 
struct sockaddr_in serAddr, cliAddr;  
int len = sizeof(struct sockaddr_in);    

int main(){        
	//create a task by taskSpawn()      
	taskId_A = taskSpawn("taskA", TASK_PRIORITY_A, VX_FP_TASK, STACK_SIZE, (FUNCPTR)taskA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);      
	taskId_B = taskSpawn("taskB", TASK_PRIORITY_B, VX_FP_TASK, STACK_SIZE, (FUNCPTR)taskB, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);      
	if (taskId_A == ERROR)          
		printf("taskA taskSpawn() failed!\n");      
	if (taskId_B == ERROR)          
		printf("taskB taskSpawn() failed!\n");    
}

//Client  
void taskA(){      
	int sockFd, newFd;      
	char msg[] = "hello";        
	//create the socket      
	sockFd = socket(AF_INET,SOCK_STREAM,0);
     
	//Setup the socket address     
	serAddr.sin_family = AF_INET;      
	serAddr.sin_port = PORT;     
	inet_aton(ip, &(serAddr.sin_addr));    
	memset(serAddr.sin_zero, 0, 8);      
     
	//Bind the socket with the address and listen     
	bind(sockFd, (struct sockaddr*)&serAddr, len);          
	listen(sockFd, 10);         
	newFd = accept(sockFd, (struct sockaddr *)&cliAddr, &len);        
	printf("[server]Get connect!\n");     
	//send the message      
	write(newFd, msg, sizeof(msg));        
	printf("[Server]Send message!\n");  
}  

//Server 
void taskB(){      
	int sockFd, rLen;      
	char buf[100];           
	sockFd=socket(AF_INET,SOCK_STREAM,0);      
	//Connect the socket     
	if (connect(sockFd, (struct sockaddr*)&serAddr, len)==OK)          
		printf("[client]Connected\n");      
	memset(buf, 0, 100);     
	//receive the message      
	rLen=read(sockFd, buf, 255);      
	buf[rLen]='\0';      
	printf("[client]Get message:%s\n", buf);  
}  
