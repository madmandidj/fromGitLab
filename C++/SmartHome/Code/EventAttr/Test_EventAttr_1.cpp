#include "EventAttr.h"
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string timestamp = "12:31:29";
    string type = "SMOKE_DETECTED";
    string room = "11_B";
    string floor = "4";
    
    EventAttr* eventAttr = new EventAttr(timestamp, type, room, floor);
    EventAttr* eventAttr2 = new EventAttr(timestamp, type, room, floor);
    
    cout << eventAttr->GetTimestamp() << endl;
    
    cout << eventAttr->GetType() << endl;
    
    cout << eventAttr->GetRoom() << endl;
    
    cout << eventAttr->GetFloor() << endl;
    
    cout << "eventAttr == eventAttr2 result = " << (*eventAttr == *eventAttr2) << endl;
    
    
    
    EventAttr* eventAttr3 = new EventAttr(timestamp, "BLAH", room, floor);
    
    cout << "eventAttr == eventAttr3 result = " << (*eventAttr == *eventAttr3) << endl;
    
    EventAttr* eventAttr4 = new EventAttr(timestamp, type, "10_B", floor);
    
    cout << "eventAttr < eventAttr2 result = " << (*eventAttr < *eventAttr4) << endl;
    
    
    
    delete eventAttr;
    delete eventAttr2;
    delete eventAttr3;
    
    return 0;
}








