#include "Flights.h"

Flights::Flights(int t,int ID, Area* ta,Area* la, Sp ty, int pa) {
	this->ID = ID;
	//this-> take_off_time= 
	TA = ta;
	LA = la;
	Flight_Type = ty;
	Passengers = pa;
	TS = t;
}

//void Flights::AutoP(int time) {
//	if (time == Scheduler::getAutoP()) {
//		promote();
//	}
//}

Sp Flights::getType() const{        // Getter for the Flight type
	return Flight_Type;
}


void Flights::promote() {
	Flight_Type = VIP;
	//Scheduler::setvip(a++);
}

Area* Flights::getTA() const { return TA; }
Area* Flights::getLA() const { return LA; }


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

int Flights::getPassNUM()                           //Getter for the number of passengers
{
	return Passengers;
}





bool Flights::refresh(int ct, int autoP) { //this function is to refresh the flight by taking the current time
								//and calculate the waiting time 
								//and if it is normal and its waiting time above autoprom time 
								// it will return false to be auto promoted
	WT = ct - TS;
	switch (Flight_Type)
	{
	case Normal:
		return WT < autoP;
	default:
		break;
	}
	return true;
}

//void Flights::setAutoProm(int ap) {         //Comment 
//	autoProm = ap;
//}

void Flights::toServe(int cT) {
	WT = cT - TS;
}