#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "../MsgQueue/MsgQ.h"

typedef struct Receiver Receiver;


Receiver* ReceiverCreate();


void ReceiverDestroy(Receiver* _rcvr);


int ReceiverSend(Receiver* _rcvr, Msg* _msg, size_t _msgSize, int _channel, int _flag);





#endif /* #ifndef __RECEIVER_H__ */
