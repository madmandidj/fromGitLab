#ifndef __SINGLE_MSG_Q_H__
#define __SINGLE_MSG_Q_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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
    long 	m_type;
    Data 	m_data;
}MsgBuf;





#endif /* #ifndef __SINGLE_MSG_Q_H__ */
