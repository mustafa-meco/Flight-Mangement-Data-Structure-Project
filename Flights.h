#pragma once
//#include <iostream>
//#include"Scheduler.h"
//using namespace std;
#include "Def.h"
#include "Area.h"

class Flights
{
private:
	int Booking_Timestamp;
	int Arrival_Area; //This is the area that the flight finishes at.
	int ID;
	int time_service, time_wait;
	int TS; //time stand 
	int landing_area;
	
	//double Departure_Area; //There are n areas for each area there is a specific number of lanes.A flight is reserved from an area to another, this is the area that the flight starts from.
	Sp Flight_Type; //There are 2 flight types : VIP and Normal.
	int Passengers;   //the number of passengers for the flight.
	//int Arrival_Area; //This is the area that the flight finishes at.
	int on_boarding_time;
	TnL Areas;
public:
	Flights(int ID, TnL, Sp, int , int );
	//void AutoP(int time); // calls promote()
	//check();
	Sp getType() const;
	//bool cancel();
	void promote();
	Area* getTA() const;
	int getID() const;
	~Flights();
};
