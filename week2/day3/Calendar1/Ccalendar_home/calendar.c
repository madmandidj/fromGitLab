#include <stdlib.h>
#include "calendar.h"

struct ad* CreateAD(unsigned int cap){
	struct ad* myAD;
	myAD = malloc(sizeof(struct ad));
	if (myAD==NULL){
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

void DestroyAD(struct ad* myAD, struct app* myApp){
	if (myAD!=NULL){
		free(myAD);
	}
	if (myApp!=NULL){
		free(myApp);
	}
	return;
}

struct app*	CreateApp(float start_time, float end_time, unsigned int room){
	struct app* myApp;
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

int CheckvalidApp(struct ad* myAD, struct app* myApp){
	//IMPLEMENT: if room is occupied, if time values are valid
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
	*/
	if(myAD==NULL){
		return 1;
	}
	if(myApp==NULL){
		return 2;
	}
	int valid_app_flag = CheckvalidApp(myAD,myApp);
	if (valid_app_flag==0){
		return 3;
	}
	int index;
	int index_to_insert;
	appPTR* temp_app_arr;
	temp_app_arr = myAD->app_arr;
	/*
	Insert appointment without changing capacity
	*/
	if (myAD->noa < myAD->cap){
		//Currently 0 appointments 
		if(myAD->noa == 0){
			myAD->app_arr[0] = myApp;
			++(myAD->noa);
			return 0;
		}
		//Currently 1 appointments
		else if(myAD->noa == 1){
			// valid_app_flag = CheckvalidApp(myAD,myApp);
			// if (valid_app_flag==0){
			// 	return 3;
			// }
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
			valid_app_flag = CheckvalidApp(myAD,myApp);
			if (valid_app_flag==0){
				return 3;
			}
			for(index_to_insert=0; index_to_insert < myAD->noa-1; ++index_to_insert){
				if((myApp->start_time >= myAD->app_arr[index_to_insert]->end_time) &&
					(myApp->end_time < myAD->app_arr[index_to_insert+1]->start_time)){
					for(index=0; index < myAD->noa-index_to_insert+1 ; ++index){
						myAD->app_arr[(myAD->noa)-index+1] = myAD->app_arr[(myAD->noa)-index];
					}
					myAD->app_arr[index_to_insert] = myApp;
					++(myAD->noa);
					return 0;
				}
			}
		}
	}
	else{
		/*
		Change capacity and then insert appointment
		*/
		
	}
}















