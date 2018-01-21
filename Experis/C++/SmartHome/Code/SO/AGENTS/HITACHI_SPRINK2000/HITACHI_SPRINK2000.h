#ifndef __HITACHI_SPRINK2000_H__
#define __HITACHI_SPRINK2000_H__

#include "../../../Agent/Agent.h"
//#include "../Payload/Payload.h"
#include<tr1/memory>
#include <string>


class HITACHI_SPRINK2000 : public Agent
{
public:
	virtual ~HITACHI_SPRINK2000();
	HITACHI_SPRINK2000(AgentAttr* _agentAttr, HubInterface* _hub); //Throws std::runtime_error
    virtual void DoOnEvent(std::tr1::shared_ptr<Event> _event);
    virtual void DoRoutine(); // Throws    
	//inherited    std::string GenerateTimestamp() const;

protected:


private:
    

};

extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, HubInterface* _hub); //Throws std::bad_alloc


#endif //#ifndef __HITACHI_SPRINK2000_H__


