#include "Receiver.h"
#include <stdlib.h>


struct Receiver
{
	key_t 		m_queueKey;
	int 		m_queueID;
	msqid_ds*	m_queueStats;
};





Receiver* ReceiverCreate(char* _myPathToMsgQ)
{
	Receiver* rcvr;
	
	rcvr = malloc(sizeof(Receiver));
	if (!rcvr)
	{
		return NULL;
	}
	
	MsgQCreate(&rcvr->m_queueKey, &rcvr->m_queueID, _myPathToMsgQ);
	
	return rcvr;
}





void ReceiverDestroy(Receiver* _rcvr)
{
	if (!_rcvr)
	{
		return;
	}
	
	MsgQDestroy(_rcvr->m_queueID, _rcvr->m_queueStats);
	free(_rcvr);

	return;
}





int ReceiverReceive(Receiver* _rcvr, Msg* _msg, size_t _msgSize, int _channel, int _flag)
{
	if (!_rcvr)
	{
		return 0;
	}
	
	MsgQReceive(_rcvr->m_queueID, _msg, _msgSize, _channel, _flag);

	return 1;
}










