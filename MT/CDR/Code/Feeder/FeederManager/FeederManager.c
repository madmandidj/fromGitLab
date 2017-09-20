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



void DoGetOptFeeder(int _argc, char* _argv[], FeederParams* _params)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "n:")) != -1) {
	   switch (opt) 
	   {
		case 'n':
			_params->m_numOfReaders = (size_t)atoi(optarg);
		   break;
		   
		default: 
		fprintf(stderr, "Usage: %s [-n num of readers]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
   
	return;
}



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



int main(int argc, char* argv[])
{
	FeederManager* feedMngr;
	FeederParams params;
/*	size_t numOfReaders = 2;*/

	DoGetOptFeeder(argc, argv, &params);
		
/*	feedMngr = FeederManagerCreate(numOfReaders);*/
	feedMngr = FeederManagerCreate(params.m_numOfReaders);
	
	printf("***Feeder***\n");
	
	printf("Running Feeder\n");
	
	ReaderRun(feedMngr->m_reader);

	FeederManagerDestroy(feedMngr);

	return 0;
}






