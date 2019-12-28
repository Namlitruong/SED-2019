#include "pch.h"
#include "IC.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define ctmIdentifier 'C'
#define itemIdentifier 'I'
#define commentTag '#'

#define ctmDbInLength 6
#define itemDbInLength 7

int initBaseDb(ItemList*, CtmList*);
int finBaseDb(ItemList*, CtmList*);
ctmTypeEnum ctmTypeUtil(string);
rentalTypeEnum rentalTypeUtil(string);
genreTypeEnum genreTypeUtil(string);
bool rentalPeriodUtil(string);
char* str2arr(string);
string arr2str(string);
string ctmTypeStr(ctmTypeEnum);
bool CheckExit(string optSel_str);

int main()
{

	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);

	CustomerLst->printList();
	CustomerLst->searchCtmID("C001");
	CustomerLst->removeHead();

	CustomerLst->printList();
	CustomerLst->searchCtmName("Minh Dinh");
	CustomerLst->removeTail();
	CustomerLst->printList();
	CustomerLst->searchCtmID("C003");
	
	CustomerLst->appendTail("C0012", "Nam Truong", "45 Sydney Road", "0819847731", ctmTypeEnum::VIP);
	CustomerLst->appendTail("C0013", "Tin Nguyen", "45 Sydney Road", "0819847713", ctmTypeEnum::VIP);
	CustomerLst->printList();


	cout << "Test remove node" << endl;
	int a = CustomerLst->removeNodeByID("C0013");
	CustomerLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Test remove node1" << endl;
	a = CustomerLst->removeNodeByID("C0012");
	CustomerLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Test remove node2" << endl;
	a = CustomerLst->removeNodeByID("C0015");
	CustomerLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Size of the list: " << CustomerLst->size() << endl;
	CustomerLst->deleteList();
	cout << "Size of the list: " << CustomerLst->size() << endl;
	CustomerLst->printList();

	/*cout << "####################ITEM TEST ######################" << endl;

	ItemLst->appendHead("I000-2000", "111111111111111", rentalTypeEnum::GAME, true, 3, 3.99, true);
	ItemLst->appendTail("I001-2001", "Medal of Honour", rentalTypeEnum::DVD, true, 3, 6.99, false, genreTypeEnum::NONE);
	ItemLst->appendTail("I002-2002", "Captain America", rentalTypeEnum::GAME, true, 2, 3.99, true);
	ItemLst->appendTail("I003-2003", "Pes 2020: New Era", rentalTypeEnum::RECORD, true, 3, 4.99, true, genreTypeEnum::ACTION);
	ItemLst->printList();
	ItemLst->removeHead();
	ItemLst->removeTail();
	ItemLst->printList();

	ItemLst->searchItemByID("I001-2001");
	ItemLst->searchItemByTitle("Captain America");

	cout << "Test remove node" << endl;
	a = ItemLst->removeItemByID("I002-2002");
	ItemLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Test remove node1" << endl;
	a = ItemLst->removeItemByID("I001-2001");
	ItemLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Test remove node2" << endl;
	a = ItemLst->removeItemByID("C0015");
	ItemLst->printList();
	cout << "Node remove successfully: " << a << endl;

	cout << "Size of the list: " << ItemLst->size() << endl;
	ItemLst->deleteList();
	cout << "Size of the list: " << ItemLst->size() << endl;
	ItemLst->printList();*/

	//finBaseDb(ItemLst, CustomerLst);

	delete ItemLst;
	delete CustomerLst;
	return 0;
}

/*int main()
{
	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);
	while (1) {
		string optSel_str; // Option Select Raw String

		cout << "\n___________________________________________________________";
		cout << "\nWelcome to Genie’s video store" << endl;
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
		if (CheckExit(optSel_str)) return 0;

		// TODO expand input evaluator here
		switch (atoi(optSel_str.c_str()))
		{
		case 1:
			//ModifyItem();
			break;

		case 2:
			//ModifyCtmr();
			break;

		case 3:
			//PromoteCtmr();
			break;
		case 4:
			//RentItem();
			break;

		case 5:
			//ReturnItem();
			break;

		case 6:
			ItemLst->printList();
			break;

		case 7:
			//DispOosItem();
			break;

		case 8:
			CustomerLst->printList();
			break;

		case 9:
			//DispGroupCtmr();
			break;

		case 10:
			//SearchItemCtmr();
			break;

		default:
			// TODO non-supported operator, merge w input evaluator
			break;
		}

	}
	delete ItemLst;
	delete CustomerLst;
	return 0;
}*/

/*	Function name: CheckExit.
Usage: Check if the input string is Exit or not. If "Exit" is pressed then exit the program and print team information.
Input: pointer to input raw string.
Output: Boolean flag to acknowledge "Exit" have been pressed or not.
*/
bool CheckExit(string optSel_str) {
	if ((optSel_str.compare("Exit") == 0) || optSel_str.compare("exit") == 0) { // Consider both Capital (Exit) and non-capital (exit) of the first character to compare with the input string.
		cout << "ASSIGNMENT 2 - GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
return 0;
}


int initBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	bool isCtmProfile = false;
	long totalRental = 0;
	ifstream ctmFile("customers.txt");
	ifstream itemFile("items.txt");

	// initialize Customer DB

	if (ctmFile.is_open())
	{
		while (getline(ctmFile, textLine))
		{
			char firstChr = textLine[0];

			// Skip comments
			if (firstChr == (char)commentTag) {
				continue;
			}

			// Detect customer identifier
			if (firstChr == (char)ctmIdentifier) {
				isCtmProfile = true;

				//TODO append to CtmList
				string inputVal[ctmDbInLength];
				const char delimeter = ',';
				int curCtm = 0, idxCtm = 0;

				// String Tokenizer into String Array
				while ((curCtm = textLine.find(delimeter)) != std::string::npos)
				{
					inputVal[idxCtm++] = textLine.substr(0, curCtm);
					textLine.erase(0, curCtm + 1); // Advance next term, +1 for delimeter
					//NOTE curCtm.length() would be redundant, unnecessary
				}
				inputVal[idxCtm] = textLine; // Last term

				// Update Customer Pointer
				ctmPtr->appendHead(inputVal[0], inputVal[1], inputVal[2], inputVal[3], ctmTypeUtil(inputVal[5]));
				//NOTE confirm no. of rentals
				totalRental = atoi(inputVal[4].c_str());
				continue;
			}

			// TODO check error based on totalRental
			if (firstChr == (char)itemIdentifier) {
				if (totalRental >= 0)
				{
					ctmPtr->addCtmItemList(ctmPtr->getCtmHead(), textLine);
					totalRental--;
				}
			}
		}
		ctmFile.close();
	}


	// Now initialize Items DB
	if (itemFile.is_open())
	{
		while (getline(itemFile, textLine))
		{
			char firstChr = textLine[0];

			// Skip comments
			if (firstChr == (char)commentTag) {
				continue;
			}

			// Update Item Database
			if (firstChr == (char)itemIdentifier) {
				string inputVal[itemDbInLength];
				const char delimeter = ',';
				int curItem = 0, idxItem = 0;

				// String Tokenizer into String Array
				while ((curItem = textLine.find(delimeter)) != std::string::npos)
				{
					inputVal[idxItem++] = textLine.substr(0, curItem);
					textLine.erase(0, curItem + 1); // Advance next term, +1 for delimeter
					//NOTE curItem.length() would be redundant, unnecessary
				}
				inputVal[idxItem] = textLine; // Last term

				// Update Customer Pointer
				// (				string id, 
				//				 string title, 
				//  rentalTypeEnum rentalType, 
				//			  bool loanStatus, 
				//				int numOfCopy, 
				//			   double rentFee, 
				//			 bool isAvailable, //TODO redundant, not provided in items.txt
				//	 genreTypeEnum genreType); // DVD || Record Only

				if (inputVal[2] == "DVD" || inputVal[2] == "Record") {
					itemPtr->appendHead(inputVal[0],
						inputVal[1],
						rentalTypeUtil(inputVal[2]),
						rentalPeriodUtil(inputVal[3]),
						atoi(inputVal[4].c_str()),
						std::stod(inputVal[5]),
						true,
						genreTypeUtil(inputVal[6].c_str()));
				}
				else if (inputVal[2] == "Game") {
					itemPtr->appendHead(inputVal[0],
						inputVal[1],
						rentalTypeUtil(inputVal[2]),
						rentalPeriodUtil(inputVal[3]),
						atoi(inputVal[4].c_str()),
						std::stod(inputVal[5]),
						true);
				}
				else {
					// Redundant
					// Extra error check
				}
				continue;
			}
		}
		itemFile.close();
	}
	// TODO boolean status if necessary
	return -1;
}

/*int finBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	ofstream ctmFile("customers.txt");
	ofstream itemFile("items.txt", std::ios_base::app);

	// Finalize Customer DB
	if (ctmFile.is_open())
	{
		// IN-DEVELOP
		// Iteratively output to buffer
		customer* current = ctmPtr->getCtmHead();
		ctmFile << "#Final Customer Database updated";
		do {
			// TODO arr2str Util function, getAllArr function from Ctm/Item cls
			textLine = "\r\n"
				+ current->getID() + ','
				+ current->getName() + ','
				+ current->getAddr() + ','
				+ current->getPhone() + ','
				+ std::to_string(current->numOfRental()) + ','
				+ ctmTypeStr(current->getCtmType());

				//for (int i = 0; i < current->numOfRental(); i++) {
				//	textLine = + *(current->getListOfRental + i) + "\n";
				//}
			;
			cout << textLine;

			//TODO add rental List of each Customer

			// ctmFile << textLine;
		} while ((current = current->getNext()) != NULL);
		ctmFile.close();
	}

	// Now Finalize Items DB


	// TODO boolean status if necessary
	return -1;
}*/

ctmTypeEnum ctmTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "VIP") == 0)
	{
		return ctmTypeEnum::VIP;
	}
	else if ((strcmp(str2arr(str.c_str()), "Regular")) == 0)
	{
		return ctmTypeEnum::REGULAR;
	}
	else if ((strcmp(str2arr(str.c_str()), "Guest")) == 0)
	{
		return ctmTypeEnum::GUEST;
	}
}

string ctmTypeStr(ctmTypeEnum ctmEnum) {

	switch (ctmEnum)
	{
	case GUEST:
		return "Guest";
	case REGULAR:
		return "Regular";
	case VIP:
		return "VIP";
	default:
		return "";
	}
}

rentalTypeEnum rentalTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "Game") == 0)
	{
		return rentalTypeEnum::GAME;
	}
	else if ((strcmp(str2arr(str.c_str()), "DVD")) == 0)
	{
		return rentalTypeEnum::DVD;
	}
	else if ((strcmp(str2arr(str.c_str()), "Record")) == 0)
	{
		return rentalTypeEnum::RECORD;
	}
}


genreTypeEnum genreTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "Action") == 0)
	{
		return genreTypeEnum::ACTION;
	}
	else if ((strcmp(str2arr(str.c_str()), "Comedy")) == 0)
	{
		return genreTypeEnum::COMEDY;
	}
	else if ((strcmp(str2arr(str.c_str()), "Drama")) == 0)
	{
		return genreTypeEnum::DRAMA;
	}
	else if ((strcmp(str2arr(str.c_str()), "Horror")) == 0)
	{
		return genreTypeEnum::HORROR;
	}
}

bool rentalPeriodUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "1-week") == 0)
	{
		return true;
	}
	else if ((strcmp(str2arr(str.c_str()), "2-day")) == 0)
	{
		return false;
	}
}

char* str2arr(string str) {
	char* cTypeStr = new char[str.length() + 1];
	//FIXME swap strcpy_s for Windows supported "safe" String libary
	 strcpy_s(cTypeStr, str.length() + 1, str.c_str());
//	strcpy(cTypeStr, str.c_str());
	return cTypeStr;
}

//string arr2str(string arr[]) {
	// bool firstTerm = true;
	// string temp;
	// // IN-DEVELOP
	// for (string &ele : arr)
	// {
	// 	if (!firstTerm) { temp.append(","); }
	// 	firstTerm = false;
	// 	temp.append(ele); // Append Element
	// }
//}