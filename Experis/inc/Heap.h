#ifndef __HEAP_H__
#define __HEAP_H__

/** 
 * @brief Create a Binary heap generic data type over a generic vector data type.
 * @author Author Eyal Alon (eyal171@yahoo.com) (adapted from Muhammad Zahalqa  (MuhammadZ@experis.co.il))
 * @see https://en.wikipedia.org/wiki/Binary_heap 
 */ 

#include "GenericVector.h"

typedef enum HeapResult 
{
	HEAP_SUCCESS = 0,
	HEAP_NOT_INITIALIZED,
	HEAP_REALLOCATION_FAILED,
	HEAP_INV_ARG
}HeapResult;

typedef struct Heap Heap;



/**  
 * @brief User-provided function for element actions
 * @param[in] _elem - element to act on
 * @param[in] _context - action context
 * @return int 
 * @retval 0 or 1 according to user requirements
 * @warning should be used with HeapForEach function. HeapForEach iteration will stop when ActionFunction returns 0.
 */
typedef int	(*ActionFunction)(const void *_elem, void * _context);



/**  
 * @brief User-provided function to compare between two elements 
 * @param[in] _left - first element
 * @param[in] _right - Second element 
 * @return int 
 * @retval 0 if _left <= _right
 * @retval 1 if _left > _right
 * @retval -1 if _left == NULL or _right == NULL
 *
 */
typedef int	(*LessThanComparator)(const void *_left, const void *_right);



/**  
 * @brief Apply a heap policy over a Vector container.  
 * @param[in] _vector - Vector that hold the elements. Vector must be initialized, elements must be initialized.
 * @param[in] _pfLess - A less than comparator to be used to compare elements (*LessThanComparator)
 * @return Heap * - on success
 * @retval NULL on fail 
 *
 * @warning allocating and freeing the underlying vector is user responsibility. 
 * as long as vector is under the heap control, user should not access the vector directly
 */
Heap* HeapBuild(Vector* _vector, LessThanComparator _pfLess);



/**  
 * @brief Deallocate a previously allocated heap
 * Frees the heap but not the underlying vector  
 * @param[in] _heap - Heap to be deallocated.  On success will be nulled.
 * @return Underlying vector, null if invalid heap
 */
Vector* HeapDestroy(Heap** _heap);



/**  
 * @brief Add an element to the Heap preserving heap property.  
 * @param[in] _heap - Heap to insert element to.
 * @param[in] _element - Element to insert. can't be null
 * @return success or error code 
 * @retval HEAP_SUCCES  on success
 * @retval HEAP_NOT_INITIALIZED  error, heap not initilized
 * @retval HEAP_INV_ARG error, element not initialized
 * @retval HEAP_REALLOCATION_FAILED error, heap could not reallocate underlying vector 
 */
HeapResult HeapInsert(Heap* _heap, void* _element);



/**  
 * @brief Peek at element on top of heap without extracting it.  
 * @param[in] _heap - Heap to peek at.
 * @return pointer to element, can be null if heap is empty or heap is null
 */
const void* HeapPeek(const Heap* _heap);



/**  
 * @brief Extract element on top of heap and remove it.  
 * @param[in] _heap - Heap to extract from.
 * @return pointer to element, null if heap is empty or heap is null. 
 */
void* HeapExtract(Heap* _heap);



/**  
 * @brief Get the current size (number of elements) in the heap.  
 * @param[in] _heap - the Heap.
 * @return number of elements or zero if empty. 
 */
size_t HeapSize(const Heap* _heap);



/**  
 * @brief Iterate over all elements  in the heap from top to bottom.
 * @details The user provided ActionFunction _act will be called for each element. 
 * iteration will stop at the first element wehere _act(e) returns zero
 * @param[in] _heap - Heap to iterate over.
 * @param[in] _act - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked, 0 if invalid params, 0 if heap empty
 */
size_t HeapForEach(const Heap* _heap, ActionFunction _act, void* _context);



/**  
 * @brief Sort a given vector of elments using a heap sort.
 * @param[in] _vector - vector to sort.
 * @param[in] _pfLess
 */
void HeapSort(Vector* _vec, LessThanComparator _pfLess);



#endif /* #ifndef __HEAP_H__ */
