#include "SyncExceptions.h"
namespace advcpp
{

const char* NoResources_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT //_NOEXCEPT
{
	return "No resources available";
}

const char* NoMemory_Exc::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT//_NOEXCEPT
{
	return "No memory available";
}

}//namespace advcpp


