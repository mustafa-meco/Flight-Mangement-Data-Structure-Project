#include "Booking.h"

Booking::Booking(int t, int i, Area* ta, Area* la, Sp ty, int pa) : EVENTS(t,i) {
	TA = ta;
	LA = la;
	typ = ty;
	Pass = pa;
	tp = B;
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

//TnL Booking::getAreas() const {
//	return As;
//}

Sp Booking::getType() const {           // getter to return the flight type after booking
	return typ;
}

Area* Booking::getTA() const { return TA; }
Area* Booking::getLA() const { return LA; }
