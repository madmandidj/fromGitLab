#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../../Comms/Transmitter/Transmitter.h"
#include "../../Comms/Receiver/Receiver.h"
#include "../../DataGenerator/DataGenerator.h"
#include "../Reader/Reader.h"
#include "FeederManager.h"
#include <unistd.h>
#include <stdlib.h>



struct FeederManager
{
	Transmitter* 	m_trans;
	Receiver* 		m_rcvr;
	Reader*			m_reader;
};



FeederManager* FeederManagerCreate()
{
/*	Transmitter* trans;*/
/*	Receiver* rcvr;*/
/*	Reader* reader;*/
	FeederManager* feedMngr;
	
	
	
	feedMngr = malloc(sizeof(FeederManager));
	if (!feedMngr)
	{
		return NULL;
	}
	
	feedMngr->m_trans = TransmitterCreate("../Comms/MsgQueue/MQ");
	if (!feedMngr->m_trans)
	{
		free(feedMngr);
		return NULL;
	}
	
	feedMngr->m_rcvr = ReceiverCreate("../Comms/MsgQueue/MQ");
	if (!feedMngr->m_trans)
	{
		TransmitterDestroy(feedMngr->m_trans);
		free(feedMngr);
		return NULL;
	}
	
	feedMngr->m_reader = ReaderCreate(1/*TODO:make this param*/,"./Reader/WORKING/TestCDRFile.cdr", feedMngr->m_trans, feedMngr->m_rcvr);
	if(!feedMngr->m_reader)
	{
		ReceiverDestroy(feedMngr->m_rcvr);
		TransmitterDestroy(feedMngr->m_trans);
		free(feedMngr);
		return NULL;
	}
	
	return feedMngr;
}





void FeederManagerDestroy(FeederManager* _feedMngr)
{
	if (!_feedMngr)
	{
		return;
	}
	
	ReaderDestroy(_feedMngr->m_reader);
	ReceiverDestroy(_feedMngr->m_rcvr);
	TransmitterDestroy(_feedMngr->m_trans);
	free(_feedMngr);

	return;
}





int FeederManagerSendCDR(FeederManager* _feedMngr, Data _data)
{
	Msg msg;
	
	if (!_feedMngr)
	{
		return 0;
	}
	
	msg.m_channel = FEEDER_TO_PROCESSOR_CH;
	msg.m_data = _data;
	
	TransmitterSend(_feedMngr->m_trans, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH);

	return 1;
}







int main()
{
	FeederManager* feedMngr;
/*	Data data;*/
/*	size_t index;*/
/*	size_t reps = 1000;*/
	
	feedMngr = FeederManagerCreate();
	
/*	for (index = 0; index < reps; ++index)*/
/*	{*/
/*		GenerateRecord(&data.m_rec);*/

/*		FeederManagerSendCDR(feedMngr, data);*/
/*	}*/
/*	*/
/*	sleep(5);*/

	ReaderRun(feedMngr->m_reader);

	
	
	FeederManagerDestroy(feedMngr);

	return 0;
}












