#pragma once
#include "Scheduler.h"


//Scheduler::Scheduler() {
//	
//}

bool Scheduler::readFile(string filename) {
	ifstream F;
	
	F.open(filename); cout << "Filename: " << filename << endl;
	if (!F) return false;
	string line = " ";
	
	getline(F, line, ' '); cout << "No. of Areas: " + line << endl;
	N_Areas = stoi(line); 
	AreasL = new Area*[N_Areas+1];
	AreasWaitinglist = new PriorityQueue<Flights*>[N_Areas];
	getline(F, line, ' '); cout << "Take off time: " + line << endl;
	//TODO take off time //DONE
	tkft = stoi(line); 
	getline(F, line, ' '); cout << "Landing time: " + line << endl;
	//TODO landing time //DONE
	lndt = stoi(line);
	getline(F, line, ' '); cout << "Passenger On B. time: " + line << endl;
	//TODO on-boarding time //DONE
	pnt = stoi(line);
	getline(F, line); cout << "Passenger Off B. time " + line << endl;
	//TODO off-boarding time //DONE
	pft = stoi(line);
	cout << "Each Area No. of Lanes and Dist.s \n";
	Dists = new int* [N_Areas];
	for (int i = 0; i < N_Areas ; i++) {
		getline(F, line, ' '); cout << line << " ";
		Area* a = new Area(i,stoi(line)); //TODO store into DS 
		AreasL[i+1]= a;
		
		//char* value = new char[line.length() + 1];
		//strcpy_s(value, line.c_str());
		Dists[i] = new int[N_Areas];
		//TODO store the dist. in matrix
		for (int j = 0; j < N_Areas-1; j++) {
			//if (j == i) Dists[i][j] = 1;
			//else {
				if (j == N_Areas - 2 ) 
					getline(F, line);
				else getline(F, line, ' '); 
				cout << line << "( ";
				Dists[i][j] = stoi(line);
			//}
		}
		Dists[i][i] = 0;
		//delete[] value;
		cout << endl;
	}
	Sp type;
	int AvT, MA, MT;
	Area* ar = nullptr;
	cout << "Each Lane in each Area: \n";
	int total_N_Lanes = 0;
	for (int i = 0; i < N_Areas; i++) total_N_Lanes += AreasL[i + 1]->getNumLanes();
	for (int i = 0; i < total_N_Lanes; i++) {
		getline(F, line, ' '); cout << line;
		ar = AreasL[stoi(line)];
		getline(F, line, ' '); cout << " " << line;
		if (line == "V") type = VIP;
		else type = Normal;
		getline(F, line, ' '); cout << " " << line;
		AvT = stoi(line);
		getline(F, line, ' '); cout << " " << line;
		MA = stoi(line);
		getline(F, line); cout << " " << line << endl;
		MT = stoi(line);
		ar->InsertLanes(type, AvT, MA, MT);
	}
	getline(F, line); cout << "Auto Promotion time: " + line << endl;
	AutoP = stoi(line);
	getline(F, line); cout << "Number of Events: " + line << endl;
	N_Events = stoi(line);
	//rawEvents = new string[N_Events];
	EventT E;
	int TfA, LnA, Ts, ID, Pass;
	//Sp type;
	EVENTS* events = nullptr;
	v<EVENTS*>* ev = new v<EVENTS*>[N_Events];
	//FlightsL = new FlightsList();
	for (int i = 0; i < N_Events; i++) {
		getline(F, line, ' '); cout << line;
		//rawEvents[i] = line;
		if (line == "B") E = B;
		else if (line == "X") E = X;
		else if (line == "P") E = P;
		switch (E)
		{
		case B:
			getline(F, line, ' '); cout << " " + line;
			TfA = stoi(line);
			getline(F, line, ' '); cout << " " + line;
			LnA = stoi(line);
			getline(F, line, ' '); cout << " " + line;
			if (line == "v") type = VIP;
			else type = Normal;
			getline(F, line, ' '); cout << " " + line;
			Ts = stoi(line);
			getline(F, line, ' '); cout << " " + line;
			ID = stoi(line);
			getline(F, line); cout << " " + line;
			Pass = stoi(line);
			events = new Booking(ID,AreasL[TfA], AreasL[LnA], type, Pass);
			//flights f = new flights(tfa, lna, type, ts, id, pass);
			//flightsl.insert(f);
			break;
		case X:
			getline(F, line, ' '); cout << " " + line;
			Ts = stoi(line);
			getline(F, line); cout << " " + line;
			ID = stoi(line);
			events = new Cancellation(ID);
			break;
		case P:
			getline(F, line, ' '); cout << " " + line;
			Ts = stoi(line);
			getline(F, line); cout << " " + line;
			ID = stoi(line);
			events = new Promotion(ID);
			break;
		default:
			break;
		}
		cout << endl;
		//ev[i] = { Ts, *events };
		ev[i].priority = Ts;
		ev[i].value = events;
		EventList.enqueue(ev[i]);
		delete events;
		events = NULL;
	}
}

//==============================================================================================================||
//																												||
//												CONSTRUCTION AREA												||
//																												||
//==============================================================================================================||
//																						  /\					||
//				 /[]\																	 //\\					||
//				/ ||  \																	//	\\					||	
//			   /  ||    \															   //	 \\					||
//	[]============||=================================================[]				  //	  \\				||
//                ||												 ||				 //		   \\				||
//                ||												 ||				//			\\				||
//				  ||											     || 		   //			 \\				||
//				  ||												 /\			  //			  \\			||
//				  ||												/  \	     //				   \\			||
//				  ||				  []				  [<code>][<code>]      //					\\			||
//				  ||              []--||-------------    [<public>][<public>]  //					 \\			||
//================||==================||============|=========================//					  \\		||
//				  ||CONSTRUCTION AREA ||            |		[<private>]		 //						   \\		||
//================||==================[]============|=======================//							\\		||
//				  ||				   [<class>][<class>][<class>]		   //							 \\		||
//				  ||			[<object>][<object>][<object>][<object>]  //							  \\	||
//----------------[]-----------------------------------------------------//--------------------------------\\---||
//==============================================================================================================||
//==============================================================================================================||


PriorityQueue<EVENTS*> Scheduler::prepare() {
	int curT = 0; int ID;
	v<EVENTS*>* EventNode = nullptr;
	EVENTS* Event;
	Flights* tempFlight;
	v<Flights*>* FlightNode;
	Area* tempArea;
	Lanes* tempLane;
	
	while (EventList.dequeue(*EventNode)) {
		Event = EventNode->value;
		ID = Event->getID();
		curT = EventNode->priority;
		EventT Etype = Event->getEventT();
		switch (Etype)
		{
		case B:
			Booking* BookEvent = static_cast<Booking*>(Event);
			tempFlight = new Flights(ID, BookEvent->getAreas(), BookEvent->getType(), EventNode->priority, BookEvent->getNpass());
			FlightNode->priority = BookEvent->getType() == VIP ? 0 : NULL /*(formula for priority depending on flight duration and no. of passengers)*/;
			AreasWaitinglist[tempFlight->getTA()->getAreasNum() - 1].enqueue(*FlightNode);
			//preparedEvents.enqueue(*EventNode);
			break;
		case X:
			if (getAreaByID(ID, tempFlight)) cancelFlight(ID);
			else delete EventNode->value;
			Event = nullptr;
			break;
		case P:
			if (getAreaByID(ID, tempFlight)) {
				/*promoteflight(fl)*/tempFlight->promote(); // TODO make event promotion and add to prepared events
				FlightNode->value = tempFlight;
				FlightNode->priority = 0;
				AreasWaitinglist[tempArea->getAreasNum() - 1].enqueue(*FlightNode);
				preparedEvents.enqueue(*EventNode);
			}
			else delete EventNode->value;
			Event = nullptr;
			break;
		case L:
			ASSIGNtoLane * Ass2LaneEvent = static_cast<ASSIGNtoLane*>(Event);
			*tempLane = Ass2LaneEvent->getAssignedLane1();
			getAreaByID(ID,tempFlight);
			//TODO
			//ServeFlight(tempFlight,curT); //call function to move the flight from waiting list to serving list
			//TODO
			//tempLane->Served() /*call function to apply that it has been used and decrement the Maintainance after*/
			break;
		case F:
			FlyFromTo * Fly2Event = static_cast<FlyFromTo*>(Event);
			*tempLane = Fly2Event->getFromLane();
			tempLane->Activate();
			break;
		case FF:
			FinishedFlight * FinFlyEvent = static_cast<FinishedFlight*>(Event);
			*tempLane = FinFlyEvent->getFinishedLane();
			tempLane->Activate();
			break;
		default:
			break;
		}
		Lanes* ServLane, *LandLane;
		Sp FlightType;
		for (int i = 0; i < N_Areas; i++) {
			int c = 0;
			while (c == 0) {
				if (AreasWaitinglist[i].dequeue(*FlightNode)) {
					//TODO
					//preServe(FlightNode) //Function to assign a Lane and make Assign to Lane Event for both taking off and landing 
				}
			}
			//refresh();
		}
		///////////////////////
		for (int i = 0; i < N_Areas; i++) {
			int c = 0;
			do {
				if (AreasWaitinglist[i].peek(*FlightNode)) {
					//LnT = curT + calcTO(flightnode->value) + calcFly(flightnode->value);
					switch (FlightNode->value->getType())
					{
					case VIP:
						
						if (FlightNode->value->getTA()->checkV(curT) && FlightNode->value->getLA()->checkV(LnT)) {

							ServLane = flightnode->value->getTA()->getVIPlane(curT);
							//LandLane = flightnode->value->getLA()->getVIPlane(LnT);
							AreasWaitinglist[i].dequeue(*flightnode);
							ASSIGNtoLane* EV = new ASSIGNtoLane(curT);
						}

						//if (ServLane) {
						//	/*AreasWaitinglist[i].dequeue(*flightnode);
						//	ASSIGNtoLane *= new ASSIGNtoLane();*/
						//	//c++;
						//	break;
						//}
					case Normal:
						ServLane = flightnode->value->getTA()->getNORMlane(curT);
						/*if (ServLane) {
							AreasWaitinglist[i].dequeue(*flightnode);
							c++;
						}
						else c = 0;*/
						break;
					}
					switch (flightnode->value->getType())
					{
					case VIP:
						LandLane = flightnode->value.getLA()->getVIPlane(curT + calcTO(flightnode->value) + calcFly(flightnode->value));
						if (LandLane) {
							break;
						}

					case Normal:
						LandLane = flightnode->value->getLA()->getNORMlane(curT + calcTO(flightnode->value) + calcFly(flightnode->value));
						/*if (ServLane) {
							AreasWaitinglist[i].dequeue(*flightnode);
							c++;
						}
						else c = 0;*/
						break;
					}
					if (ServLane && LandLane) {
						AreasWaitinglist[i].dequeue(*flightnode);

						ASSIGNtoLane *= new ASSIGNtoLane();
						c++;
						break;
					}
					ServLane->Serving();
						ServLane = NULL;
				}
			} while (c);
		}
	}
}

PriorityQueue<EVENTS*> Scheduler::prepare() {
	int curT = 0;
	int nextT = 0;
	int tempT = 0;
	for (int i = 0; i < N_Events; i++) {
		v<EVENTS*>* ev = nullptr;
		v<EVENTS*>* nextev = nullptr;
		EVENTS* eve;
		EventList.dequeue(*ev);
		eve = ev->value;
		int ID = eve->getID();
		Flights* fl;
		v<Flights*>* flightnode = nullptr;
		Area* tempArea;
		curT = ev->priority;
		nextT = ev->priority;
		switch (eve->getEventT()) {
		case B:
			Booking* Be = static_cast<Booking*>(eve);
			fl = new Flights(ID, Be->getAreas(), Be->getType(), ev->priority, Be->getNpass());
			flightnode->priority = Be->getType() == VIP ? 0 : NULL /*(formula for priority depending on flight duration and no. of passengers)*/;
			AreasWaitinglist[fl->getTA()->getAreasNum() - 1].enqueue(*flightnode);
			preparedEvents.enqueue(*ev);
			//TODO make event booking and add to preparedevents
			break;
		case X:
			if (getAreaByID(ID, fl)) cancelFlight(ID);
			else delete ev->value;
			//if (tempArea) cancelFlight(fl); // TODO make event cancel and add to preparedevents
			//delete fl;
			//else //TODO donothing;
			break;
		case P:
			if (getAreaByID(ID, fl)) {
				/*promoteflight(fl)*/fl->promote(); // TODO make event promotion and add to prepared events
				flightnode->value = fl;
				flightnode->priority = 0;
				AreasWaitinglist[tempArea->getAreasNum() - 1].enqueue(*flightnode);
				preparedEvents.enqueue(*ev);
			}
			else delete ev->value;
			break;
		}
		int c;

		Lanes* ServLane = NULL;
		Lanes* LandLane = NULL;
		int LnT;
		while (tempT < nextT) {
			for (int i = 0; i < N_Areas; i++) {
				c = 0;
				do {
					if (AreasWaitinglist[i].peek(*flightnode)) {
						LnT = curT + calcTO(flightnode->value) + calcFly(flightnode->value);
						switch (flightnode->value->getType())
						{
						case VIP:
							if (flightnode->value->getTA()->checkV(curT) && flightnode->value->getLA()->checkV(LnT)) {
								ServLane = flightnode->value->getTA()->getVIPlane(curT);
								LandLane = flightnode->value->getLA()->getVIPlane(LnT);
								AreasWaitinglist[i].dequeue(*flightnode);
								ASSIGNtoLane * EV= new ASSIGNtoLane(curT);
							}

							//if (ServLane) {
							//	/*AreasWaitinglist[i].dequeue(*flightnode);
							//	ASSIGNtoLane *= new ASSIGNtoLane();*/
							//	//c++;
							//	break;
							//}
						case Normal:
							ServLane = flightnode->value->getTA()->getNORMlane(curT);
							/*if (ServLane) {
								AreasWaitinglist[i].dequeue(*flightnode);
								c++;
							}
							else c = 0;*/
							break;
						}
						switch (flightnode->value->getType())
						{
						case VIP:
							LandLane = flightnode->value.getLA()->getVIPlane(curT + calcTO(flightnode->value) + calcFly(flightnode->value));
							if (LandLane) {
								break;
							}

						case Normal:
							LandLane = flightnode->value->getLA()->getNORMlane(curT + calcTO(flightnode->value) + calcFly(flightnode->value));
							/*if (ServLane) {
								AreasWaitinglist[i].dequeue(*flightnode);
								c++;
							}
							else c = 0;*/
							break;
						}
						if (ServLane && LandLane) {
							AreasWaitinglist[i].dequeue(*flightnode);

							ASSIGNtoLane *= new ASSIGNtoLane();
							c++;
							break;
						}
						ServLane->Serving()
							ServLane = NULL;
					}
				} while (c);
			}
		}
		
	}
	
	return preparedEvents;
}


//==============================================================================================================||
//																												||
//												CONSTRUCTION AREA												||
//																												||
//==============================================================================================================||
//																						  /\					||
//				 /[]\																	 //\\					||
//				/ ||  \																	//	\\					||	
//			   /  ||    \															   //	 \\					||
//	[]============||=================================================[]				  //	  \\				||
//                ||												 ||				 //		   \\				||
//                ||												 ||				//			\\				||
//				  ||											     || 		   //			 \\				||
//				  ||												 /\			  //			  \\			||
//				  ||												/  \	     //				   \\			||
//				  ||				  []				  [<code>][<code>]      //					\\			||
//				  ||              []--||-------------    [<public>][<public>]  //					 \\			||
//================||==================||============|=========================//					  \\		||
//				  ||CONSTRUCTION AREA ||            |		[<private>]		 //						   \\		||
//================||==================[]============|=======================//							\\		||
//				  ||				   [<class>][<class>][<class>]		   //							 \\		||
//				  ||			[<object>][<object>][<object>][<object>]  //							  \\	||
//----------------[]-----------------------------------------------------//--------------------------------\\---||
//==============================================================================================================||
//==============================================================================================================||


int Scheduler::getAutoP() {
	return AutoP;
}

void Scheduler::setAutoP(int AutoP) {
	AutoP = AutoP;
}
int Scheduler::getnormal() {
	return normal_flights;
}
int Scheduler::getvip() {
	return VIP_flights;
}
void Scheduler::setnormal(int normal) {
	normal_flights = normal;
}
//void Scheduler::setvip(int vip) {
//	//VIP_flights = vip;
//}
void Scheduler::promote(v<Flights*>* f) {
	normal_flights--;
	VIP_flights++;
	f->priority = 0;
}

Area* Scheduler::getAreaByID(int ID, Flights*& reqF)  {
	//Flights* fl = ;
	v<Flights*>* flightnode = nullptr;
	int cou = 0;
	for (int i = 0; i < N_Areas; i++) {
		//v<Flights>* tempf ;
		//AreasWaitinglist[i].dequeue(*tempf);
		PriorityQueue<Flights*>* tempQ = new PriorityQueue<Flights*>;
		//if (!(tempf->value.getID() == ID))
		while (AreasWaitinglist[i].dequeue(*flightnode)) {
			tempQ->enqueue(*flightnode);
			//flightnode = nullptr;	
			if (flightnode->value->getID() == ID) {
				cou++;
				reqF = flightnode->value;
				while (tempQ->dequeue(*flightnode))	AreasWaitinglist[i].enqueue(*flightnode);
				break;
			}
		}
		if (cou) {
			return AreasL[i+1];
		}
		while (tempQ->dequeue(*flightnode)) AreasWaitinglist[i].enqueue(*flightnode);
	}
	return NULL;
}

bool Scheduler::cancelFlight(int ID)
{
	v<EVENTS*> *temp= nullptr;
	preparedEvents.dequeue(*temp);
	Booking *P =static_cast <Booking*> (temp->value);
	v<EVENTS*>* first = temp;

	do
	{
		if (P->getID()==ID)
		{
			delete temp;
			return true; 
		}
		else
		{
			preparedEvents.enqueue(*temp);
		}
		preparedEvents.dequeue(*temp);

	} while (first != temp);

	preparedEvents.enqueue(*temp);
	return false;
}

void Scheduler::RefershAll() // To arrange the contents of the list after changing its priopority 
{
	RefershP(EventList);
	RefershP(preparedEvents);
	RefershP(*AreasWaitinglist);
	RefershLinK(ServingFlights);
	RefershLinK(finishedFlights);
}

template <typename T>
void Scheduler::RefershP(PriorityQueue<T*> q)
{
	T x,y;
	int i = 0;
	q.peek(x);
	while (q.dequeue(y))
	{
		if (x==y)
		{
			i++;
		}
		if (i==3)
		{
			break;
		}
		q.enqueue(y);

	}
}

void Scheduler::RefershLinK(LinkedQueue<Flights*> q)
{
	Flights* x;
	Flights* y;

	int i = 0;
	q.peek(x);
	while (q.dequeue(y))
	{
		if (x == y)
		{
			i++;
		}
		if (i == 3)
		{
			break;
		}
		q.enqueue(y);

	}
}

//Lanes* Area::getVIPlane(int t)
//{
//	//	Sp type;
//	// 	   
//		//for (/*int i = 0; i < NumOfLanes; i++*/)   
//	Lanes* temp = nullptr;
//	lanesLIST->dequeue(temp);
//	Lanes* l = temp;
//	do
//	{
//		if (l->getType() == VIP && l->check(t))
//		{
//			countVIP++;
//			return l;
//		}
//		else
//		{
//			lanesLIST->enqueue(l);
//		}
//		lanesLIST->dequeue(l);
//
//	} while (l != temp);
//	lanesLIST->enqueue(l);
//	return NULL;
//
//}

void Scheduler::outputfile() {
	string filename = "Output file";
	ofstream file;                                                              //create file with name filename
	file.open(filename + ".txt");
	file << "FT ID BT WT ST \n";
	int FT, ID, BT, WT, ST;
	int sumWT = 0;
	int sumST = 0;

	Flights* F;
	EVENTS* E;
	while (finishedFlights.dequeue(F)) {
		FT = F->getFT();
		ID = F->getID();
		BT = F->getBT();
		WT = F->getWT();
		sumWT = sumWT + WT;
		ST = F->getST();
		sumST = sumST + ST;

		file << FT << " " << ID << " " << BT << " " << WT << " " << ST << endl;

	}
	file << "Flights: " << getnormal() + getvip() << "[Norm: " << getnormal() << ", VIP: " << getvip() << endl;
	file << "Areas: " << N_Areas << endl;
	for (int i = 0; i < N_Areas; i++) {
		file << "Area " << i << ":" << "Lanes: " << AreasL[i]->getNumLanes() << endl;
	}
	file << "Avg Wait = " << sumWT / (getnormal() + getvip()) << ", Avg Serv = " << sumST / (getnormal() + getvip()) << endl;
	file << "Auto-promoted: " << getAutoP() << endl;

}
//bool Scheduler::cancelFlight(Flights* canceledFl, Area * are) {
//	AreasWaitinglist[are->getAreasNum() - 1]
//}






