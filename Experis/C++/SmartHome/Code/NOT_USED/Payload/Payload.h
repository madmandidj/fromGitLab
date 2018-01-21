#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__


class Payload
{
public:
    virtual ~Payload();
    Payload();
    virtual GeneratePayload() = 0;

protected:


private:
    Payload(const Payload& _payload);
    Payload& operator=(const Payload& _payload);

};























#endif //#ifndef __PAYLOAD_H__

