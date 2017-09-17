#ifndef __READER_H__
#define __READER_H__

#include "../../CDRDataTypes/Record.h"
#include "../../Comms/Receiver/Receiver.h"
#include "../../Comms/Transmitter/Transmitter.h"

typedef struct Reader Reader;

Reader* ReaderCreate(unsigned int _numOfThreads, char* _cdrPath, Transmitter* _trans, Receiver* _rcvr);

void ReaderDestroy(Reader* _reader);

int ReaderRun(Reader* _reader);
























#endif /* #ifndef __READER_H__ */



