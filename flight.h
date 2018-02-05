//======================================================================
//*  FILE NAME: flight.h                         |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Final Project                               |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Flight
{
	private:
		string flight_number;
		string destination;
		string departure_time;
		string gate_number;
		int tag; //Tag used for FLTK graphic sorting
	public:
		Flight() {}
		Flight(const string &a, const string &b, const string &c, const string &d, const int &e) :
			flight_number(a), destination(b), departure_time(c), gate_number(d), tag(e){}
		
		string get_flight_number() const;
		string get_destination() const;
		int get_departure_time() const;
		string get_gate_number() const;
		int get_tag() const;
		void display() const;
};
#endif