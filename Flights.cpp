#include "Flights.h"

Flights::Flights(int ID, TnL ars, Sp ty, int ts, int pa) { //Constructor //comment
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

Sp Flights::getType() const{        // Getter for the Flight type
	return Flight_Type;
}


void Flights::promote() {           //Comment 
	//int a = Scheduler::getvip();
	//Scheduler::setvip(a++);
}

Area* Flights::getTA() const { return Areas.TA; }    //Getter for the Depareture Area //comment 
Area* Flights::getTA() const { return Areas.LA; }    // Getter for the landing Area. 

int Flights::getID() const { return ID; }            // comment

Flights::~Flights() {

}

int Flights::getPassNUM()                           //Getter for the number of passengers
{
	return Passengers;
}




bool Flights::refresh(int ct) { //this function is to refresh the flight by taking the current time
								//and calculate the waiting time 
								//and if it is normal and its waiting time above autoprom time 
								// it will return false to be auto promoted
	WT = ct - TS;
	switch (Flight_Type)
	{
	case Normal:
		return WT < autoProm;
	default:
		break;
	}
	return true;
}

void Flights::setAutoProm(int ap) {         //Comment 
	autoProm = ap;
}