//======================================================================
//*  FILE NAME: sort.h                           |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Final Project                               |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================

#ifndef SORT_H_
#define SORT_H_

#include "flight.h"
#include <vector>
#include "std_lib_facilities_4.h"
#include "Simple_window.h"

using namespace std;

class Sort {
protected:
   unsigned long num_cmps; // number of comparisons performed in sort function
public:
   virtual void sort(vector<Flight>& data) = 0;    // main entry point
   bool testIfSorted(const vector<Flight>& data);        // returns false if not sorted
                                                // true otherwise
   unsigned long getNumCmps() { return num_cmps; }        // returns # of comparisons
   void resetNumCmps() { num_cmps = 0; }
};

class SelectionSort:public Sort {	// SelectionSort class
public:
  int tag_update[10][10]; //Creating a 2 dimensional array, updating the index of object after each iteration
  int num_comp = 0;
  int num_swaps = 0;
  void sort(vector<Flight>& data);		// main entry point
};

class BubbleSort:public Sort {		// BubbleSort class
public:
  int tag_update[10][10]; //Creating a 2 dimensional array, updating the index of object after each iteration
  int num_comp = 0;
  int num_swaps = 0;
  void sort(vector<Flight>& data);		// main entry point
};

#endif //SORT_H_

