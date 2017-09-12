#ifndef __MSGQ_H__
#define __MSGQ_H__

#define _GNU_SOURCE

#include "MsgType.h"
#include <sys/types.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <sys/ipc.h>		/* msgrcv, msgsnd, msgget, msgctl */



typedef struct msqid_ds msqid_ds;

//typedef struct Msg Msg;



void MsgQCreate(key_t* _mqKey, int* _mqID);



void MsgQDestroy(int _mqID, msqid_ds* _msqDs);



int MsgQTransmit(int mqID, Msg* _txMsg, size_t _msgSize, int _channel);



ssize_t MsgQReceive(int _mqID, Msg* _rxMsg, size_t _msgSize, int _channel, int _flag);



#endif /* #ifndef __MSGQ_H__ */



