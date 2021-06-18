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
	AreasWaitinglist = new PriorityQueue<Flights>[N_Areas];
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
	int j = 0;
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
		if (AvT==1)ar->InsertLanes(type, MA, MT);
		else {
			AddLane* ALEvent = new AddLane(AvT, ar, type, MA, MT);
			EventList.enqueue(*ALEvent, double(AvT));
			delete ALEvent;
		}
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
	double pri;
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
			events = new Booking(Ts,ID,AreasL[TfA], AreasL[LnA], type, Pass);
			//flights f = new flights(tfa, lna, type, ts, id, pass);
			//flightsl.insert(f);
			break;
		case X:
			getline(F, line, ' '); cout << " " + line;
			Ts = stoi(line);
			getline(F, line); cout << " " + line;
			ID = stoi(line);
			events = new Cancellation(Ts,ID);
			break;
		case P:
			getline(F, line, ' '); cout << " " + line;
			Ts = stoi(line);
			getline(F, line); cout << " " + line;
			ID = stoi(line);
			events = new Promotion(Ts,ID);
			break;
		default:
			break;
		}
		cout << endl;
		//ev[i] = { Ts, *events };
		pri = Ts;
		EventList.enqueue(*events,pri);
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

void Scheduler::prepare() {
	int curT = 0; int ID;
	cout << "curT: " << curT;
	
	EVENTS* Event;
	Flights* tempFlight;
	Area* tempArea;
	Lanes* tempLane;
	double Epri;
	double Fpri;
	
	while (EventList.dequeue(*Event,Epri)) {
		ID = Event->getID();
		curT = int(Epri);
		cout << "curT: " << curT << endl;
		EventT Etype = Event->getEventT();
		Booking* BookEvent;
		AddLane* ALEvent;
		switch (Etype)
		{
		case B:
			cout << "Booking Event" << endl;
			BookEvent = dynamic_cast<Booking*>(Event);
			tempFlight = new Flights(curT,ID, BookEvent->getTA(),BookEvent->getLA(), BookEvent->getType(), BookEvent->getNpass());
			Fpri = BookEvent->getType() == VIP ? 0 : 1 /*(formula for priority depending on flight duration and no. of passengers)*/;
			AreasWaitinglist[tempFlight->getTA()->getAreasNum() - 1].enqueue(*tempFlight,Fpri);
			cout << "added to Areas " << tempFlight->getTA()->getAreasNum() << " Waiting list"<< endl;
			//preparedEvents.enqueue(*EventNode);
			break;
		case X:
			if (getAreaByID(ID, tempFlight)) cancelFlight(ID);
			Event = nullptr;
			break;
		case P:
			tempArea = getAreaByID(ID, tempFlight);
			if (tempArea) {
				promote(tempFlight); // TODO make event promotion and add to prepared events
				//tempArea = new Area(ID, );
				AreasWaitinglist[tempArea->getAreasNum() - 1].enqueue(*tempFlight,0);
				//preparedEvents.enqueue(*EventNode);
			}
			else delete Event;
			Event = nullptr;
			break;
		case AL:
			ALEvent = dynamic_cast<AddLane*>(Event);
			ALEvent->getArea()->InsertLanes(ALEvent->getTY(),ALEvent->getMAf(),ALEvent->getMT());
			break;
		//case L:
		//	ASSIGNtoLane * Ass2LaneEvent = static_cast<ASSIGNtoLane>(Event);
		//	*tempLane = Ass2LaneEvent->getAssignedLane1();
		//	getAreaByID(ID,tempFlight);
		//	serveFlight(tempFlight,curT); //call function to move the flight from waiting list to serving list
		//	tempLane->served();
		//	
		//	break;
		//case F:
		//	//FlyFromTo * Fly2Event = static_cast<FlyFromTo>(Event);
		//	*tempLane = Fly2Event->getFromLane();
		//	tempLane->Activate();
		//	break;
		//case FF:
		//	//FinishedFlight * FinFlyEvent = static_cast<FinishedFlight>(Event);
		//	*tempLane = FinFlyEvent->getFinishedLane();
		//	tempLane->Activate();
		//	break;
		default:
			break;
		}
		Lanes* ServLane, *LandLane;
		Sp FlightType;
		PriorityQueue<Flights> tempQ;
		for (int i = 0; i < N_Areas; i++) {
			while (AreasWaitinglist[i].dequeue(*tempFlight,Fpri)) {
				if (preServe(tempFlight, curT)) serveFlight(tempFlight, curT);
				else tempQ.enqueue(*tempFlight,Fpri);
			}
			while (tempQ.dequeue(*tempFlight,Fpri)) AreasWaitinglist[i].enqueue(*tempFlight, Fpri);
		}
		RefershAll(curT);
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


int Scheduler::getAutoP() {
	return AutoP;
}


int Scheduler::getNnormal() {
	return normal_flights;
}
int Scheduler::getNvip() {
	return VIP_flights;
}
//void Scheduler::setnormal(int normal) {
//	normal_flights = normal;
//}
//void Scheduler::setvip(int vip) {
//	//VIP_flights = vip;
//}
bool Scheduler::promote(Flights* f) {
	
	Flights* tempF;
	double pri;
	PriorityQueue<Flights> tempQ;
	while (AreasWaitinglist[getAreaByID(f->getID(), f)->getAreasNum() - 1].dequeue(*tempF,pri)) {
		if (f->getID() == tempF->getID()) {
			AreasWaitinglist[getAreaByID(f->getID(), f)->getAreasNum() - 1].enqueue(*tempF, 0);
			while (tempQ.dequeue(*tempF, pri)) AreasWaitinglist[getAreaByID(f->getID(), f)->getAreasNum() - 1].enqueue(*tempF, pri);
			f->promote();
			normal_flights--;
			VIP_flights++;
			return true;
		}
		tempQ.enqueue(*tempF, pri);
	}
	return false;
}

Area* Scheduler::getAreaByID(int ID, Flights*& reqF)  {
	//Flights* fl = ;
	Flights* tempFlight;
	double Fpri;
	int cou = 0;
	for (int i = 0; i < N_Areas; i++) {
		//v<Flights>* tempf ;
		//AreasWaitinglist[i].dequeue(*tempf);
		PriorityQueue<Flights>* tempQ = new PriorityQueue<Flights>;
		//if (!(tempf->value.getID() == ID))
		while (AreasWaitinglist[i].dequeue(*tempFlight, Fpri)) {
			tempQ->enqueue(*tempFlight, Fpri);
			//flightnode = nullptr;	
			if (tempFlight->getID() == ID) {
				cou++;
				reqF = tempFlight;
				while (tempQ->dequeue(*tempFlight, Fpri))	AreasWaitinglist[i].enqueue(*tempFlight, Fpri);
				break;
			}
		}
		if (cou) {
			return AreasL[i+1];
		}
		while (tempQ->dequeue(*tempFlight, Fpri)) AreasWaitinglist[i].enqueue(*tempFlight, Fpri);
	}
	return NULL;
}

bool Scheduler::cancelFlight(int ID)
{
	Flights* tempF,*f;
	double pri;
	PriorityQueue<Flights> tempQ;
	while (AreasWaitinglist[getAreaByID(ID, f)->getAreasNum() - 1].dequeue(*tempF, pri)) {
		if (ID == tempF->getID()) {
			AreasWaitinglist[getAreaByID(ID, f)->getAreasNum() - 1].enqueue(*tempF, 0);
			while (tempQ.dequeue(*tempF, pri)) AreasWaitinglist[getAreaByID(ID, f)->getAreasNum() - 1].enqueue(*tempF, pri);
			Sp FType = f->getType();
			switch (FType)
			{
			case VIP:
				VIP_flights--;
				break;
			case Normal:
				normal_flights--;
				break;
			default:
				break;
			}
			return true;
		}
		tempQ.enqueue(*tempF, pri);
	}
	return false;
}

void Scheduler::RefershAll(int ct) // To arrange the contents of the list after changing its priopority 
{
	RefershPE(EventList);
	RefershPE(preparedEvents);
	for (int i = 0; i < N_Areas; i++) {
		RefershPF(AreasWaitinglist[i], ct);
	}
	RefershLinK(ServingFlights);
	RefershLinK(finishedFlights);
}

void Scheduler::RefershPE(PriorityQueue<EVENTS> q)
{
	EVENTS* x,*y;
	int i = 0;
	double prix,priy;
	q.peekFront(*x,prix);
	while (q.dequeue(*y,priy))
	{
		if (x==y)
		{
			i++;
		}
		if (i==3)
		{
			break;
		}
		q.enqueue(*y,priy);

	}
}

void Scheduler::RefershPF(PriorityQueue<Flights> q,int ct)
{
	Flights* x,* y;
	double prix, priy;
	int i = 0;
	q.peekFront(*x,prix);
	while (q.dequeue(*y,priy))
	{
		if (x == y)
		{
			i++;
			y->refresh(ct, AutoP);
		}
		if (i == 3)
		{
			break;
		}
		q.enqueue(*y,priy);

	}
}

void Scheduler::RefershLinK(LinkedQueue<Flights> q)
{
	Flights* x;
	Flights* y;

	int i = 0;
	q.peek(*x);
	while (q.dequeue(*y))
	{
		if (x == y)
		{
			i++;
		}
		if (i == 3)
		{
			break;
		}
		q.enqueue(*y);

	}
}
int Scheduler::calcFly(Flights* f) 
{
	Area *AL = f->getLA();
	Area *AT= f->getTA();
	return Dists[AT->getAreasNum()][AL->getAreasNum()];
}

int Scheduler::calcTO(Flights* f)
{
	return (f->getPassNUM() * pnt) + tkft;
}

void Scheduler::serveFlight(Flights* F, int t)
{
	Area* AREA = getAreaByID(F->getID(), F);
	int x = AREA->getAreasNum();
	Flights *tempF;
	double Fpri;
	PriorityQueue<Flights> tempQ;
	while (AreasWaitinglist[x-1].dequeue(*tempF,Fpri))
	{
		if (tempF==F)
		{
			F->toServe(t);
			ServingFlights.enqueue(*tempF);
			break;
		}
		tempQ.enqueue(*tempF,Fpri);
	}
	while (tempQ.dequeue(*tempF,Fpri)) AreasWaitinglist[x - 1].enqueue(*tempF, Fpri);
}

//bool Scheduler::CheckLane(Lanes l, int time)
//{
//	v<EVENTS> e;
//	while (EventList.dequeue(e))
//	{
//		ASSIGNtoLane* a2l = static_cast <ASSIGNtoLane>(e.value);
//		if (a2l)
//		{
//			if (a2l->getAssignedLane1()==l)
//			{
//
//			}
//			return true; 
//		}
//	}
//}

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

void Scheduler::outToFile() {
	string filename = "Output file";
	ofstream file;                                                              //create file with name filename
	file.open(filename + ".txt");
	file << "FT ID BT WT ST \n";
	int FT, ID, BT, WT, ST;
	int sumWT = 0;
	int sumST = 0;

	Flights* F;
	EVENTS* E;
	while (finishedFlights.dequeue(*F)) {
		FT = F->getFT();
		ID = F->getID();
		BT = F->getBT();
		WT = F->getWT();
		sumWT = sumWT + WT;
		ST = F->getST();
		sumST = sumST + ST;

		file << FT << " " << ID << " " << BT << " " << WT << " " << ST << endl;

	}
	file << "Flights: " << getNnormal() + getNvip() << "[Norm: " << getNnormal() << ", VIP: " << getNvip() << endl;
	file << "Areas: " << N_Areas << endl;
	for (int i = 0; i < N_Areas; i++) {
		file << "Area " << i << ":" << "Lanes: " << AreasL[i]->getNumLanes() << endl;
	}
	file << "Avg Wait = " << sumWT / (getNnormal() + getNvip()) << ", Avg Serv = " << sumST / (getNnormal() + getNvip()) << endl;
	file << "Auto-promoted: " << getAutoP() << endl;

}
//bool Scheduler::cancelFlight(Flights* canceledFl, Area * are) {
//	AreasWaitinglist[are->getAreasNum() - 1]
//}

 //Function to assign a Lane and make Assign to Lane Event for both taking off and landing
bool Scheduler::preServe(Flights * fnode, int cT) {
	Sp ftype = fnode->getType();
	int Id = fnode->getID();
	Lanes* ServeLane = NULL;
	Lanes* LandLane = NULL;
	Area* TkAr = fnode->getTA();
	Area* LnAr = fnode->getLA();
	int FlyTime = cT + calcTO(fnode);
	int LandTime = cT + calcTO(fnode) + calcFly(fnode);
	int FinTime = cT + calcTO(fnode) + calcFly(fnode) + calcLand(fnode);
	switch (ftype)
	{
	case VIP:
		ServeLane = TkAr->getVIPlane( cT, FlyTime);
		LandLane = LnAr->getVIPlane(LandTime, FinTime);
	case Normal:
		if (!ServeLane)ServeLane = TkAr->getNORMlane(cT, FlyTime);
		if (!LandLane)LandLane = LnAr->getNORMlane(LandTime, FinTime);
		break;
	default:
		break;
	}
	/*if (ServeLane && LandLane) {
		ASSIGNtoLane* A2L = new ASSIGNtoLane(cT, Id, *ServeLane, *TkAr);
		v<EVENTS>* Enode = nullptr;
		Enode->value = A2L;
		Enode->priority = cT;
		EventList.enqueue(*Enode);
		Enode = nullptr;
		FlyFromTo* Ff2 = new FlyFromTo(cT, Id, *ServeLane, *LandLane);
		Enode->value = Ff2;
		Enode->priority = LandTime;
		return true;
	} */
	if ((ServeLane && !LandLane) || (!ServeLane && LandLane)) {
		if (ServeLane) ServeLane->cancel(cT, FlyTime);
		if (LandLane) LandLane->cancel(LandTime, FinTime);
	}
	return false;
}


int Scheduler::calcLand(Flights* F) {
	return pnt * F->getPassNUM() + lndt;
}

