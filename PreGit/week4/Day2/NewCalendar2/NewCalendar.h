#ifndef __NEWCALENDAR_H__
#define __NEWCALENDAR_H__

typedef struct App{
	float m_startTime;
	float m_endTime;
	int m_room;
}App;

typedef App* AppPtr;

typedef struct AD
{
	AppPtr* m_appArr;
	int m_nOA;
	int m_cap;
}AD;

AD*		CreateAD(int _cap);
App*	CreateApp(float _startTime, float _endTime, int _room);	
int 	InsertApp(AD* _myAD, App* _myApp);
int		RemoveApp(AD* _myAD, float _startTime);
App* 	FindApp(AD* _myAD, float _startTime);
AD*		DestroyAD(AD* _myAD);
void 	PrintAppsToFile(AD* _myAD);
AD* 	ReadAppsFromFile();

#endif/* #ifndef __NEWCALENDAR_H__ */

