#ifndef __SONY_SD101_H__
#define __SONY_SD101_H__

#include "../../Agent/Agent.h"
//#include "../Payload/Payload.h"
#include <string>

class SONY_SD101 : public Agent
{
public:

    SONY_SD101(AgentAttr* _agentAttr, Hub* _hub);
    virtual ~SONY_SD101();
    
    virtual void DoOnEvent(const Event* _event);
    
//inherited    std::string GenerateTimestamp() const;

protected:


private:
    

};


extern "C" SONY_SD101* CreateAgent(AgentAttr* _agentAttr, Hub* _hub);


#endif //#ifndef __SONY_SD101_H__


