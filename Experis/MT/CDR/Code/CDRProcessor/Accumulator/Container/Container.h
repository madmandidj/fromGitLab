#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include "./HashMap/HashMap.h"
#include "../../../CDRDataTypes/Subscriber.h"
#include "../../../CDRDataTypes/Operator.h"
#include <stdlib.h>
/** 
 *  @file Container.h
 *
 *  @brief Container is responsible for inserting, retreiving and element actions on container elements
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Container Container;



/** 
 * @brief Create new Container instance
 *
 * @param[in] _capacity - Capacity of container 
 *
 * @param[in] _func - equality function for container elements
 *  
 * @return  pointer to allocated Container instance
 *
 * @retval	NULL upon create fail, if allocate fails or _func == NULL
 *
 * @retval	!NULL upon create success
 */
Container* ContainerCreate(size_t _capacity, EqualityFunction _func);



/** 
 * @brief Destroy Container instance
 *
 * @param[in] _cont - Container instance to destroy
 *  
 * @return  void
 */
void ContainerDestroy(Container* _cont);



/** 
 * @brief Get element in container
 *
 * @param[in] _cont - Container to get element from
 *
 * @param[in] _key - search key for element
 *
 * @param[in-out] _elementFound - pointer to receive found element
 *  
 * @return  pointer to allocated Container instance
 *
 * @retval	0 if fail - NULL == _cont || NULL == _key || NULL == _elementFound, or if element not found
 *
 * @retval	1 if success
 */
int	ContainerGetElement(Container* _cont, char* _key, void** _elementFound);



/** 
 * @brief Insert element into container
 *
 * @param[in] _cont - Container to insert element
 *
 * @param[in] _key - insert key for element
 *
 * @param[in-out] _element - element to insert
 *  
 * @return  pointer to allocated Container instance
 *
 * @retval	0 if fail - NULL == _cont || NULL == _key || NULL == _elementFound, or if element not found
 *
 * @retval	1 if success
 */
int ContainerInsertElement(Container* _cont, char* _key, void* _element);



/** 
 * @brief Insert element into container
 *
 * @param[in] _cont - Container to print all elements
 *  
 * @return  number of unique elements in container
 *
 * @retval	0 if fail or no elements
 */
size_t ContainerPrintAllElements(Container* _cont);



#endif /*#ifndef __CONTAINER_H__*/




