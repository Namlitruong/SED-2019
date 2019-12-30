//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Asignment 2 - A VIDEO STORE	
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

#include "pch.h"
#include "IC.h"
#include "LinkedList.h"
#include "DB.h"

using namespace std;

// Global DB Filename
string ctmDbFileName, itemDbFileName;

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ctmDbFileName = argv[1];
		itemDbFileName = argv[2];

		if (ctmDbFileName.substr(ctmDbFileName.find_last_of(".") + 1) != "txt"
			|| itemDbFileName.substr(itemDbFileName.find_last_of(".") + 1) != "txt"
			) {
			cout << "[Argument1] customerDatabase.txt [Argument2] itemDatabase.txt" << endl;
			cout << "Unsupported Database Format (.txt Only) ! Please try again !" << endl;

			return -1;
		}

	}
	else {
		ctmDbFileName = "customers.txt";
		itemDbFileName = "items.txt";
	}



	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst, ctmDbFileName, itemDbFileName);
	while (1) {
		autoPromoteCtmr(CustomerLst);
		string optSel_str; // Option Select Raw String
		cout << "\n___________________________________________________________";
		cout << "\nWelcome to Genie�s video store" << endl;
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
		getline(cin, optSel_str);
		if (CheckExit(optSel_str)) {
			finBaseDb(ItemLst, CustomerLst, ctmDbFileName, itemDbFileName);
			delete ItemLst;
			delete CustomerLst;
			return 0;
		}
		switch (atoi(optSel_str.c_str()))
		{
		case 1:
			ModifyItem(ItemLst);
			break;
		case 2:
			ModifyCtmr(CustomerLst);
			break;
		case 3:
			PromoteCtmrByID(CustomerLst);
			break;
		case 4:
			renItem(ItemLst, CustomerLst);
			break;
		case 5:
			returnItem(ItemLst, CustomerLst);
			break;
		case 6:
			printItemList(ItemLst);
			break;
		case 7:
			DisplayOutofStock(ItemLst);
			break;
		case 8:
			printCtmList(CustomerLst);
			break;
		case 9:
			DispGroupCtmr(CustomerLst);
			break;
		case 10:
			SearchItemCtmr(CustomerLst, ItemLst);
			break;
		default:
			break;
		}
	}
	finBaseDb(ItemLst, CustomerLst, ctmDbFileName, itemDbFileName);
	delete ItemLst;
	delete CustomerLst;
	return 0;
}

