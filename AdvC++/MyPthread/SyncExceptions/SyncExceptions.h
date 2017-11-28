#ifndef __SYNC_EXCEPTIONS_H__
#define __SYNC_EXCEPTIONS_H__

#include<exception>
#if (defined (__linux__))
    #define ENVIRONMENT_NOEXC _GLIBCXX_USE_NOEXCEPT
#elif (defined (__APPLE__))
    #define test _NOEXCEPT
#endif
namespace advcpp
{
/////////////////////////////////////////////////////////////////
////Sync exceptions Base class
class SyncExceptions : public std::exception{};
/////////////////////////////////////////////////////////////////
////General sync class declarations
class NoResources_Exc : public SyncExceptions{};
class NoMemory_Exc : public SyncExceptions{};
/////////////////////////////////////////////////////////////////
////Mutex sync exceptions declarations
class Mutex_NoResources_Exc : public NoResources_Exc
{
public:
    const char* what() const ENVIRONMENT_NOEXC;
};

class Mutex_NoMemory_Exc : public NoMemory_Exc
{
public:
    const char* what() const ENVIRONMENT_NOEXC;
};
/////////////////////////////////////////////////////////////////
////CondVar sync exceptions declarations
class CondVar_NoResources_Exc : public NoResources_Exc
{
public:
	const char* what() const ENVIRONMENT_NOEXC;
};

class CondVar_NoMemory_Exc : public NoMemory_Exc
{
public:
	const char* what() const ENVIRONMENT_NOEXC;
};
/////////////////////////////////////////////////////////////////
////Thread sync exceptions declarations
class Thread_NoResources_Exc : public NoResources_Exc
{
public:
	const char* what() const ENVIRONMENT_NOEXC;
};




}//namespace advcpp
#endif//#ifndef __SYNC_EXCEPTIONS_H__
