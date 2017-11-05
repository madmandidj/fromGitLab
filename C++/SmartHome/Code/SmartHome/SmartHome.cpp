#include "SmartHome.h"
#include "../Hub/Hub.h"
#include "../ConfigLoader/ConfigLoader.h"
#include<string>


SmartHome::SmartHome(std::string _soPath, std::string _iniPath)
{
    m_hub = new Hub();
    if (0 == m_hub)
    {
        //TODO: handle bad alloc
    }
    
    m_configLoader = new ConfigLoader(_soPath, _iniPath);
    if (0 == m_configLoader)
    {
        delete m_hub;
        //TODO: handle bad alloc
    }
}


SmartHome::~SmartHome()
{
    delete m_hub;
    delete m_configLoader;
}


SmartHome::LoadSmartHome()
{
    m_configLoader->LoadConfig();
}


void SmartHome::Run()
{
    
}


void SmartHome::Quit()
{

}


void SmartHome::SetLivePrintMode(bool _shouldLivePrint)
{
    m_hub->SetLivePrintMode(_shouldLivePrint);
}




















