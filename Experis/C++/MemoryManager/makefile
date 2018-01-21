FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32

PAGE_PATH = ./memPage_t/
POOL_PATH = ./memPool_t/
MNGR_PATH = ./memManager_t/
TEXCEPTION_PATH = ../ExceptionHandler/

objects = memManager_t.o memPage_t.o memPool_t.o TestMemManager.o


TestMemManager: $(objects) 
	g++ $(FLAGS) -o TestMemManager $(objects) 


TestMemManager.o: TestMemManager.cpp $(POOL_PATH)memPool_t.cpp $(POOL_PATH)memPool_t.h $(TEXCEPTION_PATH)TException_t.h
	g++ $(FLAGS) -c  TestMemManager.cpp


memPool_t.o: $(PAGE_PATH)memPage_t.cpp $(POOL_PATH)memPool_t.cpp \
				$(PAGE_PATH)memPage_t.h $(POOL_PATH)memPool_t.h $(MNGR_PATH)memManager_t.h 		
	g++ $(FLAGS) -c  $(POOL_PATH)memPool_t.cpp 
	
	
memPage_t.o: $(PAGE_PATH)memPage_t.cpp $(PAGE_PATH)memPage_t.h $(MNGR_PATH)memManager_t.h 		
	g++ $(FLAGS) -c  $(PAGE_PATH)memPage_t.cpp 
	
	
memManager_t.o: $(MNGR_PATH)memManager_t.cpp $(MNGR_PATH)memManager_t.h		
	g++ $(FLAGS) -c  $(MNGR_PATH)memManager_t.cpp
	
	
clean:
	rm TestMemManager $(objects)	
 







