#pragma once
#include <string>
//#include <iostream>
//#include "Scheduler.h"
#include "Def.h"
using namespace std;
class Lanes
{

	//char Lane_Specialization;
	int Availability_Time;    //As the flight taxi becomes popular, more lanes will be added.A lane is available when it�s availability time is reached.
	int MainAft;			  //Each lane needs servicing after a number of flights.
	int MainTime;	      	  //Each lane takes a service time to finish maintenance.
	int VARaft;               //Comment          
	int VARtime;              //Comment
	bool aval;                //boolean to check if the lanes available or not
	Sp type;                  //Variable to define the type of the lane if it is VIP or Normal
	int ID;                   //The id of the lane.  

public:

	Lanes(Sp typ, int Avt, int MA, int MT,int);            
	bool check(int t);                                
	Sp getType() const;                                        
	void Activate();                                      
	bool Serving(int time1, int time2);                 
	void served();
	bool Serving (int time1, int time2);               //Comment
	int getID() const;                                 //Comment (NOT EXISTED) 
};


