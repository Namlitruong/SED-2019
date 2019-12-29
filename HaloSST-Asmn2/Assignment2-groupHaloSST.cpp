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

int main()
{
	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);
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
			finBaseDb(ItemLst, CustomerLst);
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
			ItemLst->printList();
			break;
		case 7:
			DisplayOutofStock(ItemLst);
			break;
		case 8:
			CustomerLst->printList();
			break;
		case 9:
			DispGroupCtmr(CustomerLst);
			break;
		case 10://Hoang
			//SearchItemCtmr();
			break;
		default:
			// TODO non-supported operator, merge w input evaluator
			break;
		}
	}
	finBaseDb(ItemLst, CustomerLst);
	delete ItemLst;
	delete CustomerLst;
	return 0;
}

