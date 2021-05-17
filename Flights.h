#include <iostream>
using namespace std;

#pragma once
class Flights
{
private:
	int TS;
	int Booking_Timestamp;
	double Departure_Area; //There are n areas for each area there is a specific number of lanes.A flight is reserved from an area to another, this is the area that the flight starts from.
	char Flight_Type; //There are 2 flight types : VIP and Normal.
	int Passengers;   //the number of passengers for the flight.
	int Arrival_Area; //This is the area that the flight finishes at.
	static int on_boarding_time;
public:
	Flights();
};
