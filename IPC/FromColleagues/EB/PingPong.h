#ifndef __PINGPONG_H__
#define __PINGPONG_H__

#include <unistd.h>

#define QUEUE_FILE "msgQueue"
#define PING_CHANNEL 1
#define CLIENTS_SEM "1ab64fff_clients"
#define SERVERS_SEM "1ab64fff_servers"
#define DESTROY_SEM "1ab64fff_destroy"

typedef struct
{
	long m_type;
	pid_t m_pid;
	char m_channel;
	char m_note;
	char m_velocity;
}MidiMsg;

typedef struct
{
	long m_type;
}PongMsg;

typedef struct
{
    long m_type;
    
}CounterMsg;

#endif /* #ifndef __PINGPONG_H__ */

