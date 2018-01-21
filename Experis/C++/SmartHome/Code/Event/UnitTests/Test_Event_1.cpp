#include "Event.h"
#include "../EventAttr/EventAttr.h"
#include <string>
#include <iostream>

using namespace std;




int main()
{
    string time = "12:59:11";
    string type = "SMOKE_DETECTION";
    string room = "12_B";
    string floor = "3";
    Event* event = new Event(time, type, room, floor);
    EventAttr* eventAttr = event->GetAttributes();
    cout << (eventAttr->GetType()) << endl;
    
    return 0;
}
