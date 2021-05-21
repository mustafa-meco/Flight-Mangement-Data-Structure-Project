#include "Flights.h"

Flights::Flights(int ID, int no_areas, int take_off_time, int landing_time, int passenger_boarding_time, int passenger_off_boarding_time) {
	this->ID = ID;
	//this-> take_off_time= 
}

void Flights::AutoP(int time) {
	if (time == Scheduler::getAutoP()) {
		promote();
	}
}

Sp Flights::getType() {
	return Flight_Type;
}


void Flights::promote() {
	int a = Scheduler::getvip();
	Scheduler::setvip(a++);
}

Flights::~Flights() {

}