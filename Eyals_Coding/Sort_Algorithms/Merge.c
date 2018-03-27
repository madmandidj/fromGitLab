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
			VectorSet(_resultVec, curResultIndex++, (void*) itemR);
			++indexR;
		}
		else if (*itemL <= *itemR)
		{
			VectorSet(_resultVec, curResultIndex++, (void*) itemL);
			++indexL;
		}
/*		else*/
/*		{*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemL);*/
/*			VectorSet(_resultVec, curResultIndex++, (void*) itemR);*/
/*			++indexL;*/
/*			++indexR;*/
/*		}*/
	}
	while (indexL <= _highL)
	{
		VectorGet(_vector, indexL++, (void**)&itemL);
		VectorSet(_resultVec, curResultIndex++, (void*) itemL);
	}
	while (indexR <= _highR)
	{
		VectorGet(_vector, indexR++, (void**)&itemR);
		VectorSet(_vector, curResultIndex++, (void*) itemR);
	}
	for(indexL = _lowL; indexL <=_highR; ++indexL)
	{
		VectorGet(_resultVec, indexL, (void**)&itemL);
		VectorSet(_vector, indexL, (void*) itemL);
	}
}

void MergeSortRec(Vector* _vector, Vector* _resultVec, int _low, int _high)
{
	int midIndex;
	if (_low >= _high)
	{
		return;
	}
	midIndex = (_high + _low) / 2;
	MergeSortRec(_vector, _resultVec, _low, midIndex);
	MergeSortRec(_vector, _resultVec, midIndex + 1, _high);
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
	for(index = 0; index < numOfItems; ++index)
	{
		VectorGet(_vector, index, (void**)&element);
		VectorAppend(resultVec, (void*)element);
	}
	
	MergeSortRec(_vector, resultVec, 0, numOfItems - 1);
	VectorDestroy(resultVec, NULL);
}
