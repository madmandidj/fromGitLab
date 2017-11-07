#ifndef __HITACHI_SPRINK2000_H__
#define __HITACHI_SPRINK2000_H__

#include "../../../Agent/Agent.h"
#include<tr1/memory>
//#include "../Payload/Payload.h"
#include <string>

class HITACHI_SPRINK2000 : public Agent
{
public:
//    HITACHI_SPRINK2000(AgentAttr* _agentAttr, Hub* _hub);
	virtual ~HITACHI_SPRINK2000();
	HITACHI_SPRINK2000(AgentAttr* _agentAttr, HubInterface* _hub);
    virtual void DoOnEvent(std::tr1::shared_ptr<Event> _event); // Throws
    virtual void DoRoutine(); // Throws    
//inherited    std::string GenerateTimestamp() const;

protected:


private:
    

};


//extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, Hub* _hub);
extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, HubInterface* _hub);


#endif //#ifndef __HITACHI_SPRINK2000_H__


