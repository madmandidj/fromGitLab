#include "DynamicIntArray.h"
#include <stdlib.h>
#include <stdio.h>
/******************************************************/
/******************************************************/
/****************STATIC FUNCTIONS**********************/
/******************************************************/
/******************************************************/
static int IsValidDynArr(DynArr* _da1)
{
	return (_da1 && _da1->m_arr) ? 1 : 0;
}
static int AreDestroyParamsValid(DynArr* _da1)
{
	return IsValidDynArr(_da1);
}
static void DoDestroy(DynArr* _da1)
{
	free(_da1->m_arr);
	free(_da1);
	return;
}
static int AreInsertParamsValid(DynArr* _da1, int* _num)
{
	return (IsValidDynArr(_da1) && _num) ? 1 : 0;
}
static int AreInsertByIndexParamsValid(DynArr* _da1, int* _num, int _index)
{
	return (AreInsertParamsValid(_da1, _num)) ? ((_index >= 0 && _index <= _da1->m_noe) ? 1 : 0) : 0;
}
static int GetIndexOfNum(DynArr* _da1, int* _num)
{
	int index;
	for (index = 0; index < _da1->m_noe; ++index)
	{
		if (*_da1->m_arr[index] == *_num)
		{
			return index;
		}
	}
	return -1;
}
static int ResizeMoreIfNeeded(DynArr* _da1)
{
	IntPtr* tempIntPtr;
	if (_da1->m_noe == _da1->m_cap)
	{
		if (!(tempIntPtr = realloc(_da1->m_arr, sizeof(IntPtr) * (_da1->m_cap + _da1->m_blockSize))))
		{
			return 0;
		} 
		_da1->m_arr = tempIntPtr;
		_da1->m_cap = _da1->m_cap + _da1->m_blockSize;
	}
	return 1;
}
void ShiftElementsRightByOne(DynArr* _da1, int _index)
{
	int curIndex = _da1->m_noe;
	while (curIndex > _index)
	{
		_da1->m_arr[curIndex] = _da1->m_arr[curIndex - 1];
		--curIndex;
	}
	return;
}
static void DoInsert(DynArr* _da1, int* _num, int _index)
{
	_da1->m_arr[_index] = _num;
	++_da1->m_noe;
	return;
}
static int AreFindParamsValid(DynArr* _da1)
{
	return IsValidDynArr(_da1);
}
static int AreRemoveByNumParamsValid(DynArr* _da1)
{
	return IsValidDynArr(_da1);
}
void ShiftElementsLeftByOne(DynArr* _da1, int _index)
{
	int curIndex = _index;
	while (curIndex < _da1->m_noe)
	{
		_da1->m_arr[curIndex] = _da1->m_arr[curIndex + 1];
		++curIndex;
	}
	return;
}
static int ResizeLessIfNeeded(DynArr* _da1)
{
	IntPtr* tempIntPtr;
	if (_da1->m_noe < (_da1->m_cap - _da1->m_blockSize))
	{
		if (!(tempIntPtr = realloc(_da1->m_arr, sizeof(IntPtr) * (_da1->m_cap - _da1->m_blockSize))))
		{
			return 0;
		} 
		_da1->m_arr = tempIntPtr;
		_da1->m_cap = _da1->m_cap - _da1->m_blockSize;
	}
	return 1;
}
/******************************************************/
/******************************************************/
/******************API FUNCTIONS***********************/
/******************************************************/
/******************************************************/
DynArr* CreateDA(int _capacity, int _blockSize)
{
	DynArr* dynArr;
	if (0 >= _capacity)
	{
		return NULL;
	}
	if (!(dynArr = malloc(sizeof(DynArr))))
	{
		return NULL;
	}
	dynArr->m_cap = _capacity;
	if (!(dynArr->m_arr = malloc(sizeof(IntPtr) * dynArr->m_cap)))
	{
		free(dynArr);
		return NULL;
	}
	dynArr->m_noe = 0;
	dynArr->m_blockSize = _blockSize;
	return dynArr;
}
/******************************************************/
void Destroy(DynArr* _da1)
{
	if (!AreDestroyParamsValid(_da1))
	{
		return;
	}
	DoDestroy(_da1);
	return;
}
/******************************************************/
int Insert(DynArr* _da1, int* _num)
{
	return InsertByIndex(_da1, _num, _da1->m_noe);
}
/******************************************************/
int InsertByIndex(DynArr* _da1, int* _num, int _index)
{
	if (!AreInsertByIndexParamsValid(_da1, _num, _index))
	{
		return 0;
	}
	if (-1 != GetIndexOfNum(_da1, _num))
	{
		return 0;
	}
	if (!ResizeMoreIfNeeded(_da1))
	{
		Destroy(_da1);
	}
	ShiftElementsRightByOne(_da1, _index);
	DoInsert(_da1, _num, _index);
	return 1;
}
/******************************************************/
int* Find(DynArr* _da1, int _numtofind)
{
	int index;
	if (!AreFindParamsValid(_da1))
	{
		return NULL;
	}
	if (-1 == (index = GetIndexOfNum(_da1, &_numtofind)))
	{
		return NULL;
	}
	return _da1->m_arr[index];
}
/******************************************************/
int	RemoveNum(DynArr* _da1, int _numtoremove)
{
	int index;
	AreRemoveByNumParamsValid(_da1);
	if (-1 == (index = GetIndexOfNum(_da1, &_numtoremove)))
	{
		return 0;
	}
	ShiftElementsLeftByOne(_da1, index);
	ResizeLessIfNeeded(_da1);
	--_da1->m_noe;
	return 1;
}
/******************************************************/
void	PrintDA(DynArr* _da1)
{
	size_t index;
	for (index = 0; index < _da1->m_noe; ++index)
	{
		printf("%d\n", *_da1->m_arr[index]);
	}
}
/******************************************************/
int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	DynArr* dynArr;
	dynArr = CreateDA(5, 2);
	Insert(dynArr, &arr[0]);
	Insert(dynArr, &arr[1]);
	Insert(dynArr, &arr[2]);
	InsertByIndex(dynArr, &arr[3], 1);
	Insert(dynArr, &arr[4]);
	Insert(dynArr, &arr[5]);
	Insert(dynArr, &arr[6]);
	PrintDA(dynArr);
	RemoveNum(dynArr, 0);
	RemoveNum(dynArr, 1);
	RemoveNum(dynArr, 2);
	RemoveNum(dynArr, 3);
	PrintDA(dynArr);
	Destroy(dynArr);
	return 0;
}
