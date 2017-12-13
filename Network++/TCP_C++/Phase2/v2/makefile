FLAGS = -ansi -pedantic -Wall -g
################################################
CLIENT_PATH = ./ClientCPP/
CLIENT_SOCK_PATH = ./ClientSock/
SERVER_PATH = ./ServerCPP/
SERVER_SOCK_PATH = ./ServerSock/
COMM_SOCK_PATH = ./CommSock/
SOCKET_T_PATH = ./Socket_t/
SOCKADDRIN_T_PATH = ./SockAddrIn_t/
FD_SET_PATH = ./FDSet_t/
FD_T_PATH = ./FD_t/
NET_EXC_PATH = ./NetExceptions/
################################################
AllObjects = FD_t.o FDSet_t.o SockAddrIn_t.o CommSock.o ServerSock.o ServerCPP.o Test_Server.o ClientSock.o ClientCPP.o Test_Client.o
ServerObjects = FD_t.o FDSet_t.o SockAddrIn_t.o CommSock.o ServerSock.o ServerCPP.o Test_Server.o
ClientObjects = FD_t.o SockAddrIn_t.o ClientSock.o ClientCPP.o Test_Client.o
################################################
all: ServerTest.out ClientTest.out
################################################
ServerTest.out: $(ServerObjects)
	g++ $(FLAGS) -o ServerTest.out $(ServerObjects)

Test_Server.o: Test_Server.cpp $(SERVER_PATH)ServerCPP.h
	g++ $(FLAGS) -o Test_Server.o -c Test_Server.cpp

ServerCPP.o: $(SERVER_PATH)ServerCPP.cpp $(SERVER_PATH)ServerCPP.h $(SERVER_SOCK_PATH)ServerSock.h\
				$(COMM_SOCK_PATH)CommSock.h $(SOCKET_T_PATH)Socket_t.h $(FD_T_PATH)FD_t.h
	g++ $(FLAGS) -o ServerCPP.o -c $(SERVER_PATH)ServerCPP.cpp

ServerSock.o: $(SERVER_SOCK_PATH)ServerSock.cpp $(SERVER_SOCK_PATH)ServerSock.h $(FD_T_PATH)FD_t.h\
				$(COMM_SOCK_PATH)CommSock.h $(SOCKET_T_PATH)Socket_t.h
	g++ $(FLAGS) -o ServerSock.o -c $(SERVER_SOCK_PATH)ServerSock.cpp

CommSock.o: $(COMM_SOCK_PATH)CommSock.cpp $(COMM_SOCK_PATH)CommSock.h $(FD_T_PATH)FD_t.h\
				$(SOCKET_T_PATH)Socket_t.h
	g++ $(FLAGS) -o CommSock.o -c $(COMM_SOCK_PATH)CommSock.cpp

SockAddrIn_t.o: $(SOCKADDRIN_T_PATH)SockAddrIn_t.cpp $(SOCKADDRIN_T_PATH)SockAddrIn_t.h
	g++ $(FLAGS) -o SockAddrIn_t.o -c $(SOCKADDRIN_T_PATH)SockAddrIn_t.cpp

FDSet_t.o: $(FD_SET_PATH)FDSet_t.cpp $(FD_SET_PATH)FDSet_t.h $(FD_T_PATH)FD_t.h $(SOCKET_T_PATH)Socket_t.h
	g++ $(FLAGS) -o FDSet_t.o -c $(FD_SET_PATH)FDSet_t.cpp

FD_t.o: $(FD_T_PATH)FD_t.cpp $(FD_T_PATH)FD_t.h
	g++ $(FLAGS) -o FD_t.o -c $(FD_T_PATH)FD_t.cpp
################################################
ClientTest.out: $(ClientObjects)
	g++ $(FLAGS) -o ClientTest.out $(ClientObjects)

Test_Client.o: Test_Client.cpp $(CLIENT_PATH)ClientCPP.h
	g++ $(FLAGS) -o Test_Client.o -c Test_Client.cpp

ClientCPP.o: $(CLIENT_PATH)ClientCPP.cpp $(CLIENT_PATH)ClientCPP.h $(CLIENT_SOCK_PATH)ClientSock.h
	g++ $(FLAGS) -o ClientCPP.o -c $(CLIENT_PATH)ClientCPP.cpp

ClientSock.o: $(CLIENT_SOCK_PATH)ClientSock.cpp $(CLIENT_SOCK_PATH)ClientSock.h $(FD_T_PATH)FD_t.h\
				$(SOCKET_T_PATH)Socket_t.h $(NET_EXC_PATH)NetExceptions.h
	g++ $(FLAGS) -o ClientSock.o -c $(CLIENT_SOCK_PATH)ClientSock.cpp
################################################
clean:
	rm ClientTest.out ServerTest.out $(AllObjects)





















