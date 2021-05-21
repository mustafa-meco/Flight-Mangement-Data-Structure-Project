#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Flights.h"
#include "Area.h"
#include "Eventlist.h"
#include "AreasList.h"
#include "Booking.h"
#include "PriorityQueue.h"
#include "EVENTS/EVENTS.h"
#include "Cancellation.h"
#include "Promotion.h"

using namespace std;

enum Sp {Normal , VIP};

enum EventT {B, X, P, AP, ASSIGNtoLane, FlyFromTo, FinishedFlight};

struct TnL {
	Area* TA;
	Area* LA;
};

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
	AreasList<Area>* AreasL;
	int AutoP;
	int** Dists;
	int N_Events;
	//FlightsList<Flights>* FlightsL;
	//string* rawEvents;
	PriorityQueue<EVENTS>* EventList;
	PriorityQueue<EVENTS>* preparedEvents;
	PriorityQueue<Flights>* AreasWaitinglist;
	int normal_flights;
	int VIP_flights;
public:
	Scheduler();
	bool readFile(string );
	Eventlist prepareSimulation();
	void Simulate(Eventlist Evs);
	void outToFile();
	static int getAutoP();
	int getnormal();
	static int getvip();
	void setnormal(int normal);
	static void setvip(int vip);
};

