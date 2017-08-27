#include "MyMalloc.h"

#define MYBUF_MAGIC_NUM 0xCABAD00D
#define MYCHUNK_MAGIC_NUM 0xC011BEA8

struct MyBuf
{
	unsigned int 	m_magicNum;
	void* 			m_nextFreeChunk;
	size_t			m_chunkSize;
};


struct MyChunk
{
	unsigned int		m_magicNum;
	void*				m_next;
	char				m_data;
};







MyBuf*	MyBufCreate(size_t _chunkSize, size_t _numOfChunks)
{
	MyBuf* myBuf;
	MyChunk myChunk1; 
	MyChunk myChunk2;
	
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
	myBuf->m_nextFreeChunk = (char*) myBuf + sizeOfMyBuf;
	
	
	myChunk1.m_magicNum = MYCHUNK_MAGIC_NUM;
	myChunk1.m_next = (char*) myBuf->m_nextFreeChunk + _chunkSize;

	
	for (index = 0; index < _numOfChunks - 1; ++index)
	{
		/*
		(myChunk->m_next)->m_next = &(*myChunk) + sizeOfMyChunk;
		*/
	}
	
	return myBuf;
	/*
		PSUEDO CODE:
		************
		
		check valid params
		Calculate actual malloc size for MyBuf
		Allocate MyBuf
		Initialize MyBuf members
		for (numOfChunks)
		{
			Assign next to next chunk
		}
		return MyBuf*
	*/
}





void	MyBufDestroy(MyBuf* _myBuf)
{
	if (!_myBuf)
	{
		return;
	}
	
	_myBuf->m_magicNum = 0;
	free(_myBuf);
	
	return;
	
	
	
	/*
		PSUEDO CODE:
		************
		
		check valid params
		reset magic num
		free(_mybuf)
		return
	*/
}






void*	MyMalloc(MyBuf* _myBuf)
{
	void* test = NULL;
	
	
	
	
	return test;
	/*
		PSUEDO CODE:
		************
		
		check valid params
		if (!chunk available)
		{
			return NULL;
		}
		assign current free pionter to variable ptr
		move free to next free position
		return ptr
	*/
}








void	MyMallocFree(MyBuf* _myBuf, MyChunk* _myChunk)
{




	/*
		PSUEDO CODE:
		************
		
		check valid params
		if (Chunks available == num of chunks)
		{
			return;
		}
		set My_chunk next to point to free
		set free to point to My_chunk
		return 
	*/
}






