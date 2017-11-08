#include "./SmartHome/SmartHome.h"
#include "./ConfigLoader/ConfigLoader.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <exception>

using namespace std;

int main()
{
    string finishProgram;
    
    string curDirName = get_current_dir_name();
    
    string soPath = curDirName + "/SO/";
    
    string iniFilePath = curDirName + "/INI/Config.ini"; 

	SmartHome* smrHome;
    
    try
    {
    	smrHome = new SmartHome(soPath.c_str(), iniFilePath.c_str());
    }
    catch(std::exception& _exc)
    {
    	cout << _exc.what() << endl;
    	return 0;
    }
    
    try
    {    
    	smrHome->LoadSmartHome();
    }
    catch(std::exception& _exc)
    {
    	delete smrHome;
    	return 0;
    }
    
    try
    {
    	smrHome->Run();
    }
    catch(std::exception& _exc)
    {
    	delete smrHome;
    	return 0;
    }

    cin >> finishProgram;
    
    delete smrHome;
                                
    return 0;
}
