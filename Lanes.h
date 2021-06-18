#pragma once
#include <string>
#include "PriorityQueue.h"
//#include <iostream>
//#include "Scheduler.h"
#include "Def.h"
using namespace std;
class Lanes
{

	//char Lane_Specialization;
	int Availability_Time;   //As the flight taxi becomes popular, more lanes will be added.A lane is available when it�s availability time is reached.
	int MainAft;	//		  //Each lane needs servicing after a number of flights.
	int MainTime;			//Each lane takes a service time to finish maintenance.
	int VARaft;   ///          
	int VARtime;
	bool aval;               //booleanto check if the lanes available or not
	Sp type;                 //Variable to define the type of the lane if it is VIP or Normal
	int ID;
	PriorityQueue<int> WorkingQueue;
public:

	Lanes(Sp typ, int MA, int MT);              //Constructor intialize the members
	bool check(int t);                                
	Sp getType() const;                                   // getter for the type of the lane
	void Activate();                                     // function to activate the lane 
	bool Serving(int time1, int time2);                  // function to serve the lane (deactivate the lane during the serving time)
	void served();
	void cancel(int t1, int t2);
};


