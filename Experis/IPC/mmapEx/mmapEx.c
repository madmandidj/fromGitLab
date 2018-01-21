#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MEM_MAP_LENGTH 512



int main()
{
	int fd;
	int shmid;
	char* addr;

	fd = open("TempFile", O_RDWR);
	
	if (-1 == fd)
	{
		printf("fd failed\n");
	}
	
	addr = mmap(NULL, MEM_MAP_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (MAP_FAILED == addr)
	{
		printf("addr failed\n");
	}
	
	*addr = 1;
	
	printf("%d\n", *addr);

	
	return 0;
}













