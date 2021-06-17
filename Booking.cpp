#include "Booking.h"

Booking::Booking(int t, int i, Area* ta, Area* la, Sp ty, int pa) : EVENTS(t,i) {  //constructor 
	As.TA = ta;              // comment
	As.LA = la; // comment
	typ = ty; // comment
	Pass = pa; // comment
	tp = B; // comment
}

int Booking::calcOn(int t) const { //comment
	return t * Pass;
}

int Booking::calcOf(int t) const { //comment
	return t * Pass;
}

int Booking::getNpass() const {     //comment
	return Pass;
}

TnL Booking::getAreas() const {         // getter for the area which the plane will take off from.
	return As;
}

Sp Booking::getType() const {           // getter to return the flight type after booking
	return typ;
}

