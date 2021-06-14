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
#include "ASSIGNtoLane.h"
#include "FlyFromTo.h"
#include "FinishedFlight.h"
using namespace std;

//enum Sp {Normal , VIP};
//
//enum EventT {B, X, P, AP, ASSIGNtoLane, FlyFromTo, FinishedFlight};
//
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
	PriorityQueue<EVENTS*> prepare();
	void Simulate(PriorityQueue<EVENTS*> Evs);
	void outToFile();
	//static int getAutoP();
	int getnormal();
	//static int getvip();
	void setnormal(int normal);
	//static void setvip(int vip);
	void promote(Flights* f);
	Area* getAreaByID(int, Flights * & reqF);
	bool cancelFlight(int ID);
	void ServeFligh(Flights *);
	void Refersh(); 
	void preServe(v<Flights*>*);
	Lanes checkLane(int t,)
};

