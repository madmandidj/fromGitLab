/*#include <stdio.h>*/
#include <iostream>
#include <dlfcn.h>
using namespace std;

class Event_t;

typedef int (*add_func)(unsigned int a, unsigned int b);

int main()
{
	void* myso = dlopen("/home/eyalalon2/Desktop/compMove/Experis/work/C++/SmartHome/so_exercises/SmartHome_test/SO/PHIL_SD_1000.so", RTLD_NOW);
	
	add_func func = (add_func)dlsym(myso, "add");
	
	unsigned int result = func(1,1);
	
	cout << result << endl;
	
	dlclose(myso);
	
	
	
	myso = dlopen("/home/eyalalon2/Desktop/compMove/Experis/work/C++/SmartHome/so_exercises/SmartHome_test/SO/SONY_SD_127.so", RTLD_NOW);
	
	func = (add_func)dlsym(myso, "add");
	
	result = func(1,1);
	
	cout << result << endl;
	
//	Event_t()
	
	
	
	
	
	dlclose(myso);
	
	return 0;
}

