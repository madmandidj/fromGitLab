FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32

PAGE_PATH = ./memPage_t/
POOL_PATH = ./memPool_t/
MNGR_PATH = ./memManager_t/

objects = memPage_t.o memPool_t.o TestMemManager.o


TestMemManager: $(objects) 
	g++ $(FLAGS) -o TestMemManager  $(objects) 


memPool_t.o: $(PAGE_PATH)memPage_t.cpp $(POOL_PATH)memPool_t.cpp $(PAGE_PATH)memPage_t.h $(POOL_PATH)memPool_t.h $(MNGR_PATH)memManager_t.h 		
	g++ $(FLAGS) -c  $(POOL_PATH)memPool_t.cpp 
	
	
memPage_t.o: $(PAGE_PATH)memPage_t.cpp $(PAGE_PATH)memPage_t.h $(MNGR_PATH)memManager_t.h 		
	g++ $(FLAGS) -c  $(PAGE_PATH)memPage_t.cpp 
	
	
clean:
	rm TestMemManager $(objects)	








