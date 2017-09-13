#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../../../CDRDataTypes/Subscriber.h"
#include "../../../CDRDataTypes/Operator.h"
#include <stdlib.h>

typedef struct Container Container;

Container* ContainerCreate(size_t _subscribersCapacity, size_t _operatorsCapacity);

void ContainerDestroy(Container* _cont);

int	ContainerGetElement(Container* _cont, void* _element, void** _subFound);

int ContainerInsertElement(Container* _cont, void* _element);


/*

int	ContainerFindSubscriber(Container* _cont, Subscriber* _sub, Subscriber* _subFound);

int	ContainerFindOperator(Container* _cont, Operator* _oper, Operator* _operFound);

int ContainerUpdateSubscriber(Container* _cont, Subscriber* _sub);

int ContainerUpdateOperator(Container* _cont, Operator* _oper);


*/


#endif /*#ifndef __CONTAINER_H__*/



