#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../../../CDRDataTypes/Subscriber.h"
#include "../../../CDRDataTypes/Operator.h"
#include "./HashMap/HashMap.h"
#include <stdlib.h>

typedef struct Container Container;

Container* ContainerCreate(size_t _capacity, EqualityFunction _func);

void ContainerDestroy(Container* _cont);

int	ContainerGetElement(Container* _cont, char* _key, void** _elementFound);

int ContainerInsertElement(Container* _cont, char* _key, void* _element);


/*

int	ContainerFindSubscriber(Container* _cont, Subscriber* _sub, Subscriber* _subFound);

int	ContainerFindOperator(Container* _cont, Operator* _oper, Operator* _operFound);

int ContainerUpdateSubscriber(Container* _cont, Subscriber* _sub);

int ContainerUpdateOperator(Container* _cont, Operator* _oper);


*/


#endif /*#ifndef __CONTAINER_H__*/



