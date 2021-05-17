#include <iostream>
#include "Flights.h"
#include "Scheduler.h"
using namespace std;

void main() {

	Scheduler Sc;
	cout << "Flight Mangement System" << endl;
	cout << "please enter the input file name" << endl;
	string filename;
	do {
		cin >> filename;
		bool f = Sc.readFile(filename);
	} while (!f);
	
	//cout << "please enter the output file name --- (Default: FlightOutput.txt)\nenter 0 for default";
	//cin >> filename;
	//if (filename == 0) 
		//Sc.OutFile("FlightOutput.txt");

}