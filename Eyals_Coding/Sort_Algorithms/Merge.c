#include "Sort_Algorithms.h"
#include "../Data_Structures/inc/Vector.h"

#define FALSE 0
#define TRUE 1

void Merge(Vector* _vector, Vector* _resultVec, int _lowL, int _highL, int _lowR, int _highR)
{
	int indexL = _lowL;
	int indexR = _lowR;
	int* itemL;
	int* itemR;
	int curResultIndex = _lowL;

	while(curResultIndex <= _highR && indexL <= _highL && indexR <= _highR)
	{
		VectorGet(_vector, indexL, (void**)&itemL);
		VectorGet(_vector, indexR, (void**)&itemR);
		if (*itemR < *itemL)
		{
			VectorSet(_vector, curResultIndex++, (void*) itemR);
			++indexR;
			++curResultIndex;
		}
		else if (*itemL < *itemR)
		{
			VectorSet(_vector, curResultIndex++, (void*) itemL);
			++indexL;
		}
		else
		{
			VectorSet(_vector, curResultIndex++, (void*) itemL);
			VectorSet(_vector, curResultIndex++, (void*) itemR);
			++indexL;
			++indexR;
		}
	}
	while (indexL <= _highL)
	{
		VectorGet(_vector, indexL++, (void**)&itemL);
		VectorSet(_vector, curResultIndex++, (void*) itemL);
	}
	while (indexR <= _highR)
	{
		VectorGet(_vector, indexR++, (void**)&itemR);
		VectorSet(_vector, curResultIndex++, (void*) itemR);
	}


	/****************************************/
/*	
	if (_lowR > _highR)
	{
		_highR = _lowR;
	}
	if (_lowL > _highL)
	{
		_highL = _lowL;
	}
	
	while(indexL <= _highL && indexR <= _highR)
	{
		VectorGet(_vector, indexL, (void**)&itemL);
		VectorGet(_vector, indexR, (void**)&itemR);
		if (*itemR < *itemL)
		{
			VectorAppend(_resultVec, (void*) itemR);
			++indexR;
		}
		else if (*itemL < *itemR)
		{
			VectorAppend(_resultVec, (void*) itemL);
			++indexL;
		}
		else
		{
			VectorAppend(_resultVec, (void*) itemL);
			VectorAppend(_resultVec, (void*) itemR);
			++indexL;
			++indexR;
		}
	}
	while (indexL <= _highL)
	{
		VectorGet(_vector, indexL++, (void**)&itemL);
		VectorAppend(_resultVec, (void*) itemL);
	}
	while (indexR <= _highR)
	{
		VectorGet(_vector, indexR++, (void**)&itemR);
		VectorAppend(_resultVec, (void*) itemR);
	}
	*/
	
	/****************************************/
	
	
/*	while(curResultIndex <= _highR && indexL <= _highL && indexR <= _highR)*/
/*	{*/
/*		VectorGet(_vector, indexL, (void**)&itemL);*/
/*		VectorGet(_vector, indexR, (void**)&itemR);*/
/*		if (*itemR < *itemL)*/
/*		{*/
/*			VectorAppend(VectorSet(_resultVec, (void*) itemR);*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemR);*/
/*			++indexR;*/
/*			++curResultIndex;*/
/*		}*/
/*		else if (*itemL < *itemR)*/
/*		{*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemL);*/
/*			++indexL;*/
/*		}*/
/*		else*/
/*		{*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemL);*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemR);*/
/*			++indexL;*/
/*			++indexR;*/
/*		}*/
/*	}*/
/*	while (indexL <= _highL)*/
/*	{*/
/*		VectorGet(_vector, indexL++, (void**)&itemL);*/
/*		VectorSet(_resultVec, curResultIndex++, (void*) itemL);*/
/*	}*/
/*	while (indexR <= _highR)*/
/*	{*/
/*		VectorGet(_vector, indexR++, (void**)&itemR);*/
/*		VectorSet(_resultVec, curResultIndex++, (void*) itemR);*/
/*	}*/
}

void MergeSortRec(Vector* _vector, Vector* _resultVec, int _low, int _high)
{
	int midIndex;
	if (_low > _high)
	{
		return;
	}
	midIndex = (_high + _low) / 2;
	if (midIndex > 0)
	{
		MergeSortRec(_vector, _resultVec, _low, midIndex);
		MergeSortRec(_vector, _resultVec, midIndex + 1, _high);
	}
/*	if(midIndex == 0)*/
/*	{*/
/*		return;*/
/*	}*/
	Merge(_vector, _resultVec, _low, midIndex, midIndex + 1, _high);
}

void MergeSort(Vector* _vector)
{
	size_t numOfItems;
	Vector* resultVec;
	size_t index;
	int* element;
	if (!_vector || 1 >= VectorItemsNum(_vector))
	{
		return;
	}
	else
	{
		numOfItems = VectorItemsNum(_vector);
	}
	resultVec = VectorCreate(numOfItems, 10);
	MergeSortRec(_vector, resultVec, 0, numOfItems - 1);
	for(index = 0; index < numOfItems; ++index)
	{
		VectorGet(resultVec, index, (void**)&element);
		VectorSet(_vector, index, (void*)element);
	}
	VectorDestroy(resultVec, NULL);
}
