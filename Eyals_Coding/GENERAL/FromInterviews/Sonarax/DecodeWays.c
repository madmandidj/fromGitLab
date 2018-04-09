#include <stddef.h>
#include <stdio.h>
#include <stddef.h>
#include <stddef.h>
static int GetNumOfRemainingChars(char* s)
{
    int strLength = 0;
    if (!s || *s == '\0' )
    {
        return 0;
    }
    while (*s != '\0')
    {
        ++strLength;
        ++s;
    }
    return strLength;
}

static int IsValidString(char* s)
{
/*
Two sequential zeros is also not allowed
*/
    if (!s || *s == '\0' || *s == '0')
    {
        return 0;
    }
    while (*s != '\0')
    {
        if ('0' > *s || '9' < *s)
        {
            return 0;
        }
        ++s;
    }
    return 1;
}

/*
static int numDecodingsRec(char* s)
{
    int result = 0;
    size_t numRemaining; 
    numRemaining = GetNumOfRemainingChars(s);
    switch (numRemaining)
    {
        case 2:
            if (*s == '0')
            {
                return 0;
            }
            if ((*s == '2' && *(s+1) <= '6') || (*s == '1'))
            {
                ++result;
            }
            return result += numDecodingsRec(s + 1);
        case 1:
            if (*s != '0')
            {
                return 1;   
            }
            return 0;
        default:
            if (*s == '0')
            {
                return 0;
            }
            else
            {
                if ((*s == '2' && *(s+1) <= '6') || (*s == '1'))
                {
                    result += numDecodingsRec(s + 1);
                }
                result += numDecodingsRec(s + 2);
            }  
            break;    
    }
    return result;
}
*/


static int numDecodingsRec(char* s)
{
    int result = 0;
    size_t numRemaining; 
    numRemaining = GetNumOfRemainingChars(s); /* Can replace this with additional function parameter*/
    switch (numRemaining)
    {
        case 2:
			if (*s == '0')
			{
				result = 0;
			}
        	else if( (*s == '2' && *(s+1) <= '6')  || (*s == '1') ) 
			{
				++result;
			}
			if (*(s+1) != 0)
			{
				++result;
			}
/*			else if (*/
/*			*/
/*			else*/
/*			{*/
/*				++result;*/
/*			}*/
/*			result += (*s) == '0' ? 0 : 1; */
			return result;
        case 1:
			return (*s) == '0' ? 0 : 1;
        default:
			if(*s != '0')
			{
				result = numDecodingsRec(s+1);
			}
			if( (*s != '0') && ((*s == '2' && *(s+1) <= '6')  || (*s == '1')) )
			{
				result += numDecodingsRec(s+2);
			}
            break;    
    }
    return result;
}


int numDecodings(char* s) 
{
    int isValidString = 1;
    isValidString = IsValidString(s);
    if (!isValidString)
    {
        return 0;
    }
    return numDecodingsRec(s);
}








/*
"11111"
"12345"
"01"
"10"
"101"
"301"
"611"


Answers should be:
8
3
0
1
1
0
2
*/


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





























