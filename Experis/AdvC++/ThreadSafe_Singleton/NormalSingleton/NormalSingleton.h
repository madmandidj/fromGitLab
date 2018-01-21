#ifndef __NORMAL_SINGLETON_H__
#define __NORMAL_SINGLETON_H__

namespace advcpp
{

class NormalSingleton { 
private: 
	static NormalSingleton* sngPtr; 
public: 
	static void Destroy();
	static NormalSingleton* Create();
protected: 
	virtual ~NormalSingleton(){} 
private: 
	NormalSingleton(){}
	NormalSingleton(const NormalSingleton&);
	void operator=(NormalSingleton&);
};
 
}//namespace advcpp
#endif//#ifndef __NORMAL_SINGLETON_H__



