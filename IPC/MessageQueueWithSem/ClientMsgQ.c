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




static void ClientSignIn(sem_t* _sem, sem_t* _signSem)
{
	
	sem_wait(_signSem);
	
	sem_post(_sem);
	
	printf("Client has signed in\n");
	
	sem_post(_signSem);
	
	return;
}






static void ClientSignOut(sem_t* _sem, sem_t* _signSem)
{

	sem_wait(_signSem);

	sem_wait(_sem);
	
	sem_unlink(CSEM_NAME);
	
	printf("Client has signed out\n");
	
	sem_post(_signSem);
	
	sem_unlink(SIGN_INOUT);
	
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
	sem_t* signSem;
	
	clientSem = sem_open(CSEM_NAME, O_CREAT, 0666, 0);
	
	signSem = sem_open(SIGN_INOUT, O_CREAT, 0666, 1);
	
	
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	ClientSignIn(clientSem, signSem);
	
	DeliverClientPayload(mqID, &params);
	
	ClientSignOut(clientSem, signSem);

	return 0;
}















