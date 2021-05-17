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
		Area* a = new Area(i); //TODO store into DS 
		
		for (int x = 0; x < stoi(line); x++) a->InsertLane();
		//TODO store the dist. in matrix
		for (int j = 0; j < AreasL->getNumAreas(); j++) {
			if (j == i) AreasL->addDist(i, 0);	
		}
	}
}