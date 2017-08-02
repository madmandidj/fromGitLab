/*
Filename: 		StrHomework.c 
Description:	Implementation of String Functions
Created: 		01/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include "StrHomework.h"







/*
 STRLEN ITERATIVE AND RECURSIVE
*/

static size_t MyStrLenRec(const char* _str, size_t _index)
{
	if (_str[_index] == '\0')
	{
		return _index;
	}
	else
	{
		_index += 1;
		_index = MyStrLenRec(_str, _index);
	}	
	return _index;
}

size_t StrLenRec(const char* _str)
{
	size_t index = 0;
	if (NULL == _str)
	{
		return 0;
	}
	index = MyStrLenRec(_str, index);
	return index;
}

size_t StrLen(const char* _str)
{
	size_t index = 0;
	if (NULL == _str)
	{
		return 0;
	}
	while (_str[index] != '\0')
	{
		++index;
	}
	return index;
}























/*
 STRCOMPARE ITERATIVE AND RECURSIVE
*/

static int MyStrCompareRec(const char* _s1, const char* _s2, size_t _index)
{
	int result;
	if (_s1[_index] != _s2[_index])
	{
		return _s1[_index] - _s2[_index];
	}
	if (_s1[_index] == '\0')
	{
		return 0;
	}
	result = MyStrCompareRec(_s1, _s2, _index +1);
	return result;
}
int StrCompareRec(const char* _s1, const char* _s2)
{
	size_t index = 0;
	int result;
	if (NULL == _s1 || NULL == _s2)
	{
		return 0;
	}
	result = MyStrCompareRec(_s1, _s2, index);
	return result;
}

int StrCompare(const char* _s1, const char* _s2)
{
	size_t index = 0;
	if (NULL == _s1 || NULL == _s2)
	{
		return 0;
	}
	/*TODO: what happens if both reach '\0' <---no problem! */
	while(_s1[index] == _s2[index])
	{
		if (_s1[index] == '\0')
		{
			return 0;
		}
		++index;
	}
	return _s1[index] - _s2[index];
}
























/*
 STRCOPY ITERATIVE AND RECURSIVE
*/

static char* MyStrCopyRec(char* _destination, const char* _source, size_t _index)
{
	char* result;
	if (_source[_index] == '\0')
	{
		_destination[_index] = '\0';
		return _destination;
	}
	_destination[_index] = _source[_index];
	++_index;
	result = MyStrCopyRec(_destination, _source, _index);
	return result;
}

char* StrCopyRec(char* _destination, const char* _source)
{
	size_t index = 0;
	char* result;
	if (NULL == _destination || NULL == _source)
	{
		return NULL;
	}
	result = MyStrCopyRec(_destination, _source, index);
	return result;
}

char* StrCopy(char* _destination, const char* _source)
{
	size_t index = 0;
	if (NULL == _destination || NULL == _source)
	{
		return NULL;
	}
	while (_source[index] != '\0')
	{
		_destination[index] = _source[index];
		++index;
	}
	_destination[index] = '\0';
	return _destination;
}

















/*
 STRNCOPY ITERATIVE AND RECURSIVE
*/

static char* MyStrNCopyRec(char* _destination, const char* _source, size_t _num, size_t _index)
{
	char* result;
	if (_source[_index] == '\0' || _index < _num)
	{
		_destination[_index] = '\0';
		return _destination;
	}
	_destination[_index] = _source[_index];
	++_index;
	result = MyStrNCopyRec(_destination, _source, _num, _index);
	return result;
}

char* StrNCopyRec(char* _destination, const char* _source, size_t _num)
{
	size_t index = 0;
	char* result;
	if (NULL == _destination || NULL == _source || _num == 0)
	{
		return NULL;
	}
	result = MyStrNCopyRec(_destination, _source, _num, index);
	return result;
}

char* StrNCopy(char* _destination, const char* _source, size_t _num)
{
	size_t index = 0;
	if (NULL == _destination || NULL == _source || _num == 0)
	{
		return NULL;
	}
	while (_source[index] != '\0' && index < _num)
	{
		_destination[index] = _source[index];
		++index;
	}
	_destination[index] = '\0';
	return _destination;
}




















/*
 STRNCONCAT 
*/

char* StrConcat(char* _destination, const char* _source)
{
	size_t destIndex = 0;
	size_t sourceIndex = 0;
	if (NULL == _destination || NULL == _source)
	{
		return NULL;
	}
	while (_destination[destIndex] != '\0')
	{
		++destIndex;
	}
	while (_source[sourceIndex] != '\0')
	{
		_destination[destIndex] = _source[sourceIndex];
		++sourceIndex;
		++destIndex;
	}
	_destination[destIndex] = '\0';
	return _destination;
}

















/*
 STRSUBSTRING
*/


char* StrSubString(const char* _str, const char* _search)
{
	size_t strIndex = 0;
	size_t searchIndex = 0;
	size_t foundIndex = 0;
	if (NULL == _str || NULL == _search) /* TODO: if search length is greater than str length */
	{
		return NULL;
	}
	
	while (_str[strIndex] != '\0') /* TODO: can run untill str length - search length */
	{
		searchIndex = 0;
		if (_str[strIndex] == _search[searchIndex])
		{
			foundIndex = strIndex;
			++strIndex;
			++searchIndex;
			while (_search[searchIndex] != '\0')
			{
				if (_str[strIndex] != _search[searchIndex])
				{
					break;
				}
				++strIndex;
				++searchIndex;
			}
			if (_search[searchIndex] == '\0')
			{
				return (char*)_str + foundIndex;
			}
		}
		else
		{
			++strIndex;
		}
	}
	return NULL;
}


















