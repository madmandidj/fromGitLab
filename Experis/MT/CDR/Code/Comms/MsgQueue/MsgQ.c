#include "MsgQ.h"
#include <stdio.h>			/* printf */
#include <sys/msg.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <errno.h>			/* errno */
#include <stdlib.h>			/* atoi, exit */
#include <string.h>			/* strerr */
#include <unistd.h>			/* getcwd */
#define QUEUE_PATHNAME "../Comms/MsgQueue/MQ"



void MsgQCreate(key_t* _mqKey, int* _mqID, char* _myPathToMsgQ)
{

	char cwd[1024];
	
	getcwd(cwd, sizeof(cwd));
	
	*_mqKey = ftok(_myPathToMsgQ, 1);
	if (*_mqKey == -1)
	{
		printf("ftok() ERROR: %s\n", strerror(errno));
		
		exit(EXIT_FAILURE);
	}
	
	
	*_mqID = msgget(*_mqKey, 0666 | IPC_CREAT); 
	
	if (-1 == *_mqID)
	{
		printf("ftok() ERROR: %s\n", strerror(errno));
		
		exit(EXIT_FAILURE);
	}
	
	return;
}



void MsgQDestroy(int _mqID, msqid_ds* _msqDs)
{
	msgctl(_mqID, IPC_RMID, _msqDs);
	
	return;
}



int MsgQTransmit(int _mqID, Msg* _txMsg, size_t _msgSize, int _channel)
{
	int sndErr;
	
	sndErr = msgsnd(_mqID, _txMsg, _msgSize, _channel);

	return sndErr;
}



ssize_t MsgQReceive(int _mqID, Msg* _rxMsg, size_t _msgSize, int _channel, int _flag)
{
	ssize_t rcvErr;
	
	rcvErr = msgrcv(_mqID, _rxMsg, _msgSize, _channel, _flag);
	
	return rcvErr;
}




