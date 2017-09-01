#include "MyMsgQ.h"

#define FIVE_SECONDS_USEC 5000000

static int IsLastServer(int _mqID)
{
	MsgBuf msg;
	
	if (-1 == MsgRx(_mqID, &msg, S_ATND_CH, IPC_NOWAIT))
	{
		return 1;
	}
	
	MsgTx(_mqID, &msg);
	
	return 0;
}

static int IsClientSignedIn(int _mqID, Params* _params)
{
	MsgBuf rxMsg;
	
	if (-1 == MsgRx(_mqID, &rxMsg, C_ATND_CH, IPC_NOWAIT))
	{
		return 0;
	}
	
	MsgTx(_mqID, &rxMsg);
	
	return 1;
}





int main(int argc, char* argv[])
{
	int mqID;
	key_t mqKey;
	msqid_ds msqDs;
	Params params;
	
	DoGetOpt(argc, argv, &params);
	
	CreateMQ(&mqKey, &mqID, &params);
	
	while (!IsLastServer(mqID) || IsClientSignedIn(mqID, &params))
	{
		printf("Watchdog is watching\n");
		usleep(FIVE_SECONDS_USEC);
	}
	
	DeleteMQ(mqID, &msqDs);
	printf("Watchdog killed message queue\n");
	return 0;
}



