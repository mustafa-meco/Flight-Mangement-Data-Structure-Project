#pragma once
//#include <iostream>
//#include"Scheduler.h"
//using namespace std;
//#include "Def.h"
#include "Area.h"

class Flights
{
private:
	//int Booking_Timestamp;           
	int Arrival_Area;			     //This is the area that the flight finishes at.
	int ID;                          // id of the flight
//	int service_time, wait_time, boarding_time, finishing_time;
	int TS;						     //time stamp when the flight is booked 
//	int landing_area;            
	int WT;                          //time from booking until assigning to lane
	//double Departure_Area;         //There are n areas for each area there is a specific number of lanes.A flight is reserved from an area to another, this is the area that the flight starts from.
	Sp Flight_Type;					 //There are 2 flight types : VIP and Normal.
	int Passengers;					 //the number of passengers for the flight.
	//int Arrival_Area;				 //This is the area that the flight finishes at.
	//int on_boarding_time;           
	//TnL Areas;
	//static int autoProm;            // Time of autoPromotion
	Area* TA,*LA;                   //Departure and landing area
public:
	Flights();
	Flights(int,int ID,Area* TA, Area* LA, Sp, int );
	void ToServe(int time) ;
//	void Finish(int landing_time);
	int getBT() const;
	int getWT() const;
	int getST() const;
	int getFT() const;
	//void AutoP(int time); // calls promote()
	//check();
	Sp getType() const;
	//bool cancel();
	void promote();
	Area* getTA() const;
	Area* getLA() const;
	int getID() const;
	bool refresh(int ct, int autop);
	//static void setAutoProm(int);
	~Flights();
	int getPassNUM();
	void toServe(int );
	
};
