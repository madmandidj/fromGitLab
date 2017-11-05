#ifndef __SONY_SD101_H__
#define __SONY_SD101_H__

#include "../Agent/Agent.h"
//#include "../Payload/Payload.h"
#include <string>

class SONY_SD101 : public Agent
{
public:
//    class Payload_SD101 : public Payload
//    {
//    public:
//        Payload_SD101();
//        virtual ~Payload_SD101;
//        virtual GeneratePayload();
//    
//    protected:
//    
//    
//    private:
//        int m_smokePercentage;
//    
//    };
    SONY_SD101();
    virtual ~SONY_SD101();
    /*
    virtual EventAttr* GenerateEventAttr(std::string _type, std::string _room, std::string _floor);
    */
//inherited    std::string GenerateTimestamp() const;

protected:


private:
    

};




#endif //#ifndef __SONY_SD101_H__


