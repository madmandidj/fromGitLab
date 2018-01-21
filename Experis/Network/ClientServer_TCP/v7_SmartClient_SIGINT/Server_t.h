#ifndef __SERVER_T_H__
#define __SERVER_T_H__

typedef void* (*AppFunc)(void*);
typedef struct Server_t Server_t;

Server_t* ServerCreate(AppFunc _func, int _port);

int ServerDestroy(Server_t* _server);

int ServerRun(Server_t* _server);


#endif //#ifndef __SERVER_T_H__
