objects = EventAttr.o Event.o AgentAttr.o Agent.o Hub.o ConfigLoader.o SmartHome.o EyalsSmartHome.o
FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32 -pthread
AGENT_PATH = ./Agent/
AGENT_ATTR_PATH = ./AgentAttr/
CONFLOAD_PATH = ./ConfigLoader/
EVENT_PATH = ./Event/
EVENT_ATTR_PATH = ./EventAttr/
HUB_PATH = ./Hub/
SMART_HOME_PATH = ./SmartHome/

agentObjects = EventAttr.o Event.o AgentAttr.o Agent.o Hub.o
AGENT_FLAGS = -c -ansi -pedantic -Wall -Wconversion -m32 -fPIC
SO_FLAGS = -shared
HIT_SPNK_PATH = ./SO/AGENTS/HITACHI_SPRINK2000/
SONY_SD101_PATH = ./SO/AGENTS/SONY_SD101/

all:EyalsSmartHome HITACHI_SPRINK2000.so SONY_SD101.so

#EyalsSmartHome: $(objects) HITACHI_SPRINK2000.o HITACHI_SPRINK2000.so SONY_SD101.o SONY_SD101.so
EyalsSmartHome: $(objects)
	g++ $(FLAGS) -o EyalsSmartHome $(objects) -ldl

EyalsSmartHome.o: EyalsSmartHome.cpp $(SMART_HOME_PATH)SmartHome.h $(CONFLOAD_PATH)ConfigLoader.h 
	g++ $(FLAGS) -c  EyalsSmartHome.cpp

EventAttr.o: $(EVENT_ATTR_PATH)EventAttr.cpp $(EVENT_ATTR_PATH)EventAttr.h    
	g++ $(FLAGS) -c  $(EVENT_ATTR_PATH)EventAttr.cpp
	
Event.o: $(EVENT_PATH)Event.cpp $(EVENT_PATH)Event.h $(EVENT_ATTR_PATH)EventAttr.h   
	g++ $(FLAGS) -c  $(EVENT_PATH)Event.cpp
	
AgentAttr.o: $(AGENT_ATTR_PATH)AgentAttr.cpp $(AGENT_ATTR_PATH)AgentAttr.h   
	g++ $(FLAGS) -c  $(AGENT_ATTR_PATH)AgentAttr.cpp
	
Agent.o: $(AGENT_PATH)Agent.cpp $(AGENT_PATH)Agent.h $(HUB_PATH)Hub.h $(AGENT_ATTR_PATH)AgentAttr.h\
			$(EVENT_PATH)Event.h $(EVENT_ATTR_PATH)EventAttr.h   
	g++ $(FLAGS) -c  $(AGENT_PATH)Agent.cpp
	
Hub.o: $(HUB_PATH)Hub.cpp $(HUB_PATH)Hub.h $(AGENT_PATH)Agent.h $(EVENT_PATH)Event.h \
			$(EVENT_ATTR_PATH)EventAttr.h
	g++ $(FLAGS) -c  $(HUB_PATH)Hub.cpp
	
ConfigLoader.o: $(CONFLOAD_PATH)ConfigLoader.cpp $(CONFLOAD_PATH)ConfigLoader.h $(HUB_PATH)Hub.h\
					$(AGENT_ATTR_PATH)AgentAttr.h $(AGENT_PATH)Agent.h    
	g++ $(FLAGS) -c  $(CONFLOAD_PATH)ConfigLoader.cpp
	
SmartHome.o: $(SMART_HOME_PATH)SmartHome.cpp $(SMART_HOME_PATH)SmartHome.h   
	g++ $(FLAGS) -c  $(SMART_HOME_PATH)SmartHome.cpp
	
	
	
HITACHI_SPRINK2000.o: $(HIT_SPNK_PATH)HITACHI_SPRINK2000.cpp $(EVENT_PATH)Event.h $(EVENT_ATTR_PATH)EventAttr.h\
                       $(AGENT_PATH)Agent.h $(HUB_PATH)Hub.h $(AGENT_ATTR_PATH)AgentAttr.h 
	g++ $(AGENT_FLAGS) $(HIT_SPNK_PATH)HITACHI_SPRINK2000.cpp	
	
HITACHI_SPRINK2000.so: HITACHI_SPRINK2000.o
	g++ -shared -o HITACHI_SPRINK2000.so HITACHI_SPRINK2000.o\
						Agent.o AgentAttr.o Hub.o Event.o EventAttr.o
	mv HITACHI_SPRINK2000.so ./SO/HITACHI_SPRINK2000.so
	
SONY_SD101.o: $(SONY_SD101_PATH)SONY_SD101.cpp $(EVENT_PATH)Event.h $(EVENT_ATTR_PATH)EventAttr.h\
                       $(AGENT_PATH)Agent.h $(HUB_PATH)Hub.h $(AGENT_ATTR_PATH)AgentAttr.h 
	g++ $(AGENT_FLAGS) $(SONY_SD101_PATH)SONY_SD101.cpp	
	
SONY_SD101.so: SONY_SD101.o
	g++ -shared -o SONY_SD101.so SONY_SD101.o\
						Agent.o AgentAttr.o Hub.o Event.o EventAttr.o
	mv SONY_SD101.so ./SO/SONY_SD101.so
#	mv SONY_SD101.o ./obj/SONY_SD101.o
#	mv HITACHI_SPRINK2000.o ./obj/HITACHI_SPRINK2000.o
#	mv EyalsSmartHome.o ./obj/EyalsSmartHome.o
#	mv EventAttr.o ./obj/EventAttr.o
#	mv Event.o ./obj/Event.o
#	mv AgentAttr.o ./obj/AgentAttr.o
#	mv Agent.o ./obj/Agent.o
#	mv Hub.o ./obj/Hub.o
#	mv ConfigLoader.o ./obj/ConfigLoader.o
#	mv SmartHome.o ./obj/SmartHome.o


clean:
	rm EyalsSmartHome $(objects) SONY_SD101.o ./SO/SONY_SD101.so \
							HITACHI_SPRINK2000.o ./SO/HITACHI_SPRINK2000.so
#clean:
#	rm EyalsSmartHome
 







