#ifndef __HITACHI_SPRINK2000_H__
#define __HITACHI_SPRINK2000_H__

#include "../../../Agent/Agent.h"
#include<tr1/memory>
//#include "../Payload/Payload.h"
#include <string>

class HITACHI_SPRINK2000 : public Agent
{
public:

    HITACHI_SPRINK2000(AgentAttr* _agentAttr, Hub* _hub);
    virtual ~HITACHI_SPRINK2000();
    
    virtual void DoOnEvent(std::tr1::shared_ptr<Event> _event);
    virtual void DoRoutine(); 
    
//inherited    std::string GenerateTimestamp() const;

protected:


private:
    

};


extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, Hub* _hub);


#endif //#ifndef __HITACHI_SPRINK2000_H__


