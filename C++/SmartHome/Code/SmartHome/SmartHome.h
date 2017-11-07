#ifndef __SMART_HOME_H__
#define  __SMART_HOME_H__

#include<string>
#include<vector>
#include<tr1/memory>

class Hub;
class ConfigLoader;
class Agent;

class SmartHome
{
public:
    SmartHome(std::string _soPath, std::string _iniPath); //Throws std::bad_alloc
    ~SmartHome();
    void LoadSmartHome(); //Throws std::bad_alloc
    void Run();
    void Quit();
    void SetLivePrintMode(bool _shouldLivePrint);
    size_t GetNumOfAgents() const;

protected:


private:
    Hub* 				m_hub;
    ConfigLoader*       m_configLoader;
    std::vector<Agent*> m_agentContainer;
};




















#endif //#ifndef __SMART_HOME_H__

