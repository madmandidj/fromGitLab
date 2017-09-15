#ifndef __PROCESSING_MANAGER_H__
#define __PROCESSING_MANAGER_H__


typedef struct ProcessingManager ProcessingManager;


ProcessingManager* ProcessingManagerCreate(size_t _numOfProcThreads);

void ProcessingManagerDestroy(ProcessingManager* _procMngr);

int ProcessingManagerRun(ProcessingManager* _procMngr);



#endif /* #ifndef __PROCESSING_MANAGER_H__ */



