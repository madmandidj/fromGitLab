#include "PingPong.h"
#include "Package.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <assert.h>

#define SLEEP_TIME_DEF 100
#define MSG_NUM_DEF 10
#define FILE_NAME_SIZE 128

#define TRUE 1
#define FALSE 0
#define FAIL 1
#define SUCCESS 0

#define VERBOSE(condition, msg) if (condition) printf(msg)

/* ======================= */

typedef struct
{
	int m_verbosity;
	int m_workload;
	char m_fileName[FILE_NAME_SIZE];
	int m_msgNum;
}ClientParams;

void static InitClientParams(ClientParams* _clientParams)
{
	_clientParams->m_verbosity = FALSE;
	_clientParams->m_workload = SLEEP_TIME_DEF * 1000;
	strcpy (_clientParams->m_fileName, QUEUE_FILE);
	_clientParams->m_msgNum = MSG_NUM_DEF;
}

/* returns 1 if fails */
int SetArgs(int _argc, char** _argv, ClientParams* _clientParams)
{
    int opt;
    while ((opt = getopt(_argc, _argv, "vs:f:n:e:")) != -1)
    {
        switch(opt)
        {
            case 'v':
            	_clientParams->m_verbosity = TRUE;
            	break;
            case 's':
            	_clientParams->m_workload = 1000 * atoi(optarg);
            	break;
            case 'f':
            	strcpy(_clientParams->m_fileName, optarg);
            	break;
            case 'n':
                _clientParams->m_msgNum = atoi(optarg);
                break;
            default:
                perror("incorrect args\n");
                return 1;
        }
    }
    
    return 0;
}

/* ============================ */

typedef struct
{
    sem_t* m_clients;
    sem_t* m_servers;
}Semaphores;

void LinkSemaphores(Semaphores* _semaphores)
{
    _semaphores->m_clients = sem_open(CLIENTS_SEM, O_CREAT, 0666, 0);
    assert(NULL != _semaphores->m_clients);
    _semaphores->m_servers = sem_open(SERVERS_SEM, O_CREAT, 0666, 0);
    assert(NULL != _semaphores->m_servers);
}

void UnlinkSemaphores(Semaphores* _semaphores)
{
    sem_unlink(CLIENTS_SEM);
    sem_unlink(SERVERS_SEM);
}

/* ======================= */

void InitMidiMsg(MidiMsg* _msg)
{
    _msg->m_type = PING_CHANNEL;
	_msg->m_pid = getpid();
	_msg->m_channel = (char)(rand()%16);
	_msg->m_note = (char)(rand()%128);
	_msg->m_velocity = (char)(rand()%128);
}

void SignIn(Semaphores* _semaphores, int _verbosity)
{
    int err;
    
    err = sem_post(_semaphores->m_clients);
    assert(-1 != err);
    
    if (_verbosity)
    {
        printf("signed in\n");
    }
}

void SignOut(Semaphores* _semaphores, int _verbosity)
{
    int err;
    
    err = sem_trywait(_semaphores->m_clients);
    assert(-1 != err);
    
    if (_verbosity)
    {
        printf("signed out\n");
    }
}

int SendToServers(int _mqid, Semaphores* _semaphores, ClientParams* _clientParams)
{
	Package pkg;
	MidiMsg noteOn;
	PongMsg pongMsg;
	int i;
    
	for (i = 0 ; i < _clientParams->m_msgNum ; ++i)
	{
        VERBOSE(_clientParams->m_verbosity, "build message...\n");
		usleep((useconds_t)_clientParams->m_workload);
		InitMidiMsg(&noteOn);
        
        PackageSet(&pkg, _mqid, PING_CHANNEL, &noteOn, sizeof(MidiMsg));
        if(MSG_ERROR == PackageSend(&pkg, "ping", _clientParams->m_verbosity))
        {
        	break;
        }
		
		PackageSet(&pkg, _mqid, getpid(), &pongMsg, sizeof(PongMsg));
		if (MSG_ERROR == PackageReceive(&pkg, "Pong", _clientParams->m_verbosity))
        {
            break;
        }
	}
    return i;
}

static int InitQueue(char* _queueFile, int* _mqid)
{
    key_t key;
    
    if ((key = ftok(_queueFile, 0)) == -1)
    {
        perror("cannot find key\n");
        return FAIL;
    }
    
    *_mqid = msgget(key, IPC_CREAT | 0666);
    
    if (-1 == *_mqid)
    {
        perror("get queue failed\n");
        return FAIL;
    }
    return SUCCESS;
}

/* =================== */

int main(int argc, char** argv)
{
    Semaphores semaphores;
	ClientParams clientParams;
    int mqid;
    int msgs;
    
    InitClientParams(&clientParams);
    if (SetArgs(argc, argv, &clientParams))
    {
        return 1;
    }
    
    if (InitQueue(clientParams.m_fileName, &mqid))
    {
        return 1;
    }
    
    LinkSemaphores(&semaphores);
    SignIn(&semaphores, clientParams.m_verbosity);
    
    printf("sending messages...\n");
    msgs = SendToServers(mqid, &semaphores, &clientParams);
    printf("%d/%d messages were successfuly delivered.\n", msgs, clientParams.m_msgNum);
    
    SignOut(&semaphores, clientParams.m_verbosity);
    UnlinkSemaphores(&semaphores);
}
