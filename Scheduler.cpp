#include "Scheduler.h"


Scheduler::Scheduler() {
	
}

bool Scheduler::readFile(string filename) {
	ifstream F;
	
	F.open(filename); cout << "Filename: " << filename << endl;
	if (!F) return false;
	string line;
	
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
		AreasL[i+1];
		
		//char* value = new char[line.length() + 1];
		//strcpy_s(value, line.c_str());
		Dists[i] = new int[N_Areas];
		//TODO store the dist. in matrix
		for (int j = 0; j < N_Areas; j++) {
			if (j == i) Dists[i][j] = 1;
			else {
				if (j == N_Areas - 1) getline(F, line);
				else getline(F, line, ' '); 
				cout << line << "( ";
				Dists[i][j] = stoi(line);
			}
		}
		//delete[] value;
		cout << endl;
	}
	Sp type;
	int AvT, MA, MT;
	Area* ar;
	cout << "Each Lane in each Area: \n";
	for (int i = 0; i < N_Areas; i++) {
		getline(F, line, ' '); cout << line;
		ar = AreasL[stoi(line)];
		for (int j = 0; j < ar->getNumLanes(); j++) {
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
	}
	getline(F, line); cout << "Auto Promotion time: " + line << endl;
	AutoP = stoi(line);
	getline(F, line); cout << "Number of Events: " + line << endl;
	N_Events = stoi(line);
	//rawEvents = new string[N_Events];
	EventT E;
	int TfA, LnA, Ts, ID, Pass;
	//Sp type;
	EVENTS* events;
	v<EVENTS>* ev = new v<EVENTS>[N_Events];
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
		ev[i].value = *events;
		EventList.enqueue(ev[i]);
		delete events;
		events = NULL;
		ev = NULL;
	}
}

//PriorityQueue<EVENTS> Scheduler::prepareSimulation() {
//	v<EVENTS>* ev;
//	EVENTS* eve;
//	EventList->dequeue(*ev);
//	eve = &ev->value;
//	int ID = eve->getID();
//	Flights* fl;
//	v<Flights>* flightnode;
//	Area* tempArea;
//	switch(eve->getEventT()) {
//	case B:
//		Booking* Be = static_cast<Booking*>(eve);
//		fl = new Flights(ID,Be->getAreas(), Be->getType(), ev->priority, Be->getNpass());
//		flightnode->priority = Be->getType() == VIP ? 0 :NULL /*(formula for priority depending on flight duration and no. of passengers)*/;
//		AreasWaitinglist[fl->getTA()->getAreasNum() - 1].enqueue(*flightnode);
//		break;
//	case X:
//		tempArea = getAreaByID(ID,fl);
//		//if (tempArea) cancelFlight(fl);
//		delete fl;
//		//else;
//		break;
//	case P:
//		tempArea = getAreaByID(ID, fl);
//		if (tempArea) /*promoteflight(fl)*/fl->promote();
//		flightnode->value = *fl;
//		flightnode->priority = 0;
//		AreasWaitinglist[tempArea->getAreasNum() - 1].enqueue(*flightnode);
//		break;
//	}
//	int c ;
//	Lanes* ServLane;
//	for (int i = 0; i < N_Areas; i++) {
//		c = 0;
//		if (AreasWaitinglist[i].peek(*flightnode)) {
//			switch (flightnode->value.getType())
//			{
//			case VIP:
//				ServLane = flightnode->value.getTA()->getVIPlane(flightnode->priority);
//				if (ServLane) {
//					AreasWaitinglist[i].dequeue(*flightnode);
//					c++;
//					break;
//				}
//			case Normal:
//				ServLane = flightnode->value.getTA()->getNORMlane(flightnode->priority);
//				if (ServLane) {
//					AreasWaitinglist[i].dequeue(*flightnode);
//					c++;
//				}
//				break;
//			}
//		}
//		if (c = 0) {
//			
//		}
//	}
//
//
//}	

//int Scheduler::getAutoP() {
//	return AutoP;
//}

//void Scheduler::setAutoP(int AutoP) {
//	AutoP = AutoP;
//}
int Scheduler::getnormal() {
	return normal_flights;
}
//int Scheduler::getvip() {
//	//return VIP_flights;
//}
void Scheduler::setnormal(int normal) {
	normal_flights = normal;
}
//void Scheduler::setvip(int vip) {
//	//VIP_flights = vip;
//}

Area* Scheduler::getAreaByID(int ID, Flights*& reqF)  {
	//Flights* fl = ;
	v<Flights>* flightnode = nullptr;
	int cou = 0;
	for (int i = 0; i < N_Areas; i++) {
		//v<Flights>* tempf ;
		//AreasWaitinglist[i].dequeue(*tempf);
		PriorityQueue<Flights>* tempQ = new PriorityQueue<Flights>;
		//if (!(tempf->value.getID() == ID))
		while (AreasWaitinglist[i].dequeue(*flightnode)) {
			tempQ->enqueue(*flightnode);
			flightnode = nullptr;	
			if (flightnode->value.getID() == ID) {
				cou++;
				*reqF = flightnode->value;
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
//void outputfile() {
//	string filename = "Output file";
//	ofstream file;                                                              //create file with name filename
//	file.open(filename + ".txt");
//	file << "FT ID BT WT ST \n";
//	string line;
//	for (int i = 0; i < getnormal(); i++) {
//
//		cout << line;
//		int ind;
//		for (int j = 0; j < line.length(); j++) {
//			if (line.at(j) == '1') {
//				ind = j;
//				break;
//			}
//		}
//		line = line.substr(0, ind) + to_string(i + 1) + line.substr(ind + 1, line.length() - ind);
//
//		file << line;
//	}
//}
//bool Scheduler::cancelFlight(Flights* canceledFl, Area * are) {
//	AreasWaitinglist[are->getAreasNum() - 1]
//}