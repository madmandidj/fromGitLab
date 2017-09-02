#ifndef __MY_MSG_Q_H__
#define __MY_MSG_Q_H__
#define _GNU_SOURCE

#define ONE_SECOND_USEC 1000000
#define TEN_SECOND_USEC 10000000
#define ERR_VAL -1
#define NUM_OF_LETTERS 26
#define LOWER_A_ASCI 97
#define MSG_SIZE 64
#define TX_PRINT 0
#define RX_PRINT 1
#define C2S_CH 1
#define GEN_MSG 0

#define CSEM_NAME "myCSem"
#define SSEM_NAME "mySSem"
#define SIGN_INOUT "inOutSem"


#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct msqid_ds msqid_ds;

typedef struct Data
{
	pid_t 	m_pid;
	int 	m_status;
	int 	m_data1;
	int 	m_data2;
}Data;

typedef struct MsgBuf
{
    long 	m_channel;
    Data 	m_data;
}MsgBuf;

typedef struct Params
{
	int 		m_createMQFlag;
	int 		m_deleteMQFlag;
	int 		m_numOfMsgs;
	int 		m_eofMode;
	int 		m_verbosityMode;
	int 		m_speed;
	char* 		m_ftokFilename;
}Params;




void DoGetOpt(int _argc, char* _argv[], Params* _params);

void CreateMQ(key_t* _mqKey, int* _mqID, Params* _params);

void DeleteMQ(int _mqID, msqid_ds* _msqDs);

int MsgTx(int mqID, MsgBuf* _txMsg);

ssize_t MsgRx(int _mqID, MsgBuf* _rxMsg, int _channel, int _flag);

void PrintMsg(MsgBuf* _msgBuf, Params* _params, char* _printerStr, size_t index);














#endif /* #ifndef __MY_MSG_Q_H__ */
