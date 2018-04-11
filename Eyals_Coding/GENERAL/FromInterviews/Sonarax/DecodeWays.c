#include <stddef.h>
#include <stdio.h>
static int GetNumOfRemainingChars(char* _s)
{
    int strLength = 0;
    if (!_s || *_s == '\0' )
    {
        return 0;
    }
    while (*_s != '\0')
    {
        ++strLength;
        ++_s;
    }
    return strLength;
}

static int IsValidString(char* _s)
{
	/*Check NULL string, empty string, leading '0'*/
    if (!_s || *_s == '\0' || *_s == '0')
    {
        return 0;
    }
    while (*_s != '\0')
    {
    	/*Check valid char*/
        if ('0' > *_s || '9' < *_s)
        {
            return 0;
        }
        /*Check no sequential zero pair*/
        if (*_s == '0' && *(_s+1) =='0')
        {
        	return 0;
        }
        ++_s;
    }
    return 1;
}

static int numDecodingsRec(char* _s, size_t _numRemaining)
{
    int result = 0;
    
    switch (_numRemaining)
    {
        case 2:
			if (*_s == '0')
			{
				return 0;
			}
        	else if( (*_s == '2' && *(_s+1) <= '6')  || (*_s == '1') ) 
			{
				++result;
			}
			result += numDecodingsRec(_s+1, _numRemaining-1);
			return result;
        case 1:
			return (*_s) == '0' ? 0 : 1;
        default:
			if (*_s == '0')
			{
				return 0;
			}
			result = numDecodingsRec(_s+1, _numRemaining-1);
			if( (*_s == '2' && *(_s+1) <= '6')  || (*_s == '1') )
			{
				result += numDecodingsRec(_s+2, _numRemaining-2);
			}
            break;    
    }
    return result;
}

int numDecodings(char* _s) 
{
    int isValidString = 1;
    size_t numRemaining; 
    isValidString = IsValidString(_s);
    if (!isValidString)
    {
        return 0;
    }
    numRemaining = GetNumOfRemainingChars(_s);
    return numDecodingsRec(_s, numRemaining);
}

int main()
{
	char* str1 = "11111";
	char* str2 = "12345";
	char* str3 = "01";
	char* str4 = "10";
	char* str5 = "101";
	char* str6 = "301";
	char* str7 = "611";
	
	printf("%d\n", numDecodings(str1));
	printf("%d\n", numDecodings(str2));
	printf("%d\n", numDecodings(str3));
	printf("%d\n", numDecodings(str4));
	printf("%d\n", numDecodings(str5));	
	printf("%d\n", numDecodings(str6));
	printf("%d\n", numDecodings(str7));	
	return 0;
}





























