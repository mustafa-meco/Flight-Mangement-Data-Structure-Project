#include "Flights.h"

Flights::Flights() {
	
}

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

Sp Flights::getType() const{
	return Flight_Type;
}


void Flights::promote() {
	Flight_Type = VIP;
	//Scheduler::setvip(a++);
}

Area* Flights::getTA() const { return Areas.TA; }
Area* Flights::getLA() const { return Areas.LA; }


int Flights::getID() const { return ID; }

int Flights::getBT() const{
	return boarding_time;
}
void Flights::ToServe(int time) {
	wait_time = time- TS;
}
void Flights::Finish(int landing_time) {
	finishing_time = service_time + wait_time + landing_time;
}

int Flights::getWT() const {

	return wait_time;
}
int Flights::getST() const {
	return service_time;
}
int Flights::getFT() const {
	return getBT() + getWT() + getST();
}


Flights::~Flights() {

}