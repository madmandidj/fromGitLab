#include "./Buffer/Buffer.h"
#include "./String/String.h"
#include<iostream>




int main()
{
	advcpp::String str1;
	advcpp::String str2("edsrfg2435tswed");
	advcpp::String str3(str2);
	
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;	
	
	std::cout << (str2 == str3) << std::endl;
	std::cout << (str2 == str1) << std::endl;
	
	advcpp::String str4;
	str4 = str2;
	std::cout << (str3 == str4) << std::endl;
	std::cout << (str3 != str4) << std::endl;
	
	advcpp::String str5 = str3 + str4;
	std::cout << str5 << std::endl;
	
	
	advcpp::String eyal = "eyal";
	advcpp::String alon = "alon";
	eyal += alon;
	std::cout << eyal << std::endl;
	
	
	return 0;
}













