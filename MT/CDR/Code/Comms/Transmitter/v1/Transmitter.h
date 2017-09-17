#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include "../MsgQueue/MsgQ.h"

typedef struct Transmitter Transmitter;


Transmitter* TransmitterCreate();

void TransmitterDestroy(Transmitter* _trans);

int TransmitterSend(Transmitter* _trans, Msg* _msg, size_t _msgSize, int _channel);



#endif /* #ifndef __TRANSMITTER_H__ */