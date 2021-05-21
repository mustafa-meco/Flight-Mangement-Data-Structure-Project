#include <iostream>
#include"Scheduler.h"
using namespace std;

#pragma once
class Flights
{
private:
	int Booking_Timestamp;
	int Arrival_Area; //This is the area that the flight finishes at.
	int ID;
	int time_service, time_wait;
	int TS, TA; //time stand, taking off area
	int landing_area;
	int Booking_Timestamp;
	double Departure_Area; //There are n areas for each area there is a specific number of lanes.A flight is reserved from an area to another, this is the area that the flight starts from.
	Sp Flight_Type; //There are 2 flight types : VIP and Normal.
	int Passengers;   //the number of passengers for the flight.
	int Arrival_Area; //This is the area that the flight finishes at.
	static int on_boarding_time;
public:
	Flights(int ID, int no_areas, int take_off_time, int landing_time, int passenger_boarding_time, int passenger_off_boarding_time);
	void AutoP(int time); // calls promote()
	//check();
	Sp getType();
	//bool cancel();
	void promote();
	~Flights();
};
