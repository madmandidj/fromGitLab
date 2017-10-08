#include "memManager_t.h"
#include "../../ExceptionHandler/TException_t.h"


//inline memManager_t::memManager_t(){}



//inline memManager_t::~memManager_t(){}



size_t memManager_t::GetPosition() const
{
 	return m_position;
}



bool memManager_t::SetPosition(size_t _index)
{
	if (_index > m_size)
	{
		std::string desc("Failed Set Position");
		std::string fileName(__FILE__);
//		return false;
		TException_t<memManager_t> tExc(this, desc, fileName, __LINE__);
		throw tExc;
	}
	
	m_position = _index;
	
	return true;
}



bool memManager_t::IsEmpty() const
{
	return 0 == m_size ? true : false;
}



size_t memManager_t::GetSize() const
{
	return m_size;
}











