#include "ConfigLoader.h"
#include<iostream>
#include <fstream>

using namespace std;

ConfigLoader::ConfigLoader(string _soPath, string _iniPath)
{	
	m_soPath = _soPath;
	
	m_iniPath = _iniPath;	
	
	m_line = "";
	
	m_linePosition = 0;
}


ConfigLoader::~ConfigLoader()
{
    //Empty
}


bool ConfigLoader::LoadConfig(vector<Agent*>& _agents, Hub* _hub)
{
	m_fileStream.open(m_iniPath.c_str(), ios_base::in); 
	
	if (false == m_fileStream.good())
	{
		return false;
	}
	
	
	LoadAgents();
	
	return true;
}


bool ConfigLoader::LoadAgents()
{
	bool isEndOfAgent = false;
	size_t position = 0;
	size_t leftPos = 0;
	size_t rightPos = 0;
	string temp_ID;
	string temp_type;
	string temp_room;
	string temp_floor;
	string temp_log;
	string temp_config;
	string temp_str;
	
	while(1)
	{
	    //Get next line and check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
        leftPos = 0;
        rightPos = 0;

        //Get ID
		leftPos = m_line.find_first_of("[", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		rightPos = m_line.find_first_of("]", leftPos + 1);
		temp_ID = m_line.substr(leftPos + 1, rightPos - leftPos - 1);
		cout << temp_ID << endl;
		
		//Get Type
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_type = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		cout << temp_type << endl;
		
		//Get Room
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_room = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		cout << temp_room << endl;
		
		//Get Floor
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_floor = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		cout << temp_floor << endl;
		
		//Check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
		    continue;
		}
		
		
		leftPos = 0;
        rightPos = 0;
		rightPos = m_line.find_first_of("=", rightPos);
		if (string::npos == rightPos)
		{
			return false;
		}
		temp_str = m_line.substr(leftPos, rightPos - 1);
		//Check if log
		if (temp_str == "log")
		{
		    temp_log = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		    cout << temp_log << endl;
		}
		//Check if config
		else if(temp_str == "config")
		{
		    temp_config = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		    cout << temp_config << endl;
		}
		else
		{
		    continue;
		}
		
		//Check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
		    continue;
		}
		
		
		leftPos = 0;
        rightPos = 0;
		rightPos = m_line.find_first_of("=", rightPos);
		if (string::npos == rightPos)
		{
			return false;
		}
		temp_str = m_line.substr(leftPos, rightPos - 1);
		//Check if Config
		if (temp_str == "config")
		{
		    temp_config = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		    cout << temp_config << endl;
		}
		
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
		    continue;
		}
		
//		break; //remove
	}
}


bool ConfigLoader::LoadSharedObject()
{


}




