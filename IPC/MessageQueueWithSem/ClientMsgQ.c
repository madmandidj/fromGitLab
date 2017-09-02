#include "MyMsgQ.h"

static void InitClientMsg(MsgBuf* _txMsg, int _msgChannel, int _msgType)
{
	_txMsg->m_channel = _msgChannel;
	_txMsg->m_data.m_pid = getpid();

	switch (_msgType)
	{
		case GEN_MSG:
			_txMsg->m_data.m_status = 0;
			_txMsg->m_data.m_data1 = 0;
			_txMsg->m_data.m_data2 = 0;
			break;
			
		default:
			_txMsg->m_data.m_status = 3;
			_txMsg->m_data.m_data1 = 3;
			_txMsg->m_data.m_data2 = 3;	
	}
	
	return;
}




static void ClientSignIn(sem_t* _sem)
{
	sem_post(_sem);
	
	printf("Client has signed in\n");
	
	return;
}






static void ClientSignOut(sem_t* _sem)
{
	sem_wait(_sem);
	
	printf("Client has signed out\n");
	
	return;
}





static void DeliverClientPayload(int _mqID, Params* _params)
{
	size_t index;
	MsgBuf txMsg;
	MsgBuf rxMsg;
	size_t numOfMsgRx = 0; 
	
	printf("Client starting payload delivery\n");
	
	for (index = 0; index < _params->m_numOfMsgs; ++index)
	{
		InitClientMsg(&txMsg, C2S_CH, GEN_MSG);
		
		MsgTx(_mqID, &txMsg);
		
		PrintMsg(&txMsg, _params, "Client Tx", index);
		
		MsgRx(_mqID, &rxMsg, getpid(), 0);
		
		PrintMsg(&rxMsg, _params, "Client Rx", numOfMsgRx++);
		
		usleep((size_t)_params->m_speed);
		
	}
	
	printf("Client finished sending %d messages\n", index);
	
	return;
}






int main(int argc, char* argv[])
{
	int mqID;
	key_t mqKey;
	Params params;
	sem_t* clientSem;
	
	clientSem = sem_open(CSEM_NAME, O_CREAT, 0666, 0);
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	ClientSignIn(clientSem);
	
	DeliverClientPayload(mqID, &params);
	
	ClientSignOut(clientSem);

	return 0;
}















