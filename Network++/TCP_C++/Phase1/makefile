all: ServerTest.out	ClientTest.out

ServerTest.out:
	g++ -ansi -pedantic -Wall -g -o ServerTest.out Test_Server.cpp \
													ServerCPP.cpp \
													ServerSock.cpp\
													CommSock.cpp\
													SockAddrIn_t.cpp\
													FD_t.cpp
									
ClientTest.out:
	g++ -ansi -pedantic -Wall -g -o ClientTest.out Test_Client.cpp\
													ClientCPP.cpp\
													ClientSock.cpp\
													SockAddrIn_t.cpp\
													FD_t.cpp

clean:
	rm ClientTest.out ServerTest.out
