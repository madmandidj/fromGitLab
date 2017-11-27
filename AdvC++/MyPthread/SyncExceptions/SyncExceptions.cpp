#include "SyncExceptions.h"
namespace advcpp
{

/////////////////////////////////////////////////////////////////
////Mutex sync exceptions definitions
#if (defined (__linux__))
    const char* Mutex_NoResources_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    const char* Mutex_NoResources_Exc::what() const _NOEXCEPT
#endif
{
	return "No resources to create another mutex";
}

#if (defined (__linux__))
    const char* Mutex_NoMemory_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    const char* Mutex_NoMemory_Exc::what() const _NOEXCEPT
#endif
{
	return "No available memory to create another mutex";
}
/////////////////////////////////////////////////////////////////
////CondVar sync exceptions definitions
#if (defined (__linux__))
    const char* CondVar_NoResources_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    const char* CondVar_NoResources_Exc::what() const _NOEXCEPT
#endif
{
	return "No resources to create another condvar";
}

#if (defined (__linux__))
    const char* CondVar_NoMemory_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    const char* CondVar_NoMemory_Exc::what() const _NOEXCEPT
#endif
{
	return "No available memory to create another condvar";
}
/////////////////////////////////////////////////////////////////
////Thread sync exceptions definitions
#if (defined (__linux__))
    const char* Thread_NoResources_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    const char* Thread_NoResources_Exc::what() const _NOEXCEPT
#endif
{
	return "No resources to create another thread";
}










}//namespace advcpp


