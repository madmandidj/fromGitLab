#include <stdio.h>
#include <dlfcn.h>

typedef int (*add_func)(unsigned int a, unsigned int b);

int main()
{
	void* myso = dlopen("/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/c/so_test_1/libshared.so", RTLD_NOW);
	add_func func = dlsym(myso, "add");
	printf("%d\n", func(1,1));
	dlclose(myso);
	
	myso = dlopen("/home/eyal/Desktop/EyalsFolder/work/C++/SmartHome/so_exercises/c/so_test_2/libshared.so", RTLD_NOW);
	func = dlsym(myso, "add");
	printf("%d\n", func(1,1));
	dlclose(myso);
	return 0;
}

