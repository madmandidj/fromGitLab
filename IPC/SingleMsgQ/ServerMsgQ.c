#include "SingleMsgQ.h"
#define ONE_SECOND_USEC 1000000
#define TEN_SECOND_USEC 10000000
#define ERR_VAL -1
#define NUM_OF_LETTERS 26
#define LOWER_A_ASCI 97
#define MSG_SIZE 64
#define TX_PRINT 0
#define RX_PRINT 1
#define SERVER_TO_CLIENT_CH 2
#define CLIENT_TO_SERVER_CH 1



typedef struct Params
{
	int 	m_createMQFlag;
	int 	m_deleteMQFlag;
	int 	m_numOfMsgs;
	int 	m_eofMode;
	int 	m_verbosityMode;
	int 	m_speed;
	char* 	m_ftokFilename;
}Params;




static void DoGetOpt(int _argc, char* _argv[], Params* _params)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "cd:n:e:v:s:f:o:")) != -1) {
	   switch (opt) 
	   {
		case 'c':
			_params->m_createMQFlag = 1;
		   break;
		   
		case 'd':
			msgctl(atoi(optarg), IPC_RMID, NULL);
		   break;
		   
		case 'n':
			_params->m_numOfMsgs = atoi(optarg);
		   break;
		   
		case 'e':
			_params->m_eofMode = atoi(optarg);
		   break;
		   
		case 'v':
			_params->m_verbosityMode = atoi(optarg);
		   break;
		   
		case 's':
			_params->m_speed = atoi(optarg);
		   break;
		   
		case 'f':
			_params->m_ftokFilename = optarg;
		   break;
		   	   		
		default: 
		fprintf(stderr, "Usage: %s [-c create] [-d destroy] [-n numOfMsgs] [-e EOFtype] \
								   [-v verbosity] [-s speed] [-f filename]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
	
	if (1 == _argc)
	{
		_params->m_createMQFlag = 0;
		_params->m_deleteMQFlag = 0;
		_params->m_numOfMsgs = 1;
		_params->m_eofMode = 0;
		_params->m_verbosityMode = 0;
		_params->m_speed = 1;
		_params->m_ftokFilename = "SMQ";
	}
   
	return;
}







static void CreateMQ(key_t* _mqKey, int* _mqID, Params* _params)
{
	*_mqKey = ftok(_params->m_ftokFilename, 1);
	if (*_mqKey == -1)
	{
		printf("ftok() ERROR: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	
	*_mqID = msgget(*_mqKey, 0666 | IPC_CREAT); 
	
	if (-1 == *_mqID)
	{
		printf("ftok() ERROR: %s\n", strerror(errno));
		/*TODO: destroyqueu before exit */
		exit(EXIT_FAILURE);
		
	}

	printf("Message Queue created\n");
	
	return;
}









static void DeleteMQ(int _mqID, msqid_ds* _msqDs)
{
	msgctl(_mqID, IPC_RMID, _msqDs);
	
	return;
}





static void PrintMsg(MsgBuf* _msgBuf, Params* _params, int printMode, size_t index)
{
	if (TX_PRINT == printMode)
	{
		printf("ServerTx- pid: %d, channel: %ld, status:, %d, data1: %d, data2: %d, Tx counter: %d\n", \
				 _msgBuf->m_data.m_pid, _msgBuf->m_type, _msgBuf->m_data.m_status, _msgBuf->m_data.m_data1, \
				 	_msgBuf->m_data.m_data2, index + 1);
	}
	else if (RX_PRINT == printMode)
	{
		printf("ServerRx- pid: %d, channel: %ld, status:, %d, data1: %d, data2: %d, Tx counter: %d\n", \
				 _msgBuf->m_data.m_pid, _msgBuf->m_type, _msgBuf->m_data.m_status, _msgBuf->m_data.m_data1, \
				 	_msgBuf->m_data.m_data2, index + 1);
	}
	
	return;
}




static void InitServerMsg(MsgBuf* _msgBuf, int _msgChannel)
{
	_msgBuf->m_type = _msgChannel;
	_msgBuf->m_data.m_pid = getpid();
	_msgBuf->m_data.m_status = 1;
	_msgBuf->m_data.m_data1 = 1;
	_msgBuf->m_data.m_data2 = 1;
	
	return;
}






static void MsgTx(int mqID, MsgBuf* _txMsg, long _channel)
{
	int sndErr;
	
	sndErr = msgsnd(mqID, _txMsg, sizeof(Data), _channel);
	
	if (sndErr == -1)
	{
		printf("Server sndErr() ERROR: %s\n", strerror(errno));
		
		exit(EXIT_FAILURE);
	}
	
	return;
}





static void MsgRx(int _mqID, MsgBuf* _rxMsg, long _channel, int _flag)
{
	ssize_t rcvErr;
	
	rcvErr = msgrcv(_mqID, _rxMsg, sizeof(Data), _channel, _flag);
		
	if (rcvErr == -1)
	{
		if(ENOMSG != errno)
		{
			printf("Server rcvErr() ERROR %d: %s\n", errno, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	
	return;
}





static void ServerRoutine(int _mqID, Params* _params)
{
	size_t numOfMsgRx = 0;
	size_t numOfMsgTx = 0;
	MsgBuf msgBuf;
	MsgBuf txMsg;
	
	InitServerMsg(&txMsg, SERVER_TO_CLIENT_CH);
	
	for (;;)
	{
		MsgRx(_mqID, &msgBuf, CLIENT_TO_SERVER_CH, 0);

		if (1 == _params->m_verbosityMode)
		{
			PrintMsg(&msgBuf, _params, RX_PRINT, numOfMsgRx++);
		}
		
		usleep((size_t)_params->m_speed);
		
		MsgTx(_mqID, &txMsg, SERVER_TO_CLIENT_CH);
		
		if (1 == _params->m_verbosityMode)
		{
			PrintMsg(&txMsg, _params, TX_PRINT, numOfMsgTx++);
		}
	}
	
	return;
}








int main(int argc, char* argv[])
{
	int mqID;
	key_t mqKey;
	msqid_ds msqDs;
	Params params;
	
	DoGetOpt(argc, argv, &params);
	
	if (1 == params.m_createMQFlag)
	{
		CreateMQ(&mqKey, &mqID, &params);
	}
	
	ServerRoutine(mqID, &params);
	
	printf("Server done\n");
	
	DeleteMQ(mqID, &msqDs);
	
	printf("Message Queue deleted\n");

	return 0;
}



