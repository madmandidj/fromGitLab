FLAGS = -g -ansi -pedantic -Wall -Wconversion -m32 -pthread
AGENT_PATH = ./Agent/
AGENT_ATTR_PATH = ./AgentAttr/
CONFLOAD_PATH = ./ConfigLoader/
EVENT_PATH = ./Event/
EVENT_ATTR_PATH = ./EventAttr/
HUB_PATH = ./Hub/
SMART_HOME_PATH = ./SmartHome/

objects = EventAttr.o Event.o AgentAttr.o Agent.o Hub.o ConfigLoader.o SmartHome.o EyalsSmartHome.o

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

clean:
	rm EyalsSmartHome $(objects)	
 







