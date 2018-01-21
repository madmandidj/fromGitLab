FLAGS = -ansi -pedantic -Wall -pthread -g -std=c++98
SYNCEXC_PATH = ../SyncExceptions/
MUTEX_PATH = ../Mutex/
objects = SyncExceptions.o Mutex.o Guard.o Test_Guard.o

Test_Guard.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_Guard.out 
	
Test_Guard.o: Test_Guard.cpp Guard.h $(MUTEX_PATH)Mutex.h 
	g++ -c $(FLAGS) Test_Guard.cpp
	
Guard.o: Guard.cpp Guard.h $(MUTEX_PATH)Mutex.h $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) Guard.cpp
	
Mutex.o: $(MUTEX_PATH)Mutex.cpp $(MUTEX_PATH)Mutex.h $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) $(MUTEX_PATH)Mutex.cpp
	
SyncExceptions.o: $(SYNCEXC_PATH)SyncExceptions.cpp $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) $(SYNCEXC_PATH)SyncExceptions.cpp

clean:
	rm Test_Guard.out $(objects) 
