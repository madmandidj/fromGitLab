#ifndef __SONY_SD101_H__
#define __SONY_SD101_H__

#include "../../../Agent/Agent.h"
#include<tr1/memory>
//#include "../Payload/Payload.h" 
#include <string>

class SONY_SD101 : public Agent
{
public:
    SONY_SD101(AgentAttr* _agentAttr, Hub* _hub);
    virtual ~SONY_SD101();
    virtual void DoOnEvent(std::tr1::shared_ptr<Event> _event);
    virtual void DoRoutine(); 
//inherited    std::string GenerateTimestamp() const;

protected:


private:
    unsigned int m_sleepSec;

};


extern "C" SONY_SD101* CreateAgent(AgentAttr* _agentAttr, Hub* _hub);

//TODO: extern "C" Payload* CreatePayload() 

#endif //#ifndef __SONY_SD101_H__


