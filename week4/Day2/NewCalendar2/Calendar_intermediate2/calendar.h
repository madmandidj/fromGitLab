#ifndef CALENDAR_H
#define CALENDAR_H

struct app{
	float start_time;
	float end_time;
	unsigned int room;
};

typedef struct app* appPTR;

struct ad{
	appPTR* app_arr;
	unsigned int noa;
	unsigned int cap;
};



//FUNCTION PROTOTYPES
//-------------------
//Create AD (appointment diary)
struct ad* 	CreateAD(unsigned int cap);
//Create appointment
struct app*	CreateApp(float start_time, float end_time, unsigned int room);	
//Insert appointment
int 		InsertApp(struct ad* myAD, struct app* myApp);
//Remove appointment
int			RemoveApp(struct ad* myAD, float start_time);
//Find appointment in AD
struct app* FindApp(struct ad* myAD, float start_time);
//Destroy AD
struct ad*	DestroyAD(struct ad* myAD);
#endif
