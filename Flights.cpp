#include "Flights.h"

Flights::Flights(int t,int ID, Area* ta,Area* la, Sp ty, int pa) { //Constructor
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


void Flights::promote() {           //Function to promote from normal to VIP after certain time
	Flight_Type = VIP;
	//Scheduler::setvip(a++);
}

Area* Flights::getTA() const { return TA; }  //Getter for the Depature area
Area* Flights::getLA() const { return LA; }  //Getter for the landing area


int Flights::getID() const { return ID; }    //Getter for the flight id

int Flights::getBT() const{         //Getter for Boarding time
	return TS;
}
void Flights::ToServe(int time) {    //Function to calculate the time which the plane take from getting out the waiting list 
									 //to be assigned to lane    
	WT = time- TS;
}
//void Flights::Finish(int landing_time) {
//	finishing_time = service_time + wait_time + landing_time;
//}

int Flights::getWT() const {	//Function to return waiting time 
	return WT;
}
//int Flights::getST() const {
//	return service_time;
//}

//int Flights::getFT() const {
//	return getBT() + getWT() + getST();
//}

int Flights::getPassNUM()                           //Getter for the number of passengers
{
	return Passengers;
}

Flights::~Flights() {

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

//void Flights::setAutoProm(int ap) {         //Comment 
//	autoProm = ap;
//}

//void Flights::toServe(int cT) {    
//	WT = cT - TS;
//}