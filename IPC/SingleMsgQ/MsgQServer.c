#include "SingleMsgQ.h"
#define ONE_SECOND_USEC 1000000
#define TEN_SECOND_USEC 10000000
#define ERR_VAL -1
#define NUM_OF_LETTERS 26
#define LOWER_A_ASCI 97
#define MSG_SIZE 64



static void DoGetOpt(int _argc, char* _argv[]          )
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "cdn:e:v:s:f:")) != -1) {
	   switch (opt) 
	   {
		case 'c':

		   break;
		case 'd':
		   break;
		case 'n':
		   break;
		case 'e':
		   break;
		case 'v':
		   break;
		case 's':
		   break;
		case 'f':
		   break;		   		   		
		default: 
		fprintf(stderr, "Usage: %s [-c create] [-d destroy] [-n numOfMsgs] \
								  [-e EOFtype] [-v verbosity] [-s speed] [-f filename]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
	
	if (1 == _argc)
	{
		*_txCycles = 2;
		*_bufSize = 10;
	}
   
	return;
}



static void InitMsg(MsgBuf* _msgBuf)
{
	_msgBuf->m_type = 1;
	_msgBuf->m_data.m_pid = getpid();
	_msgBuf->m_data.m_status = 50;
	_msgBuf->m_data.m_data1 = 60;
	_msgBuf->m_data.m_data2 = 70;
	
	return;
}


static void CreateMQ(key_t* _mqKey, int* _mqID)
{
	*_mqKey = ftok("fileid", 16);
	if (*_mqKey == -1)
	{
		printf("ftok() ERROR: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	*_mqID = msgget(*_mqKey, 0666 | IPC_CREAT);

	return;
}



static void ServerTx(int mqID, MsgBuf* _msgBuf)
{
	int sndErr;
	
	sndErr = msgsnd(mqID, _msgBuf, sizeof(Data), 0);
	if (sndErr == -1)
	{
		printf("sndErr() ERROR: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	return;
}


static void DestroyMQ(int _mqID, msqid_ds* _msqDs)
{
	msgctl(_mqID, IPC_RMID, _msqDs);
	
	return;
}


int main()
{
	int mqID;
	key_t mqKey;
	msqid_ds msqDs;
	MsgBuf msgBuf;
	
	InitMsg(&msgBuf);
	
	CreateMQ(&mqKey, &mqID);
	
	ServerTx(mqID, &msgBuf);
	
	usleep(ONE_SECOND_USEC);
	
	DestroyMQ(mqID, &msqDs);

	return 0;
}















