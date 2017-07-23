#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__
/*
Filename: 		QuickSort.h 
Description:	Quick Sort using Vector API given by Ronny
Created: 		21/07/17
Created by:		Eyal Alon
Last modified: 	22/07/17
Modified by:	Eyal Alon
*/
#include "vector.h"
#include "ADTDefs.h"

ADTErr 	QuickSort(Vector* _vec);
ADTErr 	QuickSortRec(Vector* _vec);

#endif /* #ifndef __QUICKSORT_H__ */
