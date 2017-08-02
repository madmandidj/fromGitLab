#include <stdio.h>
#include <stdlib.h>
#include "BitMap.h"

BitMap* CreateBitMap(int _nof)
{
	BitMap* bM;
	bM = NULL;
	if (0 >= _nof)
	{
		return NULL;
	}
	bM = malloc(sizeof(BitMap));
	if (NULL == bM)
	{
		return NULL;
	}
	else
	{
		if (_nof % (CHAR_BIT_NUM * sizeof(char)) != 0)
		{
			bM->m_bits = malloc(((_nof / (CHAR_BIT_NUM * sizeof(char)))+1) * sizeof(char));
		}
		else
		{
			bM->m_bits = malloc(_nof * sizeof(char));
		}
		if (NULL == bM->m_bits)
		{
			free(bM);
			return NULL;
		}
	}
	bM->m_nof = _nof;
	return bM;
}


void DestroyBitMap(BitMap* _bM)
{
	if (NULL == _bM)
	{
		return;
	}
	else
	{
		if (NULL != _bM->m_bits)
		{
			free(_bM->m_bits);
			/*_bM->m_bits = NULL; //WHY DID THIS CAUSE SEGMENTATION FAULTS? */	
		}
		free(_bM);
		/*_bM = NULL; //WHY DID THIS CAUSE SEGMENTATION FAULTS? */ 
	}
	return;
}


int BitOn(BitMap* _bM, int _bNum)
{
	char charMask = 1;
	int bMIndex;
	int bitIndex;
	if (NULL == _bM)
	{
		return 0;
	}
	if (_bNum >= _bM->m_nof || _bNum < 0)
	{
		return 0;
	}
	bMIndex = _bNum / CHAR_BIT_NUM;
	bitIndex = _bNum % CHAR_BIT_NUM;
	charMask <<= bitIndex;
	_bM->m_bits[bMIndex] = _bM->m_bits[bMIndex] | charMask;
	return 1;
}


int BitOff(BitMap* _bM, int _bNum)
{
	char charMask = 1;
	int bMIndex;
	int bitIndex;
	if (NULL == _bM)
	{
		return 0;
	}
	if (_bNum >= _bM->m_nof || _bNum < 0)
	{
		return 0;
	}
	bMIndex = _bNum / CHAR_BIT_NUM;
	bitIndex = _bNum % CHAR_BIT_NUM;
	charMask <<= bitIndex;
	charMask = ~charMask;
	_bM->m_bits[bMIndex] = _bM->m_bits[bMIndex] & charMask;
	return 1;
}


int IsBitOn(BitMap* _bM, int _bNum)
{
	char charMask = 1;
	int bMIndex;
	int bitIndex;
	if (NULL == _bM)
	{
		return -1;
	}
	if (_bNum >= _bM->m_nof || _bNum < 0)
	{
		return -1;
	}
	bMIndex = _bNum / CHAR_BIT_NUM;
	bitIndex = _bNum % CHAR_BIT_NUM;
	charMask <<= bitIndex;
	if ((_bM->m_bits[bMIndex] & charMask) == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}


void PrintBitMap(BitMap* _bM, int _nof)
{
	int index;
	if (NULL == _bM)
	{
		return;
	}
	printf("\n");
	for (index = _nof-1; index >= 0; --index){
		printf("%d", IsBitOn(_bM, index));
	}
	printf("\n");
	
}

