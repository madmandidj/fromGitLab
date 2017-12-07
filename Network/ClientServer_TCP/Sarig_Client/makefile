IP = 127.0.0.1
PORT = 1234

all: Client.c Client.h TrafficSim.c
	gcc TrafficSim.c Client.c -o TrafficSim.out

run:
	./TrafficSim.out $(IP) $(PORT)
	
clean:
	rm -f ./*.out
	
