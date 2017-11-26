FLAGS = -ansi -pedantic -Wall -pthread -g -std=c++98
SYNCEXC_PATH = ../SyncExceptions/
MUTEX_PATH = ../Mutex/
objects = SyncExceptions.o Mutex.o CondVar.o Test_CondVar.o

Test_CondVar.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_CondVar.out 
	
Test_CondVar.o: Test_CondVar.cpp CondVar.h $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) Test_CondVar.cpp
	
CondVar.o: CondVar.cpp CondVar.h $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) CondVar.cpp
	
Mutex.o: $(MUTEX_PATH)Mutex.cpp $(MUTEX_PATH)Mutex.h
	g++ -c $(FLAGS) $(MUTEX_PATH)Mutex.cpp
	
SyncExceptions.o: $(SYNCEXC_PATH)SyncExceptions.cpp $(SYNCEXC_PATH)SyncExceptions.h
	g++ -c $(FLAGS) $(SYNCEXC_PATH)SyncExceptions.cpp

clean:
	rm Test_CondVar.out $(objects) 








