#include "Scheduler.h"
using namespace std;


bool Scheduler::readFile(string filename) {
	ifstream F;
	
	F.open(filename);
	if (!F) return false;
	string line;
	
	getline(F, line, ' ');
	AreasL = new AreasList<Area>(stoi(line));
	getline(F, line, ' ');
	//TODO take off time //DONE
	tkft = stoi(line);
	getline(F, line, ' ');
	//TODO landing time //DONE
	lndt = stoi(line);
	getline(F, line, ' ');
	//TODO on-boarding time //DONE
	pnt = stoi(line);
	getline(F, line);
	//TODO off-boarding time //DONE
	pft = stoi(line);
	for (int i = 0; i < AreasL->getNumAreas() ; i++) {
		getline(F, line, ' ');
		Area* a = new Area(i,stoi(line)); //TODO store into DS 
		AreasL->InsertArea(a);
		getline(F, line);
		char* value = new char[line.length() + 1];
		strcpy(value, line.c_str());
		
		//TODO store the dist. in matrix
		for (int j = 0; j < AreasL->getNumAreas(); j++) {
			if (j == i) AreasL->addDist(i + 1, 0);
			else {
				strtok(value, " ");
				AreasL->addDist(i + 1, stoi(value));
			}
		}
		delete[] value;
	}

	Sp type;
	int AvT, MA, MT;
	Area* ar;
	for (int i = 0; i < AreasL->getNumAreas(); i++) {
		getline(F, line, ' ');
		ar = AreasL->getArea(stoi(line));
		for (int j = 0; j < ar->getNumLanes(); j++) {
			getline(F, line, ' ');
			if (line == "V") type = VIP;
			else type = Normal;
			getline(F, line, ' ');
			AvT = stoi(line);
			getline(F, line, ' ');
			MA = stoi(line);
			getline(F, line);
			MT = stoi(line);
			ar->InsertLanes(type, AvT, MA, MT);
		}
	}
	getline(F, line);
	AutoP = stoi(line);
	getline(F, line);
	N_Events = stoi(line);
	//rawEvents = new string[N_Events];
	EventT E;
	int TfA, LnA, Ts, ID, Pass;
	Sp type;
	EVENTS* events;
	v<EVENTS>* ev;
	
	//FlightsL = new FlightsList();
	for (int i = 0; i < N_Events; i++) {
		getline(F, line, ' ');
		//rawEvents[i] = line;
		if (line == "B") E = B;
		else if (line == "X") E = X;
		else if (line == "P") E = P;

		switch (E)
		{
		case B:
			getline(F, line, ' ');
			TfA = stoi(line);
			getline(F, line, ' ');
			LnA = stoi(line);
			getline(F, line, ' ');
			if (line == "v") type = VIP;
			else type = Normal;
			getline(F, line, ' ');
			Ts = stoi(line);
			getline(F, line, ' ');
			ID = stoi(line);
			getline(F, line);
			Pass = stoi(line);
			
			events = new Booking(ID, E, AreasL->getArea(TfA), AreasL->getArea(LnA), type, Pass);
			


			//flights f = new flights(tfa, lna, type, ts, id, pass);
			//flightsl.insert(f);
			break;
		case X:
			getline(F, line, ' ');
			Ts = stoi(line);
			getline(F, line);
			ID = stoi(line);
			events = new Cancellation(ID, E);

			break;
		case P:
			getline(F, line, ' ');
			Ts = stoi(line);
			getline(F, line);
			ID = stoi(line);
			events = new Promotion(ID, E);

			break;
		default:
			break;
		}
		ev->priority = Ts;
		ev->value = *events;
		EventList->enqueue(*ev);
		delete events;
		events = NULL;
		ev = NULL;
	}
	
	

	

}


Eventlist Scheduler::prepareSimulation() {
	
	v<EVENTS>* ev;
	EVENTS* eve;
	EventList->dequeue(*ev);
	eve = &ev->value;
	int ID = eve->getID();
	switch(eve->getEventT()) {
	case B:
		Booking* Be = static_cast<Booking*>(eve);
		Flights* fl = new Flights(ID,Be->getAreas(),Be.);

	}

}	