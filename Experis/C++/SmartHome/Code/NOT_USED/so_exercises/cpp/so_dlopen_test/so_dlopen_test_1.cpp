/*#include <stdio.h>*/
#include <iostream>
#include <dlfcn.h>
using namespace std;

typedef int (*add_func)(unsigned int a, unsigned int b);

int main()
{
	void* myso = dlopen("/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/cpp/so_test_1/libshared.so", RTLD_NOW);
	add_func func = (add_func)dlsym(myso, "add");
//	printf("%d\n", func(1,1));
	unsigned int result = func(1,1);
	cout << result << endl;
	dlclose(myso);
	
	
	
	myso = dlopen("/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/cpp/so_test_2/libshared.so", RTLD_NOW);
	func = (add_func)dlsym(myso, "add");
//	printf("%d\n", func(1,1));
	result = func(1,1);
	cout << result << endl;
	dlclose(myso);
	return 0;
}

