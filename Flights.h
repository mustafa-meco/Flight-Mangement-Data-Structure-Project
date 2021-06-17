#pragma once
//#include <iostream>
//#include"Scheduler.h"
//using namespace std;
#include "Def.h"
#include "Area.h"

class Flights
{
private:
	int Booking_Timestamp;         // At which timeStamp the booking will happen. 
	int Arrival_Area;              //This is the area that the flight finishes at.
	int ID;                        //comment
	int time_service, time_wait;   //comment  there is another time service "ServiedTime"
	int TS;                        //time stand 
	int landing_area;              // Area where the flight will land on 
	int WT;                        //comment 
	//double Departure_Area;       //There are n areas for each area there is a specific number of lanes.A flight is reserved from an area to another, this is the area that the flight starts from.
	Sp Flight_Type;                //There are 2 flight types : VIP and Normal.
	int Passengers;                //the number of passengers for the flight.
	//int Arrival_Area;            //This is the area that the flight finishes at.
	int on_boarding_time;          //Time which the airplane will on the air.     
	TnL Areas;                     
	static int autoProm;          //Comment  
public:
	Flights(int ID, TnL, Sp, int , int );
	//void AutoP(int time); // calls promote()
	//check();
	Sp getType() const;
	//bool cancel();
	void promote();
	Area* getTA() const;
	Area* getLA() const;
	int getID() const;
	bool refresh(int);
	static void setAutoProm(int);
	~Flights();
	int getPassNUM();
	
};
