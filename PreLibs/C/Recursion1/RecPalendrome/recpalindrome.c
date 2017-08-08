#include <stdio.c>

int RecIsPal(char* _charArr, int length)
{
	char* leftPoint;
	char* rightPoint;
	if(&_charArr == &_charArr+length-1)
	{
		return 1;
	}
	if(&_charArr == &_charArr+length-1)
	{
		
	}
	if(*_charArr == *_charArr+length-1)
	{
		return RecIsPal(_charArr+1, length-2);
	}

}

int main()
{

	return 0;
}
