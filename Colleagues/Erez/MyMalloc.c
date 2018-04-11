#include <stdlib.h>
#include <stdio.h>

void* mymalloc_nextAddress = NULL;

void InitMyMalloc(void* _memory, size_t _blockSize, size_t _totalBlocks)
{
    int i;
    mymalloc_nextAddress = _memory;
    for(i = 0 ; i < _totalBlocks-1 ; ++i)
    {
        *(void**)((char*)mymalloc_nextAddress + i*_totalBlocks) = (char*)mymalloc_nextAddress + (i+1)*_totalBlocks;
    }
    *(void**)((char*)mymalloc_nextAddress + i*_totalBlocks) = NULL;
}

void Free(void* _address)
{
    *(void**)_address = mymalloc_nextAddress;
    mymalloc_nextAddress = _address;
}

void* Allocate()
{
    void* allocated = mymalloc_nextAddress;
    mymalloc_nextAddress = (mymalloc_nextAddress) ? *(void**)mymalloc_nextAddress : NULL;
    return allocated;
}

int main()
{
    void* addr[5];
    void* memory = malloc(1000*1000);
    InitMyMalloc(memory, 1000, 1000);
    
    addr[0] = Allocate();
    printf("%p\n", addr[0]);
    addr[1] = Allocate();
    printf("%p\n", addr[1]);
    addr[2] = Allocate();
    printf("%p\n", addr[2]);
    Free(addr[0]);
    addr[3] = Allocate();
    printf("%p\n", addr[3]);
    addr[4] = Allocate();
    printf("%p\n", addr[4]);
    
    free(memory);
    
    return 0;
}
