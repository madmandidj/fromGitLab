#include "../inc/ProtectedQueue.h"
#include "../inc/PQProducers.h"
#include "../inc/PQConsumers.h"
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <pthread.h>


/*****
Create int array
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}


void ReadMsgInt(int* _msg, char* _callerName, char* _comMode)
{
	printf("%s: %u, %s msg: %d\n", _callerName, (size_t)pthread_self(), _comMode, *_msg);
	
	return;
}






int main(int _argc, char* _argv[])
{
	int* arr = NULL;
	size_t 		numOfInts = 20;
	size_t 		queueSize = 10;
	size_t 		numOfProds = 5;
	size_t 		numOfCons = 5;
	size_t 		numOfMsgs = 10;
	ProQueue* 	P2C;
	ProQueue* 	C2P;
	Producers* 	prods;
	Consumers* 	cons;
	sem_t* 		eowFlag;
	
	eowFlag = sem_open(EOW_SEM, O_CREAT, 0666, 1);
	arr = InitIntArr(numOfInts);
	
	P2C = ProQueueCreate(queueSize);
	C2P = ProQueueCreate(queueSize);	
	prods = ProducersCreate(numOfProds, numOfMsgs, (void**)arr, P2C, C2P);
	cons = ConsumersCreate(numOfCons, P2C, C2P, (ReadMsg)ReadMsgInt);
	
	ConsumersRun(cons);
	ProducersRun(prods);
	ProducersJoin(prods);
	
	sem_wait(eowFlag);
	
	ConsumersDelete(cons);
	ProducersDelete(prods);
	ProQueueDestroy(P2C);
	ProQueueDestroy(C2P);
	
	sem_close(eowFlag);
	sem_unlink(EOW_SEM);


	return 0;
}




