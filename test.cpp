#include<iostream>

int main()
{
//    #if (defined (LINUX) || defined (__linux__))
//        std::cout << "I'm on Linux!" << std::endl;
	#if (defined (__linux__))
        std::cout << "I'm on Linux!" << std::endl;
    #elif (defined (__APPLE__))
        std::cout << "I'm on APPLE!" << std::endl;
    #endif
}
