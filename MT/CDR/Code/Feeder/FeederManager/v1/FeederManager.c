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
	
/*	trans = TransmitterCreate("../../Comms/MsgQueue/MQ");*/
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





/*int FeederManagerSendCDR(FeederManager* _feedMngr, Record* _record)*/
/*{*/
/*	Msg _msg;*/
/*	*/
/*	if (!_feedMngr || !_record)*/
/*	{*/
/*		return 0;*/
/*	}*/
/*	*/
/*	_msg.m_channel = FEEDER_TO_PROCESSOR_CH;*/
/*	_msg.m_data = (char*)_record;*/
/*	*/
/*	TransmitterSend(_feedMngr->m_trans, &_msg, sizeof(Record), FEEDER_TO_PROCESSOR_CH);*/

/*	return 1;*/
/*}*/



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




int main()
{
	FeederManager* feedMngr;
/*	Record record = {"111111111111111", */
/*						"222222222222222",*/
/*						"333333333333333",*/
/*						"CellCom Israel",*/
/*						"123456",*/
/*						MOC,*/
/*						"17/01/1984",*/
/*						"23:59:59", */
/*						555, */
/*						666, */
/*						777, */
/*						"888888888888888",*/
/*						"654321"		 */
/*	};*/

	Data* data;
	
	
	data = malloc(sizeof(Data));
	
	
	GenerateRecord(&data->m_rec);
	
	
/*	Record* record;*/
/*	*/
/*	record = malloc(sizeof(Record));*/
/*	*/
/*	*/
/*	GenerateRecord(record);*/
	
	feedMngr = FeederManagerCreate();
	
/*	FeederManagerSendCDR(feedMngr, &record);*/

/*	FeederManagerSendCDR(feedMngr, record);*/

	FeederManagerSendCDR(feedMngr, *data);
	
	sleep(10);
	
	FeederManagerDestroy(feedMngr);

	return 0;
}












