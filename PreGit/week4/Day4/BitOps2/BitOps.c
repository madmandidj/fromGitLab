#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BitOps.h"


int IsBitOn(const Byte _src, int _bitInd)
{
	int output = 1;
	Byte byteMask = 1;
	byteMask <<= _bitInd;
	if ((_src & byteMask) == 0)
	{
		output = 0;
	}
	return output;
}

void PrintByte(const Byte _byte)
{
	int index;
	for (index = CHAR_BIT-1; index >= 0; --index)
	{
		printf("%d", IsBitOn(_byte, index));
	}
	printf("\n");
	return;
}


int InvertByte(const Byte _src, Byte* _srcInv)
{
	int output = 1;
	Byte byteMask = 255;
	if (NULL == _srcInv || _src > 255 || _src < 0)
	{
		output = 0;
	}
	else
	{
		*_srcInv = _src ^ byteMask;
		output = 1;
	}
	return output;
}


int BitOn(Byte* _src, int _bitInd)
{
	int output = 1;
	Byte byteMask = 1;
	if (NULL == _src)
	{
		output = 0;
	}
	else
	{
		byteMask <<= _bitInd;
		*_src = *_src | byteMask;
	}
	return output;
}


int BitOff(Byte* _src, int _bitInd)
{
	int output = 1;
	Byte byteMask = 1;
	if (NULL == _src)
	{
		output = 0;
	}
	else
	{
		byteMask <<= _bitInd;
		byteMask = ~byteMask;
		*_src = *_src & byteMask;
	}
	return output;
}


int RotateByteRight(const Byte _src, Byte* _srcRot, int _nPlaces)
{
	int output = 1;
	int index;
	Byte tempByte;
	if (NULL == _srcRot)
	{
		output = 0;
	}
	else
	{
		*_srcRot = _src; 
		for (index = 0; index < _nPlaces; ++index)
		{
			tempByte = IsBitOn(*_srcRot, 0);
			*_srcRot >>= 1;
			if(tempByte != 0)
			{
				BitOn(_srcRot, CHAR_BIT-1);
			}
			else
			{
				BitOff(_srcRot, CHAR_BIT-1);
			}
		}
	}
	return output;
}


int IsBitOnInt(const unsigned int _src, int _bitInd)
{
	int output = 1;
	unsigned int intMask = 1;
	intMask <<= _bitInd;
	if ((_src & intMask) == 0)
	{
		output = 0;
	}
	return output;
}


int BitOnInt(unsigned int* _src, int _bitInd)
{
	int output = 1;
	unsigned int intMask = 1;
	if (NULL == _src)
	{
		output = 0;
	}
	else
	{
		intMask <<= _bitInd;
		*_src = *_src | intMask;
	}
	return output;
}


int BitOffInt(unsigned int* _src, int _bitInd)
{
	int output = 1;
	unsigned int intMask = 1;
	if (NULL == _src)
	{
		output = 0;
	}
	else
	{
		intMask <<= _bitInd;
		intMask = ~intMask;
		*_src = *_src & intMask;
	}
	return output;
}


void PrintInt(const unsigned int _int)
{
	int index;
	for (index = INT_BIT-1; index >= 0; --index)
	{
		printf("%d", IsBitOnInt(_int, index));
	}
	printf("\n");
	return;
}


int setBitsNP(Byte* _x, const Byte* _y, int _n, int _p)
{
	int output = 1;
	int index;
	Byte tempByte;
	if (NULL == _x || NULL == _y)
	{
		output = 0;
	}
	else if (CHAR_BIT < _n || CHAR_BIT < _p)
	{
		output = 0;
	}
	else if (0 > _n || 0 > _p)
	{
		output = 0;
	}
	else if (_n > _p)
	{
		output = 0;
	}
	else
	{
		for (index = 0; index < _n; index++)
		{
			tempByte = IsBitOn(*_y, _n-1-index);
			if (0 != tempByte)
			{
				BitOn(_x, _p-1-index);
			}
			else
			{
				BitOff(_x, _p-1-index);
			}
		}
	}
	return output;
}


int setBitsIJ(unsigned int* _w, int _i, int _j, int value)
{
	int output = 1;
	int index;
	if (NULL == _w)
	{
		output = 0;
	}
	else if (_i > INT_BIT-1 || _j > INT_BIT-1)
	{
		output = 0;
	}
	else if (_j > _i)
	{
		output = 0;
	}
	else if (value != 0 && value != 1)
	{
		output = 0;
	}
	else
	{
		for (index = _i; index >= _j; --index)
		{
			if (value == 1)
			{
				BitOnInt(_w, index);
			}
			else
			{
				BitOffInt(_w, index);
			}
		} 
	}
	return output;
}

