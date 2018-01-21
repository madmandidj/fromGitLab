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


#include <stdio.h>			/* printf */
#include <sys/types.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <sys/ipc.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <sys/msg.h>		/* msgrcv, msgsnd, msgget, msgctl */
#include <unistd.h>			/* getpid, usleep, getopt */
#include <errno.h>			/* errno */
#include <stdlib.h>			/* atoi, exit */
#include <string.h>			/* strerr */
#include <fcntl.h>			/* O_CREAT */
#include <semaphore.h>		/* sem_t, sem_open */

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



/**
*	@brief Get main function input arguments, and set program parameters accordingaly
*
*
*
*/
void DoGetOpt(int _argc, char* _argv[], Params* _params);


/**
*	@brief Create or join and message queue
*	
*	@warning Errors are handled internally
*
*/
void CreateMQ(key_t* _mqKey, int* _mqID, Params* _params);


/**
*	@brief Delete message queue
*
*	TODO : Handle errors 
*
*/
void DeleteMQ(int _mqID, msqid_ds* _msqDs);


/**
*	@brief Transmit message through message queue. 
*
*	@param[in] int - message queue ID
*
*	@param[in] MsgBuf* - message to transmit. Tx channel is set in m_channel member
*
*	@retval 0 - on success
*
*	@retval -1 - on failure
*
*/
int MsgTx(int mqID, MsgBuf* _txMsg);


/**
*	@brief Receive message through message queue. 
*
*	@param[in] int - message queue ID
*
*	@param[in] MsgBuf* - message to receive.
*
*	@param[in] int - message channel (Note: can also be negative. look at msgrcv doc))
*
*	@param[in] int - flag (e.g. IPC_NOWAIT)
*
*	@retval >= 0 - on success returns number of bytes transmitted
*
*	@retval -1 - on failure
*
*/
ssize_t MsgRx(int _mqID, MsgBuf* _rxMsg, int _channel, int _flag);


/**
*	@brief Print a message to stdout in Client/Server format
*
*
*
*/
void PrintMsg(MsgBuf* _msgBuf, Params* _params, char* _printerStr, size_t index);














#endif /* #ifndef __MY_MSG_Q_H__ */



