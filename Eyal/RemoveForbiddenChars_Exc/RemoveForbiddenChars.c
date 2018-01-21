#include <stdio.h>
#include <limits.h>

char* RemoveForbiddenChars(char* const _source, const char* const _forbidden)
{
    size_t index = 0;
    size_t curPos = 0;
    size_t curLength = 0;
    char* curPtr;
    char tempChar;
    char charSet[CHAR_MAX] = {0};

    if (!_source || !_forbidden)
    {
        return NULL;
    }

    while(_forbidden[index])
    {
        charSet[_forbidden[index]] = 1;
        ++index;
    }
    index = 0;
    
    while (0 != _source[index])
    {
        if (1 == charSet[_source[index]])
        {
            curPos = index + 1;
            while (0 != _source[curPos])
            {
                if(1 == charSet[_source[curPos]])
                {
                    ++curPos;
                    continue;
                }
                tempChar = _source[index];
                _source[index] = _source[curPos];
                _source[curPos] = tempChar;
                break;
            }
            if (0 == _source[curPos])
            {
                break;
            }
        }
        ++curLength;
        ++index;
    }
    _source[curLength] = 0;
    return _source;
}

int main()
{
    char str1[] = "abracadabra";
    char str2[] = "ba";
    RemoveForbiddenChars(str1, str2);
    printf("%s\n", str1);
    return 0;
}