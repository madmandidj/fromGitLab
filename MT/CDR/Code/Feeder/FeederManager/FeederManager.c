#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include "../../Comms/Transmitter/Transmitter.h"
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
	
	trans = TransmitterCreate();
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





int FeederManagerSendCDR(FeederManager* _feedMngr, Record* _record)
{
	Msg _msg;
	
	if (!_feedMngr || !_record)
	{
		return 0;
	}
	
	_msg.m_channel = FEEDER_TO_PROCESSOR_CH;
	_msg.m_data = _record;
	
	TransmitterSend(_feedMngr->m_trans, &_msg, sizeof(Record), FEEDER_TO_PROCESSOR_CH);

	return 1;
}





int main()
{
	FeederManager* feedMngr;
	Record record = {"111111111111111", 
						"222222222222222",
						"333333333333333",
						"CellCom Israel",
						123456,
						MOC,
						"17/01/1984",
						444, 
						555, 
						666, 
						777, 
						"888888888888888",
						654321		 
	};
	
	
	feedMngr = FeederManagerCreate();
	
	FeederManagerSendCDR(feedMngr, &record);
	
	sleep(5);
	
	FeederManagerDestroy(feedMngr);

	return 0;
}












