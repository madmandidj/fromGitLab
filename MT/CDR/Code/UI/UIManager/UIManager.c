#include "UIManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	
	TransmitterDestroyAndDisconnect(_uiMngr->m_trans);
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
	int isRun = 1;
	int queryType;
	char queryValStr[32];
	
	uiMngr = UIManagerCreate();
	
	printf("***User Interface***\n");
	
	while(isRun)
	{
		printf("1:\tSubscriber query\n2:***\tOperator query\n3:\tAll Subscribers query\n4:***\tAll Operators query\n5:***\tPause\n6:***\tResume\n0:\tShutdown\n");
		scanf("%d", &queryType);
		printf("\n");
		
		switch (queryType)
		{
			case SUBSCRIBER_QUERY:
			
				printf("Enter subscriber MSISDN\n");
				scanf("%s", queryValStr);
				printf("\n");
				data.m_uiCommand.m_command = SUBSCRIBER_QUERY;
				strcpy(data.m_uiCommand.m_searchKey, queryValStr);
				UIManagerSendCommand(uiMngr, data, UI_TO_PROCESSOR);
				
				break;
			
			case OPERATOR_QUERY:
				
				break;
			
			case ALL_SUBSCRIBERS_QUERY:
			
				data.m_uiCommand.m_command = ALL_SUBSCRIBERS_QUERY;
				UIManagerSendCommand(uiMngr, data, UI_TO_PROCESSOR);
				printf("\n");
				break;
				
			case ALL_OPERATORS_QUERY:
				
				break;
				
			case PAUSE:
				
				break;
				
			case RESUME:
				
				break;
				
			case SHUTDOWN:
				data.m_uiCommand.m_command = SHUTDOWN;
				isRun = 0;
				break;
		}
	}
	
	UIManagerSendCommand(uiMngr, data, UI_TO_PROCESSOR);
	UIManagerSendCommand(uiMngr, data, UI_TO_FEEDER);
	
	sleep(1);
	
	UIManagerDestroy(uiMngr);
	
	return 0;
}


