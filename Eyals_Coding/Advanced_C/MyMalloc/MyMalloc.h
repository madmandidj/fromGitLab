#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__

#include <stdlib.h>

typedef struct Buffer Buffer;
typedef struct Chunk Chunk;
typedef struct ChunkMetaData ChunkMetaData;
/*typedef struct void* UserData;*/



Buffer*	BufferCreate(size_t _userDataSize, size_t _numOfChunks);

void	BufferDestroy(Buffer* _myBuf);

void*	MyMalloc(Buffer* _myBuf);

void	MyMallocFree(Buffer* _myBuf, void* _userData);






#endif /* #ifndef __MY_MALLOC_H__ */
