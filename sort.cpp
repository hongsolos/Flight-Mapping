//======================================================================
//*  FILE NAME: sort.cpp                         |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Final Project                               |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================


#include "sort.h"
#include "flight.h"
#include <vector>
#include "std_lib_facilities_4.h"
#include "Simple_window.h"

using namespace std;

//Selection Sorting algorithm:
//Comparing flight objects by time
void SelectionSort::sort(vector<Flight>& data){
	for (int i = 0; i < 10; i++){
		SelectionSort::tag_update[i][0] = i;
	}
	int column = 0;
	int pos_min;
	Flight temp;
	int n = data.size();
	for (int i = 0; i < n-1; i++){
	    pos_min = i;
		for (int j = i+1; j < n; j++){
			SelectionSort::num_comp++;
			if (data[j].get_departure_time() < data[pos_min].get_departure_time())
				pos_min=j;
		}
        if (pos_min != i){
            temp = data[i];
            data[i] = data[pos_min];
            data[pos_min] = temp;
			SelectionSort::num_swaps++;
		}
		column++;
		for (int j = 0; j < 10; j++){
			SelectionSort::tag_update[j][column] = data[j].get_tag(); //Push the updated positions into the a vector
		}
	}
}
//Bubble Sorting algorithm:
//Comparing flight objects by time
void BubbleSort::sort(vector<Flight>& data){
    Flight tmp;
	int n = data.size();
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n - 1; i++) {
            if (data[i].get_departure_time() > data[i + 1].get_departure_time()) {
				BubbleSort::num_comp++;
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
				BubbleSort::num_swaps++;
			}
        }
		for (int i = 0; i < 10; i++){
			BubbleSort::tag_update[i][j] = data[i].get_tag(); //Push the updated positions into the a vector
		}
    }
}