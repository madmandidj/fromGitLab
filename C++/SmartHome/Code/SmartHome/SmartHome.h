#ifndef __SMART_HOME_H__
#define  __SMART_HOME_H__

#include<string>
#include<vector>

class Hub;
class ConfigLoader;
class Agent;

class SmartHome
{
public:
    SmartHome(std::string _soPath, std::string _iniPath);
    ~SmartHome();
    void LoadSmartHome();
    void Run();
    void Quit();
    void SetLivePrintMode(bool _shouldLivePrint);
    size_t GetNumOfAgents() const;

protected:


private:
    Hub*                m_hub;
    ConfigLoader*       m_configLoader;
    std::vector<Agent*> m_agentContainer;
};




















#endif //#ifndef __SMART_HOME_H__

