#ifndef __FEEDER_MANAGER_H__
#define __FEEDER_MANAGER_H__

#include "../../CDRDataTypes/Record.h"


typedef struct FeederManager FeederManager;


FeederManager* FeederManagerCreate();

void FeederManagerDestroy(FeederManager* _feederManager);

int FeederManagerSendCDR(FeederManager* _feedMngr, Record* _record);













#endif /* #ifndef __FEEDER_MANAGER_H__ */







