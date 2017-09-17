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

size_t ContainerPrintAllElements(Container* _cont);

#endif /*#ifndef __CONTAINER_H__*/



