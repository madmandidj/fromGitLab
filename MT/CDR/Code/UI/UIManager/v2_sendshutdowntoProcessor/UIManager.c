#include "UIManager.h"
#include <stdlib.h>
#include <unistd.h>

#include "../../Comms/ChannelDefs/ChannelDefs.h"




struct UIManager
{
	Transmitter* m_trans;
};


UIManager* UIManagerCreate()
{
	UIManager* uiMngr;
	
	uiMngr = malloc(sizeof(UIManager));
	if (!uiMngr)
	{
		return NULL;
	}
	
	uiMngr->m_trans = TransmitterCreate("../Comms/MsgQueue/MQ");
	if (!uiMngr->m_trans)
	{
		free(uiMngr);
		return NULL;
	}
	
	return uiMngr;
}


void UIManagerDestroy(UIManager* _uiMngr)
{
	if (!_uiMngr)
	{
		return;
	}
	
	TransmitterDestroy(_uiMngr->m_trans);
	free(_uiMngr);
	
	return;
}







int UIManagerSendCommand(UIManager* _uiMngr, Data _data, int _channel)
{
	Msg msg;
	
	if (!_uiMngr)
	{
		return 0;
	}
	
	msg.m_channel = _channel;
	msg.m_data = _data;
	
	TransmitterSend(_uiMngr->m_trans, &msg, sizeof(Data), _channel);

	return 1;


}











int main()
{
	UIManager* uiMngr;
	Data data = {0};
	
	data.m_uiCommand.m_command = 666;
	
	uiMngr = UIManagerCreate();
	
	sleep(1);
	
	UIManagerSendCommand(uiMngr, data, UI_TO_PROCESSOR);
	
	return 0;
}


