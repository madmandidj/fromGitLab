#include "./SmartHome/SmartHome.h"
#include "./ConfigLoader/ConfigLoader.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
    string finishProgram;
    
    string curDirName = get_current_dir_name();
    
    string soPath = curDirName + "/SO/";
    
    string iniFilePath = curDirName + "/INI/Config.ini";
    
    cout << curDirName << endl;  
    
    SmartHome* smrHome = new SmartHome(soPath.c_str(), iniFilePath.c_str());
    
//    smrHome->SetLivePrintMode(false);
    
    smrHome->LoadSmartHome();
    
    smrHome->Run();

    cin >> finishProgram;
    
    delete smrHome;
                                
    return 0;
}
