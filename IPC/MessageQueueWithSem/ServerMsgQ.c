#include "MyMsgQ.h"




static void InitServerMsg(MsgBuf* _txMsg, int _msgChannel, int _msgType)
{
	_txMsg->m_channel = _msgChannel;
	_txMsg->m_data.m_pid = getpid();
	
	switch (_msgType)
	{
		case GEN_MSG:
			_txMsg->m_data.m_status = 10;
			_txMsg->m_data.m_data1 = 10;
			_txMsg->m_data.m_data2 = 10;
			break;
			
		default:
			_txMsg->m_data.m_status = 13;
			_txMsg->m_data.m_data1 = 13;
			_txMsg->m_data.m_data2 = 13;
	}
	
	return;
}





static void ServerSignIn(sem_t* _serverSem)
{
	sem_post(_serverSem);
	
	printf("Server has signed in\n");
	
	return;
}





static void ServerSignOut(int _mqID, sem_t* _serverSem, sem_t* _clientSem)
{
	int semVal;
	
	sem_wait(_serverSem);
	
	sem_getvalue(_serverSem, &semVal);
	
	if (semVal == 0)
	{
		sem_close(_clientSem);
		sem_close(_serverSem);
		DeleteMQ(_mqID, NULL);
		printf("Server has signed out\n");
		printf("Message Queue destroyed\n");
		return;
	}
	/*
	unlink(CSEM_NAME);
	unlink(SSEM_NAME);
	*/
	
	printf("Server has signed out\n");
	
	return;
}





static void WaitForClientSignIn(sem_t* _clientSem)
{
	
	while (-1 == sem_trywait(_clientSem))
	{
		printf("Server waiting for client sign in\n");
		usleep(ONE_SECOND_USEC);
	}
	
	sem_post(_clientSem);
	
	return;
}





static int IsClientSignedIn(sem_t* _clientSem)
{
	int semVal;
	
	sem_getvalue(_clientSem, &semVal);

	if (0 == semVal)
	{
		return 0;
	}
	
	return 1;

}




static int IsMsgInQueue(int _mqID)
{
	MsgBuf rxMsg;
	
	if (-1 == MsgRx(_mqID, &rxMsg, C2S_CH, IPC_NOWAIT))
	{
		return 0;
	}
	
	MsgTx(_mqID, &rxMsg);
	
	return 1;
}





int main(int argc, char* argv[])
{
	int mqID;
	key_t mqKey;
	Params params;
	MsgBuf txMsg;
	MsgBuf rxMsg;
	size_t msgRxCount = 0;
	sem_t* clientSem;
	sem_t* serverSem;
	
	clientSem = sem_open(CSEM_NAME, O_CREAT, 0666, 0);
	serverSem = sem_open(SSEM_NAME, O_CREAT, 0666, 0);
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	ServerSignIn(serverSem);
	
	WaitForClientSignIn(clientSem);
	
	printf("Server starting to receive payload\n");

	while (IsClientSignedIn(clientSem) || IsMsgInQueue(mqID))
	{
		if (-1 == MsgRx(mqID, &rxMsg, C2S_CH, IPC_NOWAIT))
		{
			printf("No messages for server\n");
		}
		
		else
		{
			++msgRxCount;
			PrintMsg(&rxMsg, &params, "Server Rx", msgRxCount);
			
			InitServerMsg(&txMsg, rxMsg.m_data.m_pid, GEN_MSG);
		
			MsgTx(mqID, &txMsg);
			PrintMsg(&txMsg, &params, "Server Tx", msgRxCount);
		}
		
		usleep((unsigned int)params.m_speed);
	}
	
	printf("Server finished receiving %d messages\n", msgRxCount);
	
	ServerSignOut(mqID, serverSem, clientSem);

	return 0;
}



