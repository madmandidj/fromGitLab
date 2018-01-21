#include "Package.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <errno.h>

typedef struct
{
    long m_type;
    char msg[1];
}DefMsg;

void PackageSet(Package* _pkg, int _qid, long _channel, void* _msg, size_t _size)
{
    _pkg->m_qid = _qid;
    _pkg->m_channel = _channel;
    _pkg->m_msg = _msg;
    _pkg->m_msgSize = _size - sizeof(long);
    ((DefMsg*)_msg)->m_type = _channel;
}

MsgErr PackageReceive(Package* _pkg, char* _receiver, int _verbosity)
{
    if (-1 == msgrcv(_pkg->m_qid, _pkg->m_msg, _pkg->m_msgSize, _pkg->m_channel, 0))
    {
        perror("receive error");
        return MSG_ERROR;
    }
    
    if (_verbosity)
    {
        printf("%s received\n", _receiver);
    }
    return MSG_SUCCESS;
}

MsgErr PackageReceiveAsync(Package* _pkg, char* _receiver, int _verbosity)
{
    if (-1 == msgrcv(_pkg->m_qid, _pkg->m_msg, _pkg->m_msgSize, _pkg->m_channel, IPC_NOWAIT))
    {
        if (ENOMSG != errno)
        {
            perror("receive error");
            return MSG_ERROR;
        }
        
        if (_verbosity)
        {
            printf("no messages in channel\n");
        }
        return MSG_EMPTY_Q;
        
    }
    
    if (_verbosity)
    {
        printf("%s received\n", _receiver);
    }
    return MSG_SUCCESS;
}

MsgErr PackageSend(Package* _pkg, char* _sender, int _verbosity)
{
    if (-1 == msgsnd(_pkg->m_qid, _pkg->m_msg, _pkg->m_msgSize, 0))
    {
        perror("send error");
        return MSG_ERROR;
    }
    
    if (_verbosity)
    {
        printf("%s sent\n", _sender);
    }
    return MSG_SUCCESS;
}