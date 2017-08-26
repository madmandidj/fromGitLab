FLAGS = -g -ansi -pedantic -Wall -Wconversion -std=gnu99
# -std=gnu99 flag is for clockid_t 
INC_PATH = ../../inc/
LIB_PATH = ../../lib/
HEAP_PATH = ../../DS/Heap/
VECTOR_PATH = ../../DS/Vector/
MY_TIME_PATH = ./MyTime/
TASK_PATH = ./Task/
PRIORITY_Q_PATH = ./PriorityQ/

testPE.out: TestPeriodicExecutor.c $(LIB_PATH)libPE.a \
									$(LIB_PATH)libPQ.a \
									$(LIB_PATH)libHeap.a \
									$(LIB_PATH)libVector.a \
									$(LIB_PATH)libTask.a \
									$(LIB_PATH)libMyTime.a 
									
									
	gcc $(FLAGS) -o testPE.out TestPeriodicExecutor.c -L$(LIB_PATH) -lPE \
											 -L$(LIB_PATH) -lPQ \
											 -L$(LIB_PATH) -lHeap \
											 -L$(LIB_PATH) -lVector \
											 -L$(LIB_PATH) -lTask \
											 -L$(LIB_PATH) -lMyTime 
							
							
# Periodic Executor				 
$(LIB_PATH)libPE.a: PeriodicExecutor.o 
	ar -cvq $(LIB_PATH)libPE.a PeriodicExecutor.o
	
PeriodicExecutor.o: PeriodicExecutor.c PeriodicExecutor.h $(PRIORITY_Q_PATH)PriorityQ.h $(TASK_PATH)Task.h
	gcc $(FLAGS) -c PeriodicExecutor.c 
	
	
# Priority Queue	
$(LIB_PATH)libPQ.a: $(PRIORITY_Q_PATH)PriorityQ.o 
	ar -cvq $(LIB_PATH)libPQ.a PriorityQ.o
	
$(PRIORITY_Q_PATH)PriorityQ.o: $(PRIORITY_Q_PATH)PriorityQ.c $(PRIORITY_Q_PATH)PriorityQ.h
	gcc $(FLAGS) -c $(PRIORITY_Q_PATH)PriorityQ.c 


# Heap	
$(LIB_PATH)libHeap.a: $(HEAP_PATH)Heap.o 
	ar -cvq $(LIB_PATH)libHeap.a $(HEAP_PATH)Heap.o
	
Heap.o: $(HEAP_PATH)Heap.c $(INC_PATH)Heap.h
	gcc $(FLAGS) -c $(HEAP_PATH)Heap.c


# Vector
$(LIB_PATH)libVector.a: $(VECTOR_PATH)GenericVector.o 
	ar -cvq $(LIB_PATH)libVector.a $(VECTOR_PATH)GenericVector.o
	
GenericVector.o: $(VECTOR_PATH)GenericVector.c $(INC_PATH)GenericVector.h
	gcc $(FLAGS) -c $(VECTOR_PATH)GenericVector.c


# Task
$(LIB_PATH)libTask.a: $(TASK_PATH)Task.o
	ar -cvq $(LIB_PATH)libTask.a $(TASK_PATH)Task.o
	
Task.o: $(TASK_PATH)Task.c $(TASK_PATH)Task.h 
	gcc $(FLAGS) -c $(TASK_PATH)Task.c 


# My Time
$(LIB_PATH)libMyTime.a: $(MY_TIME_PATH)MyTime.o 
	ar -cvq $(LIB_PATH)libMyTime.a $(MY_TIME_PATH)MyTime.o
	
MyTime.o: $(MY_TIME_PATH)MyTime.c $(MY_TIME_PATH)MyTime.h
	gcc $(FLAGS) -c $(MY_TIME_PATH)MyTime.c

	


clean:
	rm testPE.out $(LIB_PATH)libPE.a $(LIB_PATH)libPQ.a $(LIB_PATH)libHeap.a \
	$(LIB_PATH)libVector.a $(LIB_PATH)libTask.a $(LIB_PATH)libMyTime.a
	rm PeriodicExecutor.o PriorityQ.o $(HEAP_PATH)Heap.o $(VECTOR_PATH)GenericVector.o $(TASK_PATH)Task.o $(MY_TIME_PATH)MyTime.o
