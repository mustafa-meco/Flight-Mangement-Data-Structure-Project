//#include <iostream>
#include "Flights.h"
#include "Scheduler.h"
//#include "Def.h"
using namespace std;

int main() {

	cout << "Flight Mangement System" << endl;
	Scheduler Sc;
	
	cout << "please enter the input file name" << endl;
	string filename;
	//bool f;
	do {
		cin >> filename;
		//f = Sc.readFile(filename);
	} while (!Sc.readFile(filename));

	//Eventlist Events = Sc.prepareSimulation();
	//Sc.Simulate(Events);
	//cout << "please enter the output file name" << endl;
	
	Sc.outToFile();
	/*cout << "please enter the output file name --- (Default: FlightOutput.txt)\nenter 0 for default";
	cin >> filename;
	if (filename == 0) 
		Sc.OutFile("FlightOutput.txt");
	return 0;*/
}