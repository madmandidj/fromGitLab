#include "NormalSingleton.h"
namespace advcpp
{

NormalSingleton* NormalSingleton::sngPtr = 0;

void NormalSingleton::Destroy()	
{ 
	if (sngPtr != 0)
	{
		delete sngPtr; 
		sngPtr = 0; 
	}
}	

NormalSingleton* NormalSingleton::Create() 
{ 
	if (sngPtr == 0)	
	{ 
		sngPtr = new NormalSingleton; 
	} 
	return sngPtr; 
} 



















}//namespace advcpp


