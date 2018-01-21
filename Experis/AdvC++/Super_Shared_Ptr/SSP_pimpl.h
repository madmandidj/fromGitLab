#ifndef __SSP_PIMPL_H__
#define __SSP_PIMPL_H__

#include <stddef.h>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////////////
//SharedPtr class
template<class T, bool>
class SSP_pimpl
{
public:

private:
	T*		m_ptr;
	size_t*	m_numOfOwners;

};
































}//namespace advcpp
#endif//#ifndef __SSP_PIMPL_H__
