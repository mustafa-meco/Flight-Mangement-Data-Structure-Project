#include "Scheduler.h"
using namespace std;


bool Scheduler::readFile(string filename) {
	ifstream F;
	
	F.open(filename);
	if (!F) return false;
	
	string line;
	getline(F, line, ' ');
	numAreas = stoi(line);
	getline(F, line, ' ');
	//TODO take off time
	getline(F, line, ' ');
	//TODO landing time
	getline(F, line, ' ');
	//TODO on-boarding time
	getline(F, line);
	//TODO off-boarding time
	for (int i = 0; i < numAreas; i++) {
		getline(F, line, ' ');
		Area* a = new Area(stoi(line)); //TODO store into DS 
		//TODO store the dist. in matrix
	}
}