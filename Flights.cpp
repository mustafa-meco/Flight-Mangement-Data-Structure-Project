#include "Flights.h"
Flights::Flights(int ID, int take_off_time, int landing_time, int passenger_boarding_time, int passenger_off_boarding_time) {

}

void Flights::AutoP(int time) {
	if (time == getAutoP()) {
		promote();
	}
}

Sp Flights::getType() {
	return Flight_Type;
}


void Flights::promote() {

}

Flights::~Flights() {

}