//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Asignment 2 - A VIDEO STORE	
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

//////////////////////////--Built-in libraries--/////////////////////////////
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

//////////////////////////--Define Macro--/////////////////////////////

using namespace std;

//////////////////////////--rentalItemCls--/////////////////////////////
typedef struct rentalItemID { 
    int code;
	int year;
} itemID; 

typedef enum recordMediaType { 
	Action,
	Horror,
	Drama,
	Comedy,
} mediaType; 

class rentalItemCls {
private:
	itemID id;		// 
	string title; 	// Captures the whole title of the item
	mediaType type;	// Record, DVD, or Game
	// int Loan type: either 2-day loan or 1-week loan
	// int Number of copies held in stock (e.g. 1, 2, 3 or more)
	// int Rental fee (in USD)
	// int Rental status: either borrowed or available.

public:

};

//Function prototypes
bool CheckExit(string);
bool ModifyItem();
bool ModifyCtmr();
bool PromoteCtmr();
bool RentItem();
bool ReturnItem();
bool DispAllItem();
bool DispOosItem();
bool DispAllCtmr();
bool DispGroupCtmr();
bool SearchItemCtmr();

//Main Program
int main()
{
	while (1) {
		string optSel_str; // Option Select Raw String

		cout << "\n___________________________________________________________";
		cout << "\nWelcome to HaloSST’s video store" << endl;
		cout << "\nEnter an option below." << endl;
		cout << "1. Add a new item, update or delete an existing item" << endl;
		cout << "2. Add new customer or update an existing customer" << endl;
		cout << "3. Promote an existing customer" << endl;
		cout << "4. Rent an item" << endl;
		cout << "5. Return an item" << endl;
		cout << "6. Display all items" << endl;
		cout << "7. Display out-of-stock items" << endl;
		cout << "8. Display all customers" << endl;
		cout << "9. Display group of customers" << endl;
		cout << "10. Search items or customers" << endl;
		cout << "Exit." << endl;

		getline(cin,optSel_str);
		if (CheckExit(optSel_val)) return 0;

		// TODO expand input valuator here
		switch ( atoi(optSel_str.c_str()) )
		{
			case 1: 
				ModifyItem();
				break;

			case 2: 
				ModifyCtmr();
				break;

			case 3: 
				PromoteCtmr();
				break;
			case 4: 
				RentItem();
				break;

			case 5: 
				ReturnItem();
				break;

			case 6: 
				DispAllItem();
				break;

			case 7: 
				DispOosItem();
				break;

			case 8: 
				DispAllCtmr();
				break;

			case 9: 
				DispGroupCtmr();
				break;

			case 10: 
				SearchItemCtmr();
				break;

			default:
				break;
		}

	}
}

/*	Function name: CheckExit.
	Usage: Check if the input string is Exit or not. If "Exit" is pressed then exit the program and print team information.
	Input: pointer to input raw string.
	Output: Boolean flag to acknowledge "Exit" have been pressed or not.
*/
bool CheckExit(string optSel_str) {
	if ( (optSel_str.compare("Exit") == 0) || optSel_str.compare("exit") == 0 ) { // Consider both Capital (Exit) and non-capital (exit) of the first character to compare with the input string.
		cout << "ASSIGNMENT 2 - GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
	return 0;
}

bool ModifyItem(){
	cout << "ModifyItem Activated" << endl;
};
bool ModifyCtmr(){
	cout << "ModifyCtmr Activated" << endl;
};
bool PromoteCtmr(){
	cout << "PromoteCtmr Activated" << endl;
};
bool RentItem(){
	cout << "RentItem Activated" << endl;
};
bool ReturnItem(){
	cout << "ReturnItem Activated" << endl;
};
bool DispAllItem(){
	cout << "DispAllItem Activated" << endl;
};
bool DispOosItem(){
	cout << "DispOosItem Activated" << endl;
};
bool DispAllCtmr(){
	cout << "DispAllCtmr Activated" << endl;
};
bool DispGroupCtmr(){
	cout << "DispGroupCtmr Activated" << endl;
};
bool SearchItemCtmr(){
	cout << "SearchItemCtmr Activated" << endl;
};