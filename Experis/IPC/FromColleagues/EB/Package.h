#ifndef __PACKAGE_H__
#define __PACKAGE_H__

#define MSG_SIZE(PKG) sizeof(PKG) - sizeof(long)

#include <stddef.h>

typedef struct
{
    int m_qid;
    long m_channel;
    void* m_msg;
    size_t m_msgSize;
}Package;

typedef enum
{
    MSG_SUCCESS,
    MSG_ERROR,
    MSG_EMPTY_Q
}MsgErr;

void PackageSet(Package* _pkg, int _qid, long _channel, void* _msg, size_t _size);

MsgErr PackageReceive(Package* _pkg, char* _receiver, int _verbosity);
MsgErr PackageReceiveAsync(Package* _pkg, char* _receiver, int _verbosity);

MsgErr PackageSend(Package* _pkg, char* _sender, int _verbosity);


#endif