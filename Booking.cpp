#include "Booking.h"

Booking::Booking(int t, int i, Area* ta, Area* la, Sp ty, int pa) : EVENTS(t,i) {
	As.TA = ta;
	As.LA = la;
	typ = ty;
	Pass = pa;
	tp = B;
}

int Booking::calcOn(int t) const {
	return t * Pass;
}

int Booking::calcOf(int t) const {
	return t * Pass;
}

int Booking::getNpass() const {
	return Pass;
}

TnL Booking::getAreas() const {
	return As;
}

Sp Booking::getType() const {
	return typ;
}

