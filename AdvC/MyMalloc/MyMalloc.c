#include "MyMalloc.h"

#define MYBUF_MAGIC_NUM 0xCABAD00D
#define MYCHUNK_MAGIC_NUM 0xC011BEA8

#define IS_A_MYBUF(B)		((B) && MYBUF_MAGIC_NUM == (B)->m_magicNum)
#define IS_A_MYCHUNK(C)		((C) && MYCHUNK_MAGIC_NUM == (C)->m_magicNum)


struct MyBuf
{
	unsigned int 	m_magicNum;
	void* 			m_nextFreeChunk;
	size_t			m_chunkSize;
};


/*
struct MyBuf
{
	unsigned int 	m_magicNum;
	MyChunk* 		m_nextFreeChunk;
	size_t			m_chunkSize;
};
*/

struct MyChunk
{
	unsigned int		m_magicNum;
	void*				m_next;
	char				m_data;
};







MyBuf*	MyBufCreate(size_t _chunkSize, size_t _numOfChunks)
{
	MyBuf* myBuf;
	void* myChunk; 
	
	size_t sizeOfMyBuf;
	size_t sizeOfMyChunk;
	size_t index;
	
	if (0 == _chunkSize || 0 == _numOfChunks)
	{
		return NULL;
	}

	sizeOfMyBuf = sizeof(MyBuf);
	sizeOfMyChunk = sizeof(MyChunk);
	
	myBuf = malloc((_numOfChunks * _chunkSize) + sizeOfMyBuf + (_numOfChunks * sizeOfMyChunk));
	if (!myBuf)
	{
		return NULL;
	}

	myBuf->m_magicNum = MYBUF_MAGIC_NUM;
	myBuf->m_chunkSize = _chunkSize;
	
	/*
	myBuf->m_nextFreeChunk = (char*) myBuf + sizeOfMyBuf;
	myChunk = myBuf->m_nextFreeChunk;
	*/
	
	myBuf->m_nextFreeChunk = (char*) myBuf + sizeOfMyBuf;
	myChunk = myBuf->m_nextFreeChunk;

	for (index = 0; index < _numOfChunks - 1; ++index)
	{
		((MyChunk*)myChunk)->m_next = (char*) myChunk + _chunkSize;
		myChunk = ((MyChunk*)myChunk)->m_next;
	}
	((MyChunk*)myChunk)->m_next = NULL;
	
	return myBuf;
}






void	MyBufDestroy(MyBuf* _myBuf)
{
	if (!IS_A_MYBUF(_myBuf))
	{
		return;
	}
	
	_myBuf->m_magicNum = 0;
	free(_myBuf);
	
	return;
}







void*	MyMalloc(MyBuf* _myBuf)
{
	void* myChunk;
	
	if (!IS_A_MYBUF(_myBuf) || !_myBuf->m_nextFreeChunk)
	{
		return NULL;
	}
	
	myChunk = _myBuf->m_nextFreeChunk;
	((MyChunk*)myChunk)->m_magicNum = MYCHUNK_MAGIC_NUM;
	_myBuf->m_nextFreeChunk = ((MyChunk*)_myBuf->m_nextFreeChunk)->m_next;
	
	
	return &((MyChunk*)myChunk)->m_data;
}








void	MyMallocFree(MyBuf* _myBuf, void* _myChunk)
{
	_myChunk = ((MyChunk*)_myChunk);
	if (!IS_A_MYBUF(_myBuf) || !IS_A_MYCHUNK((MyChunk*)_myChunk))
	{
		return;
	}
	
	((MyChunk*)_myChunk)->m_magicNum = 0;
	
	if (NULL == _myBuf->m_nextFreeChunk)
	{
		((MyChunk*)_myChunk)->m_next = NULL;
		_myBuf->m_nextFreeChunk = _myChunk;
	}
	else
	{
		((MyChunk*)_myChunk)->m_next = _myBuf->m_nextFreeChunk;
		_myBuf->m_nextFreeChunk = _myChunk;
	}
	
	return;
}






