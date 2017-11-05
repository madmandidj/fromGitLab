#include "./SmartHome/SmartHome.h"
#include "./ConfigLoader/ConfigLoader.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SmartHome* smrHome = new SmartHome("/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/Code/SO/",
                            "/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/Code/INI/Config.ini");
    smrHome->LoadSmartHome();
    
    cout << smrHome->GetNumOfAgents() << endl;
    
    delete smrHome;
                                
    return 0;
}
