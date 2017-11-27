#ifndef __SYNC_EXCEPTIONS_H__
#define __SYNC_EXCEPTIONS_H__

#include<exception>
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
#if (defined (__linux__))
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
#elif (defined (__APPLE__))
    const char* what() const _NOEXCEPT;
#endif
/*	const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT; //_NOEXCEPT;*/
};

class Mutex_NoMemory_Exc : public NoMemory_Exc
{
public:
#if (defined (__linux__))
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
#elif (defined (__APPLE__))
    const char* what() const _NOEXCEPT;
#endif
/*	const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT; //_NOEXCEPT;*/
};
/////////////////////////////////////////////////////////////////
////CondVar sync exceptions declarations
class CondVar_NoResources_Exc : public NoResources_Exc
{
public:
#if (defined (__linux__))
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
#elif (defined (__APPLE__))
    const char* what() const _NOEXCEPT;
#endif
/*	const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT; //_NOEXCEPT;*/
};

class CondVar_NoMemory_Exc : public NoMemory_Exc
{
public:
#if (defined (__linux__))
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
#elif (defined (__APPLE__))
    const char* what() const _NOEXCEPT;
#endif
/*	const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT; //_NOEXCEPT;*/
};
/////////////////////////////////////////////////////////////////
////Thread sync exceptions declarations
class Thread_NoResources_Exc : public NoResources_Exc
{
public:
#if (defined (__linux__))
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
#elif (defined (__APPLE__))
    const char* what() const _NOEXCEPT;
#endif
/*	const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT; //_NOEXCEPT;*/
};




}//namespace advcpp
#endif//#ifndef __SYNC_EXCEPTIONS_H__
