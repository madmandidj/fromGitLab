#include "SyncExceptions.h"
namespace advcpp
{
/////////////////////////////////////////////////////////////////
////Mutex sync exceptions definitions
const char* Mutex_NoResources_Exc::what() const ENVIRONMENT_NOEXC
{
	return "No resources to create another mutex";
}

const char* Mutex_NoMemory_Exc::what() const ENVIRONMENT_NOEXC
{
	return "No available memory to create another mutex";
}
/////////////////////////////////////////////////////////////////
////CondVar sync exceptions definitions
const char* CondVar_NoResources_Exc::what() const ENVIRONMENT_NOEXC
{
	return "No resources to create another condvar";
}

const char* CondVar_NoMemory_Exc::what() const ENVIRONMENT_NOEXC
{
	return "No available memory to create another condvar";
}
/////////////////////////////////////////////////////////////////
////Thread sync exceptions definitions
const char* Thread_NoResources_Exc::what() const ENVIRONMENT_NOEXC
{
	return "No resources to create another thread";
}










}//namespace advcpp


