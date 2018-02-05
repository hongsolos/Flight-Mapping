//======================================================================
//*  FILE NAME: main.cpp                         |* * * * * |##########|
//*  NAME: Han Hong                              | * * * * *|##########|
//*  Final Project                               |* * * * * |##########|
//*  CSCE 113 SECTION 501                        |#####################|
//*  UIN: 824000237                              |#####################|
//======================================================================

#include "sort.h"
#include "flight.h"
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;
using namespace std;

int main(){
	//Reading portion: read each set of info, push them into separate vectors. Assuming format is correct when given ==========================
	string filename;
	fstream read;
	bool state = false;
	while (!state){
		cout << "Please enter file name (with extension): ";
		cin >> filename;
		read.open(filename);
		if (read.good())
			state = true;
	}
	string line;
	vector <string> inputs, flight, destination, time, gate;
	read.ignore( std::numeric_limits<std::streamsize>::max(), '\n') ; //Ignore the first line of the file
	while (!read.eof()){
		getline(read,line);
		inputs.push_back(line);
	}
	read.close();
	
	//Vector of destination ===================================================================================================================
	for (int i = 0; i < inputs.size(); i++){
		int indexOfDigit = -1;
		for (int j = 0; j < inputs[i].length(); j++){
			if (isdigit(inputs[i].at(j))){
				indexOfDigit = j;
				destination.push_back(inputs[i].substr(0,j-1));
				j = inputs[i].length();
			}
		}
		inputs[i] = inputs[i].substr(indexOfDigit,inputs[i].length());
	}
	//Vector of time for flight ==============================================================================================================
	for (int i = 0; i < inputs.size(); i++){
		int space = -1;
		for (int j = 0; j < inputs[i].length(); j++){
			if (inputs[i].at(j) == ' '){
				space = j;
				time.push_back(inputs[i].substr(0,j-1));
				j = inputs[i].length();
			}
		}
		inputs[i] = inputs[i].substr(space+1,inputs[i].length());
	}
	//Vector of flight number ================================================================================================================
	for (int i = 0; i < inputs.size(); i++){
		int tab = -1;
		for (int j = 0; j < inputs[i].length(); j++){
			if (inputs[i].at(j) == ' '){
				tab = j;
				flight.push_back(inputs[i].substr(0,j-1));
				j = inputs[i].length();
			}
		}
	}
	//Vector of gate number ===================================================================================================================
	for (int i = 0; i < 10; i++){
		gate.push_back(inputs[i].substr(inputs[i].size()-3,inputs[i].size()));
	}
	
	//Push informations from each created vector into flight vectors ==========================================================================
	vector <Flight> vi;
	vector <Flight> v;
	for (int i = 0; i < 10; i++){
		Flight temp( flight[i],destination[i],time[i],gate[i], i);
		vi.push_back(temp);
		v.push_back(temp);
	}
	
//FLTK =============================================================================================================================================================	
	SelectionSort s;
	BubbleSort z;

	try{
		Simple_window console(Point(100,200),1000,800,"Sort Window");		//creates a window
	//Display unsorted data graphically	===============================================================================================================================
		vector <Text*> flight_name_unsort;
		for (int j = 0; j < 2; j++){
			for (int i = 0; i < vi.size(); i++){
				string destination = vi[i].get_destination();
				Text* temp = new Text(Point(5, 105+(i*30)+(j*370)), destination);
				flight_name_unsort.push_back(temp);
			}
		}
		cout << left << setw(12) << "Flight Number" << right << setw(15) << "Destination" << right << setw(20) << "Departure Time" << right << setw(20) << "Gate Number" << '\n' << endl; 
		for (int i = 0; i < vi.size(); i++){
			cout << left << setw(10) << vi[i].get_flight_number() << right << setw(17) << vi[i].get_destination() << right << setw(15) << vi[i].get_departure_time() << right << setw(22) << vi[i].get_gate_number() << '\n' << endl; 
		}
		
		for (int i = 0; i < 20; i++){
			console.attach(*(flight_name_unsort[i]));
		}
		
//Selection Sort =====================================================================================================================================================
		vector <Circle*> circles;
		vector <Line*> lines;
		vector <Text*> iterations;
		Text* titles = new Text (Point(350,50), "Selection Sort");
		titles->set_font_size(30);
		s.sort(vi); //SORTING CALLED
		//Graphic iterations ==========================================================================================================================================
		for (int i = 0; i < 11; i++){
			string it;
			stringstream convert;
			convert << i;
			it = convert.str();
			Text* temp = new Text(Point(117+(70*i), 80), it);
			temp->set_color(Color::blue);
			iterations.push_back(temp);
		}
		//Graphic positions of data ====================================================================================================================================
		for (int j = 0; j < 11; j++){
		    int incrc = (120+(j*70));
			for (int i = 0; i < 10; i++){
				int incr = (100+(i*30));
				Circle* temp = new Circle(Point(incrc, incr),5);
				temp->set_fill_color(Color::red);
				circles.push_back(temp);
			}
		}
		//Lines updating positions after each iteration ================================================================================================================
		for (int c = 0; c < 9; c++){
			for (int count = 0; count < 10; count++){
				for (int r = 0; r < 10; r++){
					if (s.tag_update[count][c] == s.tag_update[r][c+1]){
						Line* temp = new Line (Point(120+(c*70),100+(count*30)), Point(120+((c+1)*70),100+(r*30)));
						temp->set_color(Color::red);
						lines.push_back(temp);
					}
				}
			}
		}
		for (int i = 0; i < 10; i++){
			Line* temp = new Line (Point(120+(9*70),100+(i*30)), Point(120+((10)*70),100+(i*30)));
			temp->set_color(Color::red);
			lines.push_back(temp);
		}
		//Display sorted data graphically ===============================================================================================================================
		vector <Text*> flight_name_ssorted;

		for (int i = 0; i < vi.size(); i++){
			string destination = vi[i].get_destination();
			Text* temp = new Text(Point(880, 105+(i*30)), destination);
			flight_name_ssorted.push_back(temp);
		}
		cout << "Selection sort =================================================================" << endl;
		cout << left << setw(12) << "Flight Number" << right << setw(15) << "Destination" << right << setw(20) << "Departure Time" << right << setw(20) << "Gate Number" << '\n' << endl; 
		for (int i = 0; i < vi.size(); i++){
			cout << left << setw(10) << vi[i].get_flight_number() << right << setw(17) << vi[i].get_destination() << right << setw(15) << vi[i].get_departure_time() << right << setw(22) << vi[i].get_gate_number() << '\n' << endl; 
		}
		//Attach to graphic display =====================================================================================================================================
		for (int i = 0; i < 10; i++){
			console.attach(*(flight_name_ssorted[i]));
		}
		for (int i = 0; i < 110; i++){
			console.attach(*(circles[i]));
 		}
		for (int i = 0; i < lines.size(); i++){
			console.attach(*(lines[i]));
 		}
		for (int i = 0; i < 11; i++){
			console.attach(*(iterations[i]));
		}
		console.attach(*titles);
		
//Bubble Sort ============================================================================================================================================================
		vector <Circle*> circleb;
		vector <Line*> lineb;
		vector <Text*> iterationb;
		Text* titleb = new Text (Point(360,420), "Bubble Sort");
		titleb->set_font_size(30);
		z.sort(v); //SORTING CALLED
		vector <int> initial {0,1,2,3,4,5,6,7,8,9};
		
		//Graphic iterations =============================================================================================================================================
		for (int i = 0; i < 11; i++){
			string it;
			stringstream convert;
			convert << i;
			it = convert.str();
			Text* temp = new Text(Point(117+(70*i), 450), it);
			temp->set_color(Color::blue);
			iterationb.push_back(temp);
		}
		//Graphic positions of data ======================================================================================================================================
		for (int j = 0; j < 11; j++){
		    int incrc = (120+(j*70));
			for (int i = 0; i < 10; i++){
				int incr = (470+(i*30));
				Circle* temp = new Circle(Point(incrc, incr),5);
				temp->set_fill_color(Color::red);
				circleb.push_back(temp);
			}
		}
		//Lines updating ==================================================================================================================================================
		for (int c = 0; c < 9; c++){
			for (int count = 0; count < 10; count++){
				for (int r = 0; r < 10; r++){
					if (z.tag_update[count][c] == z.tag_update[r][c+1]){
						Line* temp = new Line (Point(120+((c+1)*70),470+(count*30)), Point(120+((c+2)*70),470+(r*30)));
						temp->set_color(Color::red);
						lineb.push_back(temp);
					}
				}
			}
		}
		//Initial connection to first values ==============================================================================================================================
		for (int count = 0; count < 10; count++){
			for (int j = 0; j < 10; j++){
				if (initial[count] == z.tag_update[j][0]){
					Line* temp = new Line (Point(120+(0*70),470+(count*30)), Point(120+((1)*70),470+(j*30)));
					temp->set_color(Color::red);
					lineb.push_back(temp);
				}
			}
		}
		//Display sorted data graphically =================================================================================================================================
		vector <Text*> flight_name_bsorted;
		for (int i = 0; i < v.size(); i++){
			string destination = v[i].get_destination();
			Text* temp = new Text(Point(880, 105+(i*30)+370), destination);
			flight_name_bsorted.push_back(temp);
		}
		cout << "Bubble sort ===================================================================" << endl;
		cout << left << setw(12) << "Flight Number" << right << setw(15) << "Destination" << right << setw(20) << "Departure Time" << right << setw(20) << "Gate Number" << '\n' << endl; 
		for (int i = 0; i < v.size(); i++){
			cout << left << setw(10) << v[i].get_flight_number() << right << setw(17) << v[i].get_destination() << right << setw(15) << v[i].get_departure_time() << right << setw(22) << v[i].get_gate_number() << '\n' << endl; 
		}
		//Attach to graphic display ========================================================================================================================================
		for (int i = 0; i < 10; i++){
			console.attach(*(flight_name_bsorted[i]));
		}
		for (int i = 0; i < 110; i++){
			console.attach(*(circleb[i]));
 		}
		for (int i = 0; i < 11; i++){
			console.attach(*(iterationb[i]));
		}
		for (int i = 0; i < lineb.size(); i++){
			console.attach(*(lineb[i]));
 		}
		console.attach(*titleb);
			
		console.wait_for_button();
		//Print out number of comparisons and swaps ==========================================================================================================================
		
		cout << "                 NUMBER OF COMPARISION    Number of Swaps" << endl;
		cout << "Selection sort:         " << s.num_comp << "                       " << s.num_swaps << endl;
		cout << "Bubble Sort:            " << z.num_comp << "                       " << z.num_swaps << endl;
		return 0;
	}
	
	catch(exception& e) {
		cerr << "exception: " << e.what() << '\n';
			return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
			return 2;
	}
}
