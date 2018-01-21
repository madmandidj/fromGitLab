FLAGS = -ansi -pedantic -Wall -pthread
objects = Mutex.o Test_Mutex.o

Test_Mutex.out: $(objects)
	g++ $(FLAGS) $(objects) -o Test_Mutex.out 
	
Test_Mutex.o: Test_Mutex.cpp Mutex.h
	g++ -c $(FLAGS) Test_Mutex.cpp
	
Mutex.o: Mutex.cpp Mutex.h
	g++ -c $(FLAGS) Mutex.cpp

clean:
	rm Test_Mutex.out $(objects) 
