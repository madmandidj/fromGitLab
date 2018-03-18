#ifndef __CLIENT_T_H__
#define __CLIENT_T_H__

typedef struct Client_t Client_t;

Client_t* ClientCreate(int _port, char* _ip);

void ClientDestroy(Client_t* _client);

void ClientRun(Client_t* _client);

#endif //#ifndef __CLIENT_T_H__
