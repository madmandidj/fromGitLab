FLAGS = -ansi -pedantic -Wall -pthread
SYNCEXC_PATH = ../SyncExceptions/
objects = SyncExceptions.o Mutex.o Test_Mutex.o

Test_Mutex.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_Mutex.out 
	
Test_Mutex.o: Test_Mutex.cpp Mutex.h
	g++ -c $(FLAGS) Test_Mutex.cpp
	
Mutex.o: Mutex.cpp Mutex.h $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) Mutex.cpp

SyncExceptions.o: $(SYNCEXC_PATH)SyncExceptions.cpp $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) $(SYNCEXC_PATH)SyncExceptions.cpp

clean:
	rm Test_Mutex.out $(objects) 
