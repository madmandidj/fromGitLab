FLAGS = -ansi -pedantic -Wall -pthread -g -std=c++98
SYNCEXC_PATH = ../SyncExceptions/
MUTEX_PATH = ../Mutex/
CONDV_PATH = ../CondVar/
objects = SyncExceptions.o Mutex.o CondVar.o Test_Thread.o

Test_Thread.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_Thread.out 
	
Test_Thread.o: Test_Thread.cpp Thread.h $(CONDV_PATH)CondVar.h $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) Test_Thread.cpp
	
CondVar.o: $(CONDV_PATH)CondVar.cpp $(CONDV_PATH)CondVar.h $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) $(CONDV_PATH)CondVar.cpp
	
Mutex.o: $(MUTEX_PATH)Mutex.cpp $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) $(MUTEX_PATH)Mutex.cpp
	
SyncExceptions.o: $(SYNCEXC_PATH)SyncExceptions.cpp $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) $(SYNCEXC_PATH)SyncExceptions.cpp

clean:
	rm Test_Thread.out $(objects) 








