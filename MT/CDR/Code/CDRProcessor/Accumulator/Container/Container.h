#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../../../CDRDataTypes/Subscriber.h"
#include "../../../CDRDataTypes/Operator.h"

typedef struct Container Container;

Container* ContainerCreate(size_t _subscribersCapacity, size_t _operatorsCapacity);

Container* ContainerDestroy(Container* _cont);

int	ContainerFindSubscriber(Container* _cont, Subscriber* _subscriber);

int	ContainerFindOperator(Container* _cont, Operator* _operator);

int ContainerUpdateSubscriber(Container* _cont, Subscriber* _subscriber);

int ContainerUpdateOperator(Container* _cont, Operator* _operator);





#endif /*#ifndef __CONTAINER_H__*/



