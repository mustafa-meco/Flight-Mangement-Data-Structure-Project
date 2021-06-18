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
//#include "ASSIGNtoLane.h"
//#include "FlyFromTo.h"
//#include "FinishedFlight.h"
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

//template <typename T>       //COMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMENT
class Scheduler
{
private:
	int N_Areas;                                // Number of areas
	int tkft;									//take off time 
	int lndt;									//landing time
	int pnt;									//one passenger on time
	int pft;									//one passenger off time
	Area** AreasL;                              //array of areas     
	int AutoP;                                  //Time which the airplane takes to be promoted  
	int** Dists;                                //matrix for the distances between each Aera and the other one
	int N_Events;                               //number of events 
	//FlightsList<Flights>* FlightsL;
	//string* rawEvents;
	PriorityQueue<EVENTS*> EventList;				// List of the all events
	PriorityQueue<EVENTS*> preparedEvents;			// list of the events after modifications  
	PriorityQueue<Flights*>* AreasWaitinglist;		// Array where each index has a queue for each area
	int normal_flights;                             // number of normal flights    
	int VIP_flights;                                // number of vip flights
	LinkedQueue<Flights*> ServingFlights;           // list of the flights which is served
	LinkedQueue<Flights*> finishedFlights;          // list of flights which are finished and the passengers out 
	void RefershPE(PriorityQueue<EVENTS*> q);          
	void RefershPF(PriorityQueue<Flights*> q,int );
	void RefershLinK(LinkedQueue<Flights*> q);
	int Cargo_Flights;
	int Emergence_Flights;

public:
	
	//Scheduler();
	bool readFile(string );
	PriorityQueue<EVENTS*> prepare();
	void Simulate(PriorityQueue<EVENTS*> Evs);
	void outToFile();
	int getAutoP();
	int getNnormal();
	//static int getvip();
	void setnormal(int normal);
	//static void setvip(int vip);
	void promote(v<Flights*>* f);
	Area* getAreaByID(int, Flights * & reqF);
	bool cancelFlight(int ID);
	void RefershAll();
	int calcFly(Flights* f);
	int calcTO(Flights* f);
	int calcLand(Flights* f);
//	bool CheckLane(Lanes l, int time);
	void serveFlight(Flights *F, int t);
	bool preServe(v<Flights*>* fnode, int cT);
	void RefershAll(int);

	void ServeFligh(Flights *);
	void Refersh(int); 
	//Lanes getLane(Sp , int t1, int t2);
	bool checkLane(Lanes*);
	int getNvip();
	int getNCargo();
	int getNEmergence();

};

