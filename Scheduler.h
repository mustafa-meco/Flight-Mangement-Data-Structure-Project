#include <iostream>
#include <fstream>
#include <string>
#include "Flights.h"
#include "Area.h"
#include "Eventlist.h"
#include "AreasList.h"
using namespace std;

enum Sp {Normal , VIP};

enum EventT {B, X, P};

struct Event {
	int ID;
	int TS;
	int TA;
	int LA;
	Sp typ;
	int Pass;
};

#pragma once
class Scheduler
{
private:
	int tkft; //take off time 
	int lndt; //landing time
	int pnt; //one passenger on time
	int pft; //one passenger off time
	AreasList<Area>* AreasL;
	int AutoP;
	int N_Events;
	//FlightsList<Flights>* FlightsL;
	string* rawEvents;
public:
	Scheduler();
	bool readFile(string );
	Eventlist prepareSimulation();
	void Simulate(Eventlist Evs);
	void outToFile();
};
