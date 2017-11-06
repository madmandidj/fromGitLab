g++ -c -Wall -Werror -fPIC ../../../Agent/Agent.cpp
g++ -c -Wall -Werror -fPIC ../../../AgentAttr/AgentAttr.cpp
g++ -c -Wall -Werror -fPIC ../../../Hub/Hub.cpp
g++ -c -Wall -Werror -fPIC ../../../Event/Event.cpp
g++ -c -Wall -Werror -fPIC ../../../EventAttr/EventAttr.cpp
g++ -c -Wall -Werror -fPIC SONY_SD101.cpp
g++ -shared -o SONY_SD101.so SONY_SD101.o Agent.o AgentAttr.o Hub.o Event.o EventAttr.o
# g++ -shared -o SONY_SD101.so SONY_SD101.o


