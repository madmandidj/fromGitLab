#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../../Comms/Transmitter/Transmitter.h"
#include "../../Comms/Receiver/Receiver.h"
#include "../../DataGenerator/DataGenerator.h"
#include "../Reader/Reader.h"
#include "FeederManager.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



struct FeederManager
{
	Transmitter* 	m_trans;
	Receiver* 		m_rcvr;
	Reader*			m_reader;
};



FeederManager* FeederManagerCreate(size_t _numOfReaders)
{	
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
	
	feedMngr->m_reader = ReaderCreate(_numOfReaders,"./NewFileWatcher/WORKING/", feedMngr->m_trans, feedMngr->m_rcvr);
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



int main()
{
	FeederManager* feedMngr;
	size_t numOfReaders = 2;
		
	feedMngr = FeederManagerCreate(numOfReaders);
	
	printf("***Feeder***\n");
	
	printf("Running Feeder\n");
	
	ReaderRun(feedMngr->m_reader);

	FeederManagerDestroy(feedMngr);

	return 0;
}






