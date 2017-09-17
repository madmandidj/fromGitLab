#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "../MsgQueue/MsgQ.h"

typedef struct Receiver Receiver;


Receiver* ReceiverCreate(char* _myPathToMsgQ);


void ReceiverDestroyAndDisconnect(Receiver* _rcvr);

void ReceiverDestroy(Receiver* _rcvr);


/* int flag e.g. IPC_NOWAIT */
ssize_t ReceiverReceive(Receiver* _rcvr, Msg* _msg, size_t _msgSize, int _channel, int _flag);





#endif /* #ifndef __RECEIVER_H__ */
