#include "MyMsgQ.h"

static void InitClientMsg(MsgBuf* _txMsg, int _msgChannel, int _msgType)
{
	_txMsg->m_channel = _msgChannel;
	_txMsg->m_data.m_pid = getpid();
	/* _txMsg->m_data.m_pid_receiver = _pidTarget; */
	
	switch (_msgType)
	{
		case GEN_MSG:
			_txMsg->m_data.m_status = 0;
			_txMsg->m_data.m_data1 = 0;
			_txMsg->m_data.m_data2 = 0;
			break;
			
		case EOW_MSG:
			_txMsg->m_data.m_status = 1;
			_txMsg->m_data.m_data1 = 1;
			_txMsg->m_data.m_data2 = 1;
			break;
			
		case ATND_MSG:
			_txMsg->m_data.m_status = 2;
			_txMsg->m_data.m_data1 = 2;
			_txMsg->m_data.m_data2 = 2;
			break;
			
		default:
			_txMsg->m_data.m_status = 3;
			_txMsg->m_data.m_data1 = 3;
			_txMsg->m_data.m_data2 = 3;
		
	}
	
	return;
}









static void ClientSignIn(int _mqID, Params* _params)
{
	MsgBuf txMsg;
	
	InitClientMsg(&txMsg, C_ATND_CH, ATND_MSG);
	
	MsgTx(_mqID, &txMsg);
	
	PrintMsg(&txMsg, _params, "Client sign in", 1);
	
	return;
}


static void ClientSignOut(int _mqID, Params* _params)
{
	MsgBuf rxMsg;
	
	MsgRx(_mqID, &rxMsg, C_ATND_CH, 0);
	
	PrintMsg(&rxMsg, _params, "Client sign out", 1);
	
	return;
}



/*

static size_t GetActiveServers(int _mqID, pid_t* _pidArr)
{
	MsgBuf* msg[64];
	size_t numOfServers = 0;
	size_t index;
	
	while (-1 != MsgRx(_mqID, &msg[numOfServers], S_ATND_CH, IPC_NOWAIT))
	{
		_pidArr[numOfServers] = msg[numOfServers]->m_pid_receiver;
		++numOfServers;
	}
	
	for(index = 0; index < numOfServers; ++index)
	{
		MsgTx(_mqID, &msg[index], msg[index]->m_pid_receiver);
	}
	
	return numOfServers;
}

*/





static void DeliverClientPayload(int _mqID, Params* _params)
{
	size_t index;
	MsgBuf txMsg;
	MsgBuf rxMsg;
	size_t numOfMsgRx = 0; 
	
	for (index = 0; index < _params->m_numOfMsgs; ++index)
	{
		
		InitClientMsg(&txMsg, C2S_CH, GEN_MSG);
		
		MsgTx(_mqID, &txMsg);
		
		PrintMsg(&txMsg, _params, "Client Tx", index);
		
		MsgRx(_mqID, &rxMsg, getpid(), 0);
		
		PrintMsg(&rxMsg, _params, "Client Rx", numOfMsgRx++);
		
		usleep((size_t)_params->m_speed);
		
	}
	return;
}




















int main(int argc, char* argv[])
{
	int mqID;
	key_t mqKey;
	Params params;
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	ClientSignIn(mqID, &params);
	
	/*
	numOfServers = GetActiveServers(mqID, serverPidArr);
	*/
	
	DeliverClientPayload(mqID, &params);
	
	ClientSignOut(mqID, &params);
	
	/*
	
	Connect to MQ
	Sign In
	Wait for servers to sign in
	Get all active servers pids
	Deliver payload
	Sign out
	
	
	*/
	
	
	
	/*
	
	DoGetOpt(argc, argv, &params);
	
	if (1 == params.m_createMQFlag)
	{
		CreateMQ(&mqKey, &mqID, &params);
	}
	
	
	
	InitClientMsg(&txMsg, C_ATND_CH, ATND_MSG);
	
	ClientSignIn(mqID, &txMsg, &params);
	
	InitClientMsg(&txMsg, C2S_CH, GEN_MSG);
	
	ClientDeliverPayload(mqID, &txMsg, &params);
	
	printf("Client done\n");
	
	*/

	return 0;
}















