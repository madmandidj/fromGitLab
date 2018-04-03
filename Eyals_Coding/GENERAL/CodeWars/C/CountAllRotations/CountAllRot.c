/*
Input:

a string strng
an array of strings arr
Output of function contain_all_rots(strng, arr) (or containAllRots or contain-all-rots):

a boolean true if all rotations of strng are included in arr (C returns 1)
false otherwise (C returns 0)
#Examples:

contain_all_rots(
"bsjq", ["bsjq", "qbsj", "sjqb", "twZNsslC", "jqbs"]) -> true

contain_all_rots(
"Ajylvpy", ["Ajylvpy", "ylvpyAj", "jylvpyA", "lvpyAjy", "pyAjylv", "vpyAjyl", "ipywee"]) -> false)
Note:
Though not correct in a mathematical sense

we will consider that there are no rotations of strng == ""
and for any array arr: contain_all_rots("", arr) --> true
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct RotCount RotCount;
struct RotCount
{
    char* m_str;
    int m_isPresent;
};

typedef struct RotArray RotArray;
struct RotArray
{
    RotCount* m_rotCount;
    size_t m_numOfRots;
};

int AreParamsValid(char* strng, char* arr[], int sz)
{
    if (!strng || !arr || 0 == sz)
    {
        return 0;
    }
    return 1;
}

RotArray* CreateRotArray(char* strng)
{
    char* c;
    size_t strngLength = 0;
    RotArray* rotArray;
    size_t index;
    size_t rotIndex;
    c = strng;
    while (*c)
    {
        ++strngLength;
        ++c;
    }
    if (NULL == (rotArray = malloc(sizeof(RotArray))))
    {
        return NULL;
    }
    rotArray->m_numOfRots = strngLength;
    if (NULL == (rotArray->m_rotCount = malloc(sizeof(RotCount) * rotArray->m_numOfRots)))
    {
        free(rotArray);
        return NULL;
    }
    for (index = 0; index < rotArray->m_numOfRots; ++index)
    {
        if (NULL == (rotArray->m_rotCount[index].m_str = malloc(sizeof(char) * rotArray->m_numOfRots + 1)))
        {
            /*TODO: free allocations that have succeeded up to this point */
            free(rotArray->m_rotCount);
            free(rotArray);
            return NULL;
        }

        
    }
}

// sz is size of arr
int containAllRots(char* strng, char* arr[], int sz) 
{
    /*
    psuedo code:
    AreParamsValid
    CreateCountArray
    FillCountArray
    CheckIfAllRotationsCounted
    */
    char* c;
    size_t strngLength = 0;
    RotArray* rotArray;
    int result;

    if (!AreParamsValid(strng, arr, sz))
    {
        return 1;
    }

    rotArray = CreateRotArray(strng);
    c = strng;
    while (c)
    {
        ++strngLength;
        ++c;
    }

}


int main()
{
    return 0;
}


