#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CDR_PATH "../CDRs"
#define READY_PATH "./CDRs"
#define WRITE_PATH "../CDRs/WritingTo"
#define CDR_MAX 256
#define FILE_PATH_MAX 128

#define TOTAL_FILES 1
#define TOTAL_SUB_OPS 1
#define COUNT_PER_FILE 1

void GenerateCdr(char* _cdrToFill, char* _type, char* _imsi, char* _msisdn, char* _mcc)
{
    strcpy(_cdrToFill, _imsi);
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, _msisdn);
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "a53fa");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "evil corp");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "2346982");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, _type);
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "1/1/90|00:00:00");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "1");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "1");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "1");
    strcat(_cdrToFill, "|");
    
    strcat(_cdrToFill, "99999");
    strcat(_cdrToFill, "|");
    
    if (NULL == _mcc || _mcc[0] == '\0')
    {
        strcat(_cdrToFill, "2346982");
        strcat(_cdrToFill, "|");
    }
    else
    {
        strcat(_cdrToFill, _mcc);
        strcat(_cdrToFill, "|");
    }
    
    strcat(_cdrToFill, "\n");
}

void ExportAllTypes(FILE* _file, char* _imsi, char* _msisdn, char* _mcc)
{
    char cdr[CDR_MAX];

    GenerateCdr(cdr, "MOC", _imsi, _msisdn, _mcc);
    fputs(cdr, _file);
    GenerateCdr(cdr, "MOC", _imsi, _msisdn, NULL);
    fputs(cdr, _file);
    GenerateCdr(cdr, "MTC", _imsi, _msisdn, NULL);
    fputs(cdr, _file);
    GenerateCdr(cdr, "MTC", _imsi, _msisdn, _mcc);
    fputs(cdr, _file);
    GenerateCdr(cdr, "SMS-MO", _imsi, _msisdn, NULL);
    fputs(cdr, _file);
    GenerateCdr(cdr, "SMS-MO", _imsi, _msisdn, _mcc);
    fputs(cdr, _file);
    GenerateCdr(cdr, "SMS-MT", _imsi, _msisdn, NULL);
    fputs(cdr, _file);
    GenerateCdr(cdr, "SMS-MT", _imsi, _msisdn, _mcc);
    fputs(cdr, _file);
    GenerateCdr(cdr, "GPRS", _imsi, _msisdn, NULL);
    fputs(cdr, _file);
}

void ExportCdrFile(char* _fileName)
{
    int subOps;
    int i;
    char msisdn[16];
    char mcc_mnc[6];
    FILE* file;
    char filePath[FILE_PATH_MAX];
    
    strcpy(filePath, READY_PATH);
    strcat(filePath, _fileName);
    file = fopen(filePath, "w");
    
    for (i = 0 ; i < COUNT_PER_FILE ; ++i)
    {
    	for(subOps = 0 ; subOps < TOTAL_SUB_OPS ; ++subOps)
    	{
       		sprintf(msisdn, "%d", subOps);
        	sprintf(mcc_mnc, "%d", subOps);
        	ExportAllTypes(file, msisdn, msisdn, mcc_mnc);
    	}
    }

    
    fclose(file);
}

int main()
{
    int i;
    char fileName[20];
    
    for (i = 0 ; i < TOTAL_FILES ; ++i)
    {
        sprintf(fileName, "/CDR_%d", i);
        ExportCdrFile(fileName);
    }
    
}
