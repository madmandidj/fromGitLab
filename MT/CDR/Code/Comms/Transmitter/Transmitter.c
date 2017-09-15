#include "Transmitter.h"
#include <stdlib.h>


struct Transmitter
{
	key_t 		m_queueKey;
	int 		m_queueID;
	msqid_ds*	m_queueStats;
};





Transmitter* TransmitterCreate(char* _myPathToMsgQ)
{
	Transmitter* trans;
	
	trans = malloc(sizeof(Transmitter));
	if (!trans)
	{
		return NULL;
	}
	
	MsgQCreate(&trans->m_queueKey, &trans->m_queueID, _myPathToMsgQ);
	
	return trans;
}





void TransmitterDestroy(Transmitter* _trans)
{
	if (!_trans)
	{
		return;
	}
	
	MsgQDestroy(_trans->m_queueID, _trans->m_queueStats);
	free(_trans);

	return;
}





int TransmitterSend(Transmitter* _trans, Msg* _msg, size_t _msgSize, int _channel)
{
	if (!_trans)
	{
		return 0;
	}
	
	MsgQTransmit(_trans->m_queueID, _msg, _msgSize, _channel);

	return 1;


}










