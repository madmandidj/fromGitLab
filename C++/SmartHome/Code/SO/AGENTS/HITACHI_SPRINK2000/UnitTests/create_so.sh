g++ -c -Wall -Werror -fPIC ../../../Agent/Agent.cpp
g++ -c -Wall -Werror -fPIC ../../../AgentAttr/AgentAttr.cpp
g++ -c -Wall -Werror -fPIC ../../../Hub/Hub.cpp
g++ -c -Wall -Werror -fPIC ../../../Event/Event.cpp
g++ -c -Wall -Werror -fPIC ../../../EventAttr/EventAttr.cpp
g++ -c -Wall -Werror -fPIC HITACHI_SPRINK2000.cpp
g++ -shared -o HITACHI_SPRINK2000.so HITACHI_SPRINK2000.o Agent.o AgentAttr.o Hub.o Event.o EventAttr.o
# g++ -shared -o SONY_SD101.so SONY_SD101.o


