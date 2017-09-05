#ifndef __BARRIER_H__
#define __BARRIER_H__


/*
typedef struct Barrier Barrier;
*/

typedef 

/**
*	@brief Create a barrier
*	
*	@param int - capacity of barrier
*
*	@return Barrier* - Newly created barrier
*/
Barrier* BarrierCreate(int _capacity);


/**
*	@brief Destroy a barrier
*	
*	@param Barrier* - pointer to barrier to destroy
*
*	@return void
*/
void BarrierDestroy(Barrier* _barrier);



/**
*	@brief Wait on barrier untill condition satisfied
*	
*	@param Barrier* - barrier to wait on
*
*	@return int
*
*	@retval 0 - Wait succeeded
*
*	@retval 1 - DestroyBarrier received during wait
*
*	@retval -1 - Error occured, so check errno
*/
int BarrierWait(Barrier* _barrier);






#endif /* #ifndef __BARRIER_H__ */
