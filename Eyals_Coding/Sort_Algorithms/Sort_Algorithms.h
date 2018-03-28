#ifndef __SORT_ALGORITHMS_H__
#define __SORT_ALGORITHMS_H__
#include "../Data_Structures/inc/Vector.h"

/*typedef struct Vector Vector;*/

void BubbleSort(Vector* _vector);
void ShakeSort(Vector* _vector);
void InsertionSort(Vector* _vector);
void ShellSort(Vector* _vector);
void SelectionSort(Vector* _vector);
void QuickSort(Vector* _vector);
void MergeSort(Vector* _vector);
void CountingSort(Vector* _vector);
void RadixSort(Vector* _vector);

#endif/*#ifndef __SORT_ALGORITHMS_H__*/
