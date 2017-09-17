#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../../Comms/Transmitter/Transmitter.h"
#include "../../DataGenerator/DataGenerator.h"
#include "FeederManager.h"
#include <unistd.h>
#include <stdlib.h>



struct FeederManager
{
	Transmitter* m_trans;
	
	
	
	
};







FeederManager* FeederManagerCreate()
{
	Transmitter* trans;
	FeederManager* feedMngr;
	
	trans = TransmitterCreate("../Comms/MsgQueue/MQ");
	if (!trans)
	{
		return NULL;
	}
	
	feedMngr = malloc(sizeof(FeederManager));
	if (!feedMngr)
	{
		TransmitterDestroy(trans);
		return NULL;
	}
	
	feedMngr->m_trans = trans;

	return feedMngr;
}



void FeederManagerDestroy(FeederManager* _feedMngr)
{
	if (!_feedMngr)
	{
		return;
	}
	
	TransmitterDestroy(_feedMngr->m_trans);
	free(_feedMngr);

	return;
}





int FeederManagerSendCDR(FeederManager* _feedMngr, Data _data)
{
	Msg msg;
	
/*	if (!_feedMngr || !_data)*/
	if (!_feedMngr)
	{
		return 0;
	}
	
	msg.m_channel = FEEDER_TO_PROCESSOR_CH;
	msg.m_data = _data;
	
	TransmitterSend(_feedMngr->m_trans, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH);

	return 1;
}




/*int main()*/
/*{*/
/*	FeederManager* feedMngr;*/
/*	Data* data;*/
/*	*/
/*	*/
/*	data = malloc(sizeof(Data));*/
/*	*/
/*	GenerateRecord(&data->m_rec);*/
/*	*/
/*	feedMngr = FeederManagerCreate();*/

/*	FeederManagerSendCDR(feedMngr, *data);*/
/*	*/
/*	sleep(5);*/
/*	*/
/*	FeederManagerDestroy(feedMngr);*/

/*	return 0;*/
/*}*/



int main()
{
	FeederManager* feedMngr;
	Data data;
	size_t index;
	size_t reps = 1000;
	
	
/*	data = malloc(sizeof(Data));*/
	
	
	
	feedMngr = FeederManagerCreate();
	
	for (index = 0; index < reps; ++index)
	{
		GenerateRecord(&data.m_rec);

		FeederManagerSendCDR(feedMngr, data);
	}
	
	sleep(5);
	
	FeederManagerDestroy(feedMngr);

	return 0;
}












