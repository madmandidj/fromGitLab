#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__

#include <stdlib.h>

/** 
 *  @file MyMalloc.h
 *  @brief My Malloc functionality
 *	
 *  @details  Buffer is allocated by parameters: chunk size (in bytes) and number of chunks
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Zero bug approach 
 */

typedef struct MyBuf MyBuf;

typedef struct MyChunk MyChunk;

MyBuf*	MyBufCreate(size_t _chunkSize, size_t _numOfChunks);

void	MyBufDestroy(MyBuf* _myBuf);

void*	MyMalloc(MyBuf* _myBuf);

void	MyMallocFree(MyBuf* _myBuf, void* _myChunk);





















#endif /* #ifndef __MY_MALLOC_H__ */
