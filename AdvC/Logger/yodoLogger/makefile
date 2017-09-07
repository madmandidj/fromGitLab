
FLAGS= -ansi -g -pedantic -Wvariadic-macros -pthread -std=gnu99


testlogger: config.o logger.o testlogger.o  
	gcc $(FLAGS) -o testlogger testlogger.o logger.o config.o


testlogger.o: testlogger.c logger.h
	gcc $(FLAGS) -c testlogger.c
	    
	    
logger.o: logger.c logger.h config.h
	gcc $(FLAGS) -c logger.c


config.o: config.c config.h
	gcc $(FLAGS) -c config.c


clean:
	rm config.o
	rm logger.o
	rm testlogger.o
	rm testlogger
	
	
