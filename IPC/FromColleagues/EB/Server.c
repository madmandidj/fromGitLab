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
#define HOLDING_TIME 100000
#define MAX_WAIT 10000000

#define TRUE 1
#define FALSE 0

#define FAIL 1
#define SUCCESS 0

#define VERBOSE(condition, msg) if (condition) printf(msg)

/* ============================ */

typedef struct
{
	int m_verbosity;
	int m_workload;
	char m_fileName[FILE_NAME_SIZE];
}ServerParams;

void static InitServerParams(ServerParams* _serverParams)
{
    _serverParams->m_verbosity = FALSE;
    _serverParams->m_workload = 1000 * SLEEP_TIME_DEF;
    strcpy (_serverParams->m_fileName, QUEUE_FILE);
}

/* returns 1 if fails */
int SetArgs(int _argc, char** _argv, ServerParams* _serverParams)
{
    int opt;
    while ((opt = getopt(_argc, _argv, "cdvs:f:n:e:")) != -1)
    {
        switch(opt)
        {
            case 'v':
                _serverParams->m_verbosity = TRUE;
                break;
            case 's':
                _serverParams->m_workload = 1000 * atoi(optarg);
                break;
            case 'f':
                strcpy(_serverParams->m_fileName, optarg);
                break;
            default:
                return FAIL;
        }
    }
    
    return SUCCESS;
}


/* ============================ */

typedef struct
{
    sem_t* m_clients;
    sem_t* m_servers;
    sem_t* m_destroy;
}Semaphores;

void LinkSemaphores(Semaphores* _semaphores)
{
    _semaphores->m_clients = sem_open(CLIENTS_SEM, O_CREAT, 0666, 0);
    assert(NULL != _semaphores->m_clients);
    _semaphores->m_servers = sem_open(SERVERS_SEM, O_CREAT, 0666, 0);
    assert(NULL != _semaphores->m_servers);
    _semaphores->m_destroy = sem_open(DESTROY_SEM, O_CREAT, 0666, 1);
    assert(NULL != _semaphores->m_destroy);
}

void UnlinkSemaphores(Semaphores* _semaphores)
{
    sem_unlink(CLIENTS_SEM);
    sem_unlink(SERVERS_SEM);
    sem_unlink(DESTROY_SEM);
}

/* ============================== */

int HandlePackage(Package* _pkg, ServerParams* _serverParams)
{
    PongMsg pongMsg;
    MidiMsg* msg;
    
    msg = (MidiMsg*)_pkg->m_msg;
    
    VERBOSE(_serverParams->m_verbosity, "process message...\n");
    usleep((useconds_t)_serverParams->m_workload);

    if (_serverParams->m_verbosity)
    {
        printf("ping received from %d\n", msg->m_pid);
        printf("channel: %d, note: %d, velocty: %d\n", msg->m_channel, msg->m_note, msg->m_velocity);
    }
    
    PackageSet(_pkg, _pkg->m_qid, msg->m_pid, &pongMsg, sizeof(PongMsg));
    return PackageSend(_pkg, "send pong", _serverParams->m_verbosity);
}

int CheckForClients(sem_t* _clientsSem, int _verbosity)
{
    int clientCount;
    sem_getvalue(_clientsSem, &clientCount);
    if (0 == clientCount)
    {
        VERBOSE((_verbosity), "finished reading\n");
        return 1;
    }
    else
    {
        VERBOSE(_verbosity, "sleeping...\n");
        usleep(HOLDING_TIME);
        return 0;
    }
}

int ListenToClients(int _mqid, Semaphores* _semaphores, ServerParams* _serverParams)
{
    int shouldExit = FALSE;
	MidiMsg noteMsg;
    Package pkg;
    MsgErr msgErr;
    int totalMsgs = 0;
    
	while(!shouldExit)
	{
        PackageSet(&pkg, _mqid, PING_CHANNEL, &noteMsg, sizeof(MidiMsg));
        msgErr = PackageReceiveAsync(&pkg, "get ping", _serverParams->m_verbosity);
    
        switch(msgErr)
        {
            case MSG_ERROR:
                shouldExit = TRUE;
                break;
            case MSG_EMPTY_Q:
                shouldExit = CheckForClients(_semaphores->m_clients, _serverParams->m_verbosity);
                break;
            default:
                /* process and send pong */
                shouldExit = HandlePackage(&pkg, _serverParams);
                ++totalMsgs;
        }
	}
    return totalMsgs;
}

/* ============================== */

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

void SignIn(Semaphores* _semaphores, int _verbosity)
{
    int err;
    
    err = sem_post(_semaphores->m_servers);
    assert(-1 != err);
    
    VERBOSE(_verbosity, "signed in\n");
}

void SignOut(int _mqid, Semaphores* _semaphores, int _verbosity)
{
    int postValue;
    int err;
    
    err = sem_wait(_semaphores->m_destroy);
    assert(-1 != err);
    
    err = sem_trywait(_semaphores->m_servers);
    assert(-1 != err);
    
    err = sem_getvalue(_semaphores->m_servers, &postValue);
    assert(-1 != err);
    
    err = sem_post(_semaphores->m_destroy);
    assert(-1 != err);
    
    VERBOSE(_verbosity, "signed out\n");
    
    if (0 == postValue)
    {
        if (0 != msgctl(_mqid, IPC_RMID, NULL))
        {
            perror("queue could not be destroyed");
        }
        else if(_verbosity)
        {
            printf("queue destroyed\n");
        }
    }
}

int WaitForClients(Semaphores* _semaphores)
{
    int val;
    useconds_t sleepTime = 1000;
    
    while (MAX_WAIT > sleepTime)
    {
        sem_getvalue(_semaphores->m_clients, &val);
        if (0 != val)
        {
            return SUCCESS;
        }
        usleep(sleepTime);
        sleepTime *= 2;
    }
    return FAIL;
}

/* =================== */

int main(int argc, char** argv)
{
    Semaphores semaphores;
	ServerParams serverParams;
    int mqid;
    int totalMsgs;
    
    InitServerParams(&serverParams);
    if (SetArgs(argc, argv, &serverParams))
    {
        perror("incorrect args\n");
        return 1;
    }
    
    if (InitQueue(serverParams.m_fileName, &mqid))
    {
        return 1;
    }
    
    LinkSemaphores(&semaphores);
    SignIn(&semaphores, serverParams.m_verbosity);
    
    if (SUCCESS == WaitForClients(&semaphores))
    {
        printf("Listening to clients...\n");
        totalMsgs = ListenToClients(mqid, &semaphores, &serverParams);
        printf("%d messages were successfuly processed\n", totalMsgs);
    }
    printf("no more clients available.\n");
    
    SignOut(mqid, &semaphores, serverParams.m_verbosity);
    UnlinkSemaphores(&semaphores);
}
