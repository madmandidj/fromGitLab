#include "TException_t.h"
#include <iostream>
#include <string>




int main()
{
	bool dummyFlag = true;

	std::string object("MackMack");
	std::string description;
	std::string sourceFileName(__FILE__);
	
	description.assign("This is a test");
	
	TException_t<std::string> tExcp1(&object, description, sourceFileName, __LINE__);
	
	std::cout << tExcp1;
	
	
	return 0;
}
