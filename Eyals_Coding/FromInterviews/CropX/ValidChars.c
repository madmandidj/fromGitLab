#include <stdio.h>
/*
Input is a string. Method returns if string is valid or not.
Valid string contains matching number of [] and (), and in that order. 
*Round cannot be before square
*/

int DoIsValidString(char* _str, int _numOfSquare, int _numOfRound)
{
	int result = 0;
	if (0 > _numOfSquare || 0 > _numOfRound || _numOfRound > _numOfSquare)
	{
		result = 0;
	}
	else
	{
		switch(*_str)
		{
		case '[':
			++_numOfSquare;
			result = DoIsValidString(++_str, _numOfSquare, _numOfRound);
			break;
		case ']':
			--_numOfSquare;
			result = DoIsValidString(++_str, _numOfSquare, _numOfRound);
			break;
		case '(':
			++_numOfRound;
			result = DoIsValidString(++_str, _numOfSquare, _numOfRound);
			break;
		case ')':
			--_numOfRound;
			result = DoIsValidString(++_str, _numOfSquare, _numOfRound);
			break;
		case 0:
			result = (_numOfSquare != 0 || _numOfRound != 0) ? 0 : 1;
			break;
		default:
			result = DoIsValidString(++_str, _numOfSquare, _numOfRound);
			break;	
		}
	}
	return result;
}

int IsValidString(char* _str)
{
	int numOfRound = 0;
	int numOfSquare = 0;
	
	if(!_str)
	{
		return 0;
	}
	return DoIsValidString(_str, numOfSquare, numOfRound);
}



int main()
{
	char str[] = "[fdgf(34[23])]";
	
	printf("%d\n", IsValidString(str));
	
	return 0;
}
