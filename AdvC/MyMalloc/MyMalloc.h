#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__

#include <stdlib.h>

typedef struct MyBuf MyBuf;

typedef struct MyChunk MyChunk;

MyBuf*	MyBufCreate(size_t _chunkSize, size_t _numOfChunks);

void	MyBufDestroy(MyBuf* _myBuf);

void*	MyMalloc(MyBuf* _myBuf);

void	MyMallocFree(MyBuf* _myBuf, MyChunk* _myChunk);





















#endif /* #ifndef __MY_MALLOC_H__ */
