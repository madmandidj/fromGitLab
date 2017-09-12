#include "MsgQ.h"

#include <stdio.h>			/* printf */
#include <sys/msg.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <errno.h>			/* errno */
#include <stdlib.h>			/* atoi, exit */
#include <string.h>			/* strerr */
//#include <fcntl.h>			/* O_CREAT */
//#include <unistd.h>			 getpid, usleep, getopt 
//#include <semaphore.h>		/* sem_t, sem_open */

#define QUEUE_PATHNAME "MQ"




/*struct Msg*/
/*{*/
/*    long 	m_channel;*/
/*    void* 	m_data;*/
/*};*/



void MsgQCreate(key_t* _mqKey, int* _mqID)
{
	*_mqKey = ftok("../../Comms/MsgQueue/MQ", 1);
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

	printf("Message Queue created or joined\n");
	
	return;
}





void MsgQDestroy(int _mqID, msqid_ds* _msqDs)
{
	msgctl(_mqID, IPC_RMID, _msqDs);
	return;
}






int MsgQTransmit(int mqID, Msg* _txMsg, size_t _msgSize, int _channel)
{
	int sndErr;
	
	sndErr = msgsnd(mqID, _txMsg, _msgSize, _channel);

	return sndErr;
}





ssize_t MsgQReceive(int _mqID, Msg* _rxMsg, size_t _msgSize, int _channel, int _flag)
{
	ssize_t rcvErr;
	
	rcvErr = msgrcv(_mqID, _rxMsg, _msgSize, _channel, _flag);
	
	return rcvErr;
}






