/*#include<stdio.h>*/

#include <iostream>

#include"../so_test_1/shared.h"

using namespace std;

int main(void)
{
    unsigned int a = 1;
    unsigned int b = 2;
    unsigned int result = 0;

    result = add(a,b);

/*    printf("\n The result is [%u]\n",result);*/

	cout << "(cpp) result is " << result << endl;

    return 0;
}
