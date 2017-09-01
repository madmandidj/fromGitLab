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
			
		case EOW_MSG:
			_txMsg->m_data.m_status = 11;
			_txMsg->m_data.m_data1 = 11;
			_txMsg->m_data.m_data2 = 11;
			break;
			
		case ATND_MSG:
			_txMsg->m_data.m_status = 12;
			_txMsg->m_data.m_data1 = 12;
			_txMsg->m_data.m_data2 = 12;
			break;
			
		default:
			_txMsg->m_data.m_status = 13;
			_txMsg->m_data.m_data1 = 13;
			_txMsg->m_data.m_data2 = 13;
	}
	
	return;
}





static void ServerSignIn(int _mqID, Params* _params)
{
	MsgBuf txMsg;
	
	InitServerMsg(&txMsg, S_ATND_CH, ATND_MSG);
	
	MsgTx(_mqID, &txMsg);
	
	PrintMsg(&txMsg, _params, "Server sign in", 1);
	
	return;
}





static void ServerSignOut(int _mqID, Params* _params)
{
	MsgBuf rxMsg;
	
	MsgRx(_mqID, &rxMsg, S_ATND_CH, 0);
	
	PrintMsg(&rxMsg, _params, "Server sign out", 1);
	
	return;
}





static void WaitForClientSignIn(int _mqID, Params* _params)
{
	MsgBuf rxMsg;
	
	MsgRx(_mqID, &rxMsg, C_ATND_CH, 0);
	
	PrintMsg(&rxMsg, _params, "Server Rx", 1);
	
	MsgTx(_mqID, &rxMsg);
	
	return;
}





static int IsClientSignedIn(int _mqID, Params* _params)
{
	MsgBuf rxMsg;
	
	if (-1 == MsgRx(_mqID, &rxMsg, C_ATND_CH, IPC_NOWAIT))
	{
		return 0;
	}
	
	MsgTx(_mqID, &rxMsg);
	
	return 1;
}





static int IsMsgForMe(int _mqID)
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
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	ServerSignIn(mqID, &params);
	
	WaitForClientSignIn(mqID, &params);
	
	while (IsClientSignedIn(mqID, &params) || IsMsgForMe(mqID))
	{
		if (-1 == MsgRx(mqID, &rxMsg, C2S_CH, IPC_NOWAIT))
		{
			printf("No messages for server\n");
		}
		else
		{
			++msgRxCount;
			PrintMsg(&rxMsg, &params, "Server Rx", msgRxCount);
		}
		
		InitServerMsg(&txMsg, rxMsg.m_data.m_pid, GEN_MSG);
		
		MsgTx(mqID, &txMsg);
		
		usleep((unsigned int)params.m_speed);
	}
	
	ServerSignOut(mqID, &params);

	return 0;
}



