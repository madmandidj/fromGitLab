#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

struct ad* CreateAD(unsigned int cap){
	struct ad* myAD;
	myAD = malloc(sizeof(struct ad));
	if (myAD==NULL || cap == 0){
		return NULL;
	}
	else{
		myAD->app_arr = malloc(cap*sizeof(appPTR));
		if (myAD->app_arr==NULL){
			free(myAD);
			return NULL;
		}
		else{
			myAD->cap=cap;
			myAD->noa=0;
			return myAD;
		}
	}
}

struct ad* DestroyAD(struct ad* myAD){
	for(unsigned int i=0; i<myAD->noa; ++i){
		free(myAD->app_arr[i]);
	}
	free(myAD->app_arr);
	free(myAD);
	return NULL;
}

struct app*	CreateApp(float start_time, float end_time, unsigned int room){
	struct app* myApp;
	if (start_time<0 || end_time>24){
		return NULL;
	}
	if (start_time >= end_time || end_time <= start_time){
		return NULL;
	}
	myApp = malloc(sizeof(struct app));
	if (myApp==NULL){
		return NULL;
	}
	else{
		myApp->start_time = start_time;
		myApp->end_time = end_time;
		myApp->room = room;
	}
	return myApp;
}

int CheckOverlap(struct ad* myAD, struct app* myApp){
	int index;
	for(index=0;index<myAD->noa;++index){	
		//Check if myApp start_time is valid	
		if((myApp->start_time >= myAD->app_arr[index]->start_time) &&
			(myApp->start_time < myAD->app_arr[index]->end_time)){
				return 0;
		}
		//Check if myApp end_time is valid			
		if((myApp->end_time > myAD->app_arr[index]->start_time) &&
			(myApp->end_time <= myAD->app_arr[index]->end_time)){
				return 0;
		}
		//Check if myApp is nested in another appointment
		if((myApp->start_time >= myAD->app_arr[index]->start_time) &&
			(myApp->end_time <= myAD->app_arr[index]->end_time)){
				return 0;
		}
		//Check if current appointment contains myApp
		if((myApp->start_time <= myAD->app_arr[index]->start_time) &&
			(myApp->end_time >= myAD->app_arr[index]->end_time)){
				return 0;
		}
	}
	return 1;
}

int InsertApp(struct ad* myAD, struct app* myApp){ 
	/*
	return values: 
	0 = success 
	1 = no diary 
	2 = no appointment 
	3 = Time not available for appointment
	4 = Invalid appointment format
	5 = No memory
	*/
	if(myAD==NULL){
		return 1;
	}
	if(myApp==NULL){
		return 2;
	}
	int valid_app_flag = CheckOverlap(myAD,myApp);
	if (valid_app_flag==0){
		return 3;
	}
	int index;
	int index_to_insert;
	appPTR* temp_app_arr;
	temp_app_arr = myAD->app_arr;
	//Check if need to change capacity
	if (myAD->noa == myAD->cap){
		temp_app_arr = realloc( myAD->app_arr, myAD->cap*2*sizeof(appPTR));
		if (temp_app_arr==NULL){
			return 5;
		}
		myAD->app_arr = temp_app_arr;
		myAD->cap = 2 * myAD->cap;
	}
	//Currently 0 appointments 
	if(myAD->noa == 0){
		myAD->app_arr[0] = myApp;
		++(myAD->noa);
		return 0;
	}
	//Currently 1 appointments
	else if(myAD->noa == 1){
		if (myApp->start_time >= myAD->app_arr[0]->end_time){
			myAD->app_arr[1] = myApp;
			++(myAD->noa);
			return 0;
		}
		else{
			//shift 1 appointment right and enter myApp
			myAD->app_arr[1] = myAD->app_arr[0];
			myAD->app_arr[0] = myApp;
			++(myAD->noa);
			return 0;
		}
	}
	//Currently 2 or more appointments
	else{
		valid_app_flag = CheckOverlap(myAD,myApp);
		if (valid_app_flag==0){
			return 3;
		}
		// If appointment needs to be added at end of diary
		if (myApp->start_time >= myAD->app_arr[myAD->noa-1]->end_time){
			index_to_insert= myAD->noa;
		}
		// If appointment needs to be added at beginning of diary
		else if (myApp->end_time <= myAD->app_arr[0]->start_time){
			index_to_insert= 0;
			for(index = myAD->noa; index > index_to_insert ; index--){
				myAD->app_arr[index] = myAD->app_arr[index-1];
			}
		}
		else{
			for(index=0; index < myAD->noa-1; ++index){	
				if((myApp->start_time >= myAD->app_arr[index]->end_time) &&
					(myApp->end_time <= myAD->app_arr[index+1]->start_time)){
						index_to_insert = index+1;
						break;
				}
			}
			for(index = myAD->noa; index > index_to_insert ; --index){
				myAD->app_arr[index] = myAD->app_arr[index-1];
			}
		}
		myAD->app_arr[index_to_insert] = myApp;
		++(myAD->noa);
		return 0;
	}
}

int	RemoveApp(struct ad* myAD, float start_time){
	//returns 1 if app removed or 0 if no appointment at that start_time
	if(myAD==NULL){
		return 0;
	}
	unsigned int index;
	unsigned int shift_index;
	for(index=0; index < myAD->noa; ++index){
		if(myAD->app_arr[index]->start_time == start_time){
			free(myAD->app_arr[index]);
			for (shift_index = index; shift_index < myAD->noa-1; ++shift_index){
				myAD->app_arr[shift_index] = myAD->app_arr[shift_index+1];
			}
			--(myAD->noa);
			return 1;
		}	
	}
	return 0;
}

struct app* FindApp(struct ad* myAD, float start_time){
	unsigned int index;
	if(myAD==NULL){
		return NULL;
	}
	for(index=0; index < myAD->noa; ++index){
		if(myAD->app_arr[index]->start_time == start_time){
			return myAD->app_arr[index];
		}
	}
	return NULL;
}
