#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Lanes.h"
#include "Area.h"
#include "Booking.h"
#include "PriorityQueue.h"
//#include "EVENTS/EVENTS.h"
#include "Cancellation.h"
#include "Promotion.h"
//#include "Flights.h"
#include "Def.h"
//#include "EVENTS/EVENTS.h"
using namespace std;



class Scheduler
{
private:
	int N_Areas;
	int tkft; //take off time 
	int lndt; //landing time
	int pnt; //one passenger on time
	int pft; //one passenger off time
	Area** AreasL;
	int AutoP;
	int** Dists;
	int N_Events;
	//FlightsList<Flights>* FlightsL;
	//string* rawEvents;
	PriorityQueue<EVENTS*> EventList;
	PriorityQueue<EVENTS*> preparedEvents;
	PriorityQueue<Flights*>* AreasWaitinglist;
	int normal_flights;
	int VIP_flights;
	LinkedQueue<Flights*> ServingFlights;
	LinkedQueue<Flights*> finishedFlights;
public:
	
	//Scheduler();
	bool readFile(string );
	PriorityQueue<EVENTS*> prepareSimulation();
	void Simulate(PriorityQueue<EVENTS*> Evs);
	void outputfile();
	int getAutoP();
	void setAutoP(int AutoP);
		int getnormal() const;
	int getvip() const;
	void setnormal(int normal);
	//static void setvip(int vip);
	void promote(v<Flights*>* f);
	Area* getAreaByID(int, Flights * & reqF);
	bool cancelFlight(Flights*, Area*);
	int get_AVG_wait();
	int get_AVG_serve();
};

