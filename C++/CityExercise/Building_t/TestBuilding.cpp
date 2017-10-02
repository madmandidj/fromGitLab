#include "Building_t.h"
#include <string>
#include <iostream>

//using namespace std;

int main()
{
	size_t buildingIDint = 666;
	
	std::string buildingIDstring = "Eyals house";
	
	Building_t<size_t> buildingInt(buildingIDint);
	
	Building_t<size_t> buildingInt2(buildingIDint);
	
	Building_t<std::string> buildingString(buildingIDstring);
	
	std::cout << buildingInt.GetID() << std::endl;
	
	buildingString.SetID(buildingIDstring);
	
	std::cout << buildingString.GetID() << std::endl;
	
	buildingInt2 = 555;
	
	std::cout << buildingInt2.GetID() << std::endl;
	
	return 0;
}






















