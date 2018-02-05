//======================================================================
//*  FILE NAME: flight.cpp                       |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Final Project                               |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================

#include <string>
#include <iostream>
#include <algorithm>
#include "flight.h"

using std::string;
using namespace std;

string Flight::get_flight_number() const{
	return flight_number;
}
string Flight::get_destination() const{
	return destination;
}
int Flight::get_departure_time() const{
	int temp;
	char colon = ':';
	string temps = departure_time;
	temps.erase(std::remove(temps.begin(), temps.end(), colon), temps.end()); //Removing colon in the time data
	temp = stoi(temps);
	return temp;
}
string Flight::get_gate_number() const{
	return gate_number;
}
//Returning the special tag, use for FLTK graphic sort
int Flight::get_tag() const {
	return tag;
}
void Flight::display() const{
	cout << "Flight number: " << flight_number << '\n'
		 << "Destination: " << destination << '\n'
		 << "Departure Time : " << departure_time << '\n'
		 << "Gate Number: " << gate_number << '\n' << endl;
}	