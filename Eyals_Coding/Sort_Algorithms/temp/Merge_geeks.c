#include<stdlib.h>
#include<stdio.h>
 
// Merges two subarrays of arr[].
// First subarray is arr[_begin.._middle]
// Second subarray is arr[_middle+1.._end]
void merge(int arr[], int _begin, int _middle, int _end)
{
    int i, j, k;
    int n1 = _middle - _begin + 1;
    int n2 =  _end - _middle;
 
    /* create temp arrays */
    int L[n1], R[n2];
    Vector* vecL;
    Vector* vecR;
 
 	
    /* Copy data to temp arrays L[] and R[] */
    
    for (i = 0; i < n1; i++)
        L[i] = arr[_begin + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[_middle + 1+ j];
 
    /* Merge the temp arrays back into arr[_begin.._end]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = _begin; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* _begin is for left index and _end is right index of the
   sub-array of arr to be sorted */
void MergeSortRec(Vector* _vector, int _begin, int _end)
{
	int middle;
    if (_begin < _end)
    {
        middle = _begin+(_end-_begin)/2;
        mergeSort(arr, _begin, _middle);
        mergeSort(arr, middle+1, _end);
        merge(arr, _begin, middle, _end);
    }
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
	MergeSortRec(_vector, 0, numOfItems - 1);
}
