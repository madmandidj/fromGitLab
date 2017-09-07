#ifndef __BARRIER_H__
#define __BARRIER_H__

typedef struct Barrier Barrier;

typedef int (*BarrierAction)(void* _context);

Barrier* BarrierCreate(unsigned int _capacity);

void BarrierDestroy(Barrier* _barrier);

int BarrierWait(Barrier* _barrier, BarrierAction _func, void* _context);

#endif /* #ifndef __BARRIER_H__ */





