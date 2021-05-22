#include "Flights.h"

Flights::Flights(int ID, TnL ars, Sp ty, int ts, int pa) {
	this->ID = ID;
	//this-> take_off_time= 
	Areas = ars;
	Flight_Type = ty;
	Booking_Timestamp = ts;
	Passengers = pa;
}

//void Flights::AutoP(int time) {
//	if (time == Scheduler::getAutoP()) {
//		promote();
//	}
//}

Sp Flights::getType() {
	return Flight_Type;
}


void Flights::promote() {
	//int a = Scheduler::getvip();
	//Scheduler::setvip(a++);
}

Area* Flights::getTA() const { return Areas.TA; }

int Flights::getID() const { return ID; }

Flights::~Flights() {

}