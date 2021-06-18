#include "Booking.h"

Booking::Booking(int t, int i, Area* ta, Area* la, Sp ty, int pa) : EVENTS(t,i) {  //Constuctor
	TA = ta;        
	LA = la;
	typ = ty;
	Pass = pa;
	tp = B;
}

int Booking::calcOn(int t) const {  //Function to calculate the time for the passengers 
									//+getting  or off from the airplane
	return t * Pass;
}

int Booking::calcOf(int t) const { //Function to calculate the time for the passengers 
									//+getting  or off from the airplane
	return t * Pass;
}

int Booking::getNpass() const {     //Getter for the number of passengers 
	return Pass;
}

//TnL Booking::getAreas() const {
//	return As;
//}

Sp Booking::getType() const {           // Getter to return the flight type after booking
	return typ;
}


EventT Booking::getEventT() const {
	return B;
}
Area* Booking::getTA() const { return TA; }    //Getter for the deperature area 
Area* Booking::getLA() const { return LA; }    //Getter for the landing area
