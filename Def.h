#pragma once


//#include "Area.h"

enum Sp {    // The type of the flight 

	VIP,
	Normal,
	Cargo,
	Emergence, 
};


enum EventT { //The event type 
	 B          //Booking
	,X          //Cancellation   
	,P          //Promotion 
	,L          //AssignToLane
	,AL			//adding lane
	,F          //Fly from to
	,FF};       //Finished Flight 
                                    


//struct TnL {
//	Area* TA;
//	Area* LA;
//};

//struct Event {
//	int ID;
//	int TS;
//	int TA;
//	int LA;
//	Sp typ;
//	int Pass;
//};

