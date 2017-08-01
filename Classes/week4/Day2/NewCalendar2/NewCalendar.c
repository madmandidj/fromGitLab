#include <stdio.h>
#include <stdlib.h>
#include "NewCalendar.h"

AD* CreateAD(int _cap)
{
	AD* myAD;
	myAD = malloc(sizeof( AD));
	if (NULL == myAD || 0 == _cap)
	{
		return NULL;
	}
	else
	{
		myAD->m_appArr = malloc(_cap*sizeof(AppPtr));
		if (NULL == myAD->m_appArr)
		{
			free(myAD);
			return NULL;
		}
		else
		{
			myAD->m_cap=_cap;
			myAD->m_nOA=0;
			return myAD;
		}
	}
}

AD* DestroyAD( AD* _myAD)
{
	int i;
	for(i = 0; i < _myAD->m_nOA; ++i){
		free(_myAD->m_appArr[i]);
	}
	free(_myAD->m_appArr);
	free(_myAD);
	return NULL;
}

App*	CreateApp(float _startTime, float _endTime, int _room)
{
	App* myApp;
	if (_startTime < 0 || _endTime > 24){
		return NULL;
	}
	if (_startTime >= _endTime || _endTime <= _startTime){
		return NULL;
	}
	myApp = malloc(sizeof(App));
	if (NULL == myApp)
	{
		return NULL;
	}
	else
	{
		myApp->m_startTime = _startTime;
		myApp->m_endTime = _endTime;
		myApp->m_room = _room;
	}
	return myApp;
}

static int CheckOverlap( AD* _myAD,  App* _myApp)
{
	int index;
	for(index=0;index<_myAD->m_nOA;++index)
	{	
		/* Check if _myApp start_time is valid */	
		if((_myApp->m_startTime >= _myAD->m_appArr[index]->m_startTime) &&
			(_myApp->m_startTime < _myAD->m_appArr[index]->m_endTime)){
				return 0;
		}
		/* Check if _myApp end_time is valid	*/		
		if((_myApp->m_endTime > _myAD->m_appArr[index]->m_startTime) &&
			(_myApp->m_endTime <= _myAD->m_appArr[index]->m_endTime)){
				return 0;
		}
		/* Check if _myApp is nested in another appointment */
		if((_myApp->m_startTime >= _myAD->m_appArr[index]->m_startTime) &&
			(_myApp->m_endTime <= _myAD->m_appArr[index]->m_endTime)){
				return 0;
		}
		/* Check if current appointment contains _myApp */
		if((_myApp->m_startTime <= _myAD->m_appArr[index]->m_startTime) &&
			(_myApp->m_endTime >= _myAD->m_appArr[index]->m_endTime)){
				return 0;
		}
	}
	return 1;
}

int InsertApp( AD* _myAD,  App* _myApp)
{ 
	/*
	return values: 
	0 = success 
	1 = no diary 
	2 = no appointment 
	3 = Time not available for appointment
	4 = Invalid appointment format
	5 = No memory
	*/
	int valid_app_flag;
	int index;
	int index_to_insert;
	AppPtr* temp_app_arr;
	if(NULL == _myAD)
	{
		return 1;
	}
	if(NULL == _myApp)
	{
		return 2;
	}
	valid_app_flag = CheckOverlap(_myAD,_myApp);
	if (0 == valid_app_flag)
	{
		return 3;
	}
	temp_app_arr = _myAD->m_appArr;
	/* Check if need to change capacity */
	if (_myAD->m_nOA == _myAD->m_cap)
	{
		temp_app_arr = realloc(_myAD->m_appArr, _myAD->m_cap*2*sizeof(AppPtr));
		if (NULL == temp_app_arr)
		{
			return 5;
		}
		_myAD->m_appArr = temp_app_arr;
		_myAD->m_cap = 2 * _myAD->m_cap;
	}
	/* Currently 0 appointments */
	if(0 == _myAD->m_nOA)
	{
		_myAD->m_appArr[0] = _myApp;
		++(_myAD->m_nOA);
		return 0;
	}
	/* Currently 1 appointments */
	else if(1 == _myAD->m_nOA)
	{
		if (_myApp->m_startTime >= _myAD->m_appArr[0]->m_endTime)
		{
			_myAD->m_appArr[1] = _myApp;
			++(_myAD->m_nOA);
			return 0;
		}
		else
		{
			/* shift 1 appointment right and enter _myApp */
			_myAD->m_appArr[1] = _myAD->m_appArr[0];
			_myAD->m_appArr[0] = _myApp;
			++(_myAD->m_nOA);
			return 0;
		}
	}
	/* Currently 2 or more appointments */
	else
	{
		valid_app_flag = CheckOverlap(_myAD,_myApp);
		if (0 == valid_app_flag)
		{
			return 3;
		}
		/* If appointment needs to be added at end of diary */
		if (_myApp->m_startTime >= _myAD->m_appArr[_myAD->m_nOA-1]->m_endTime)
		{
			index_to_insert= _myAD->m_nOA;
		}
		/* If appointment needs to be added at beginning of diary */
		else if (_myApp->m_endTime <= _myAD->m_appArr[0]->m_startTime)
		{
			index_to_insert= 0;
			for(index = _myAD->m_nOA; index > index_to_insert ; index--)
			{
				_myAD->m_appArr[index] = _myAD->m_appArr[index-1];
			}
		}
		/* If appointment needs to be added in middle of diary */
		else
		{
			for(index = 0; index < _myAD->m_nOA-1; ++index){	
				if((_myApp->m_startTime >= _myAD->m_appArr[index]->m_endTime) &&
					(_myApp->m_endTime <= _myAD->m_appArr[index+1]->m_startTime))
				{
					index_to_insert = index+1;
					break;
				}
			}
			for(index = _myAD->m_nOA; index > index_to_insert ; --index)
			{
				_myAD->m_appArr[index] = _myAD->m_appArr[index-1];
			}
		}
		_myAD->m_appArr[index_to_insert] = _myApp;
		++(_myAD->m_nOA);
		return 0;
	}
}

int	RemoveApp( AD* _myAD, float _startTime)
{
	/* returns 1 if App removed or 0 if no appointment at that start_time */
	int index;
	int shift_index;
	if(NULL == _myAD)
	{
		return 0;
	}
	for(index = 0; index < _myAD->m_nOA; ++index)
	{
		if(_myAD->m_appArr[index]->m_startTime == _startTime)
		{
			free(_myAD->m_appArr[index]);
			for (shift_index = index; shift_index < _myAD->m_nOA-1; ++shift_index)
			{
				_myAD->m_appArr[shift_index] = _myAD->m_appArr[shift_index+1];
			}
			--(_myAD->m_nOA);
			return 1;
		}	
	}
	return 0;
}

App* FindApp( AD* _myAD, float _startTime)
{
	int index;
	if(NULL == _myAD)
	{
		return NULL;
	}
	for(index = 0; index < _myAD->m_nOA; ++index)
	{
		if(_myAD->m_appArr[index]->m_startTime == _startTime)
		{
			return _myAD->m_appArr[index];
		}
	}
	return NULL;
}

void PrintAppsToFile(AD* _myAD) /* need to add filename as parameter */
{
	/* can add num of appointments in file OR ftell at end of file and know the index to exit */
	int i;
	FILE* fp;
	if(NULL == _myAD)
	{
		return;
	}
	fp = fopen("AppDiary", "w+"); /* This should be w instead of w */
	if(NULL == fp)
	{
		return;
	}
	for (i = 0; i < _myAD->m_nOA; ++i)
	{
		/* Check if the fprintf has worked or not */
		fprintf(fp,"%f %f %d\n", _myAD->m_appArr[i]->m_startTime, _myAD->m_appArr[i]->m_endTime, _myAD->m_appArr[i]->m_room);
	}
	return;
}

AD* ReadAppsFromFile() /*Name of the file should be sent as a parameter, and pointer to AD instance */
{
	char line[128];
	float startTime;
	float endTime;
	int room;
	int initCap = 2;
	AD* myAD;
	App* myApp;
	FILE* fp;
	fp = fopen("AppDiary", "r"); /* Check if fopen succeeded */
	if(NULL == fp)
	{
		return NULL; /* Do not return NULL because this destroys the existing AD* */
	}
	myAD = CreateAD(initCap); /* This should be in the main function, and added as a parameter */
	fseek(fp, 0, 0);
	while (1)
    {
        if (feof(fp))
        {
            break;
        }
        else
        {
        	/* Do checks for all of these functions */
        	fgets(line, 128, fp); /* Not needed, can use only sscanf */
        	sscanf(line, "%f %f %d", &startTime, &endTime, &room); /*Dont need blank between parameters here */
        	myApp = CreateApp(startTime, endTime, room);
        	InsertApp(myAD, myApp);
        }
    }
	return myAD;
}








