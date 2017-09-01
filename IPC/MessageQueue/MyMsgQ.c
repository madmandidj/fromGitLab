#include "MyMsgQ.h"



void DoGetOpt(int _argc, char* _argv[], Params* _params)
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
		fprintf(stderr, "Usage: %s [-c create] [-d destroy] [-n numOfMsgs] [-e EOFtype] [-v verbosity] [-s speed] [-f filename]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
	
	if (1 == _argc)
	{
		_params->m_createMQFlag = 1;
		_params->m_deleteMQFlag = 0;
		_params->m_numOfMsgs = 5;
		_params->m_eofMode = 0;
		_params->m_verbosityMode = 1;
		_params->m_speed = 1000000;
		_params->m_ftokFilename = "SMQ";
	}
   
	return;
}







void CreateMQ(key_t* _mqKey, int* _mqID, Params* _params)
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




void DeleteMQ(int _mqID, msqid_ds* _msqDs)
{
	msgctl(_mqID, IPC_RMID, _msqDs);
	
	return;
}





void PrintMsg(MsgBuf* _msgBuf, Params* _params, char* _printerStr, size_t index)
{

	if (1 == _params->m_verbosityMode)
	{
		printf("%s- pid: %d, channel: %ld, status:, %d, data1: %d, data2: %d, Tx counter: %d\n", _printerStr,\
					 _msgBuf->m_data.m_pid, _msgBuf->m_channel, _msgBuf->m_data.m_status, _msgBuf->m_data.m_data1, \
					 	_msgBuf->m_data.m_data2, index + 1);
	}
	
	return;
}





int MsgTx(int mqID, MsgBuf* _txMsg)
{
	int sndErr;
	
	sndErr = msgsnd(mqID, _txMsg, sizeof(Data), _txMsg->m_channel);

	return sndErr;
}





ssize_t MsgRx(int _mqID, MsgBuf* _rxMsg, int _channel, int _flag)
{
	ssize_t rcvErr;
	
	rcvErr = msgrcv(_mqID, _rxMsg, sizeof(Data), _channel, _flag);

	
	return rcvErr;
}













