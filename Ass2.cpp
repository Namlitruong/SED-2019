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
string rentalTypeStr(rentalTypeEnum);
string rentalPeriodStr(bool);
string double2str(double);
string genreTypeStr(item*);

/*int main()
{

	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);

	/*CustomerLst->printList();
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
	CustomerLst->printList();

	cout << "####################ITEM TEST ######################" << endl;
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
	ItemLst->printList();
	finBaseDb(ItemLst, CustomerLst);

	delete ItemLst;
	delete CustomerLst;
	return 0;
}*/

int renItem (ItemList*, CtmList*);
int returnItem(ItemList*, CtmList*);
int PromoteCtmr(CtmList*);
void DispGroupCtmr(CtmList*);
int main()
{
	ItemList* ItemLst = new ItemList();
	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);
	while (1) {
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
		// TODO expand input evaluator here
		switch (atoi(optSel_str.c_str()))
		{
		case 1: //Hoang
			//ModifyItem();
			break;
		case 2://Hoang
			//ModifyCtmr();
			break;
		case 3:
			PromoteCtmr(CustomerLst);
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
		case 7://Hoang
			//DispOosItem();
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
		//delete rentIt;
		//delete rentCtm;
	}
	finBaseDb(ItemLst, CustomerLst);
	delete ItemLst;
	delete CustomerLst;
	return 0;
}

void DispGroupCtmr(CtmList* CustomerLst) {
	string select;
	cout << "\nEnter an option below." << endl;
	cout << "1. List of VIP customers" << endl;
	cout << "2. List of Regular customers" << endl;
	cout << "3. List of Guest customers" << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		cout << "List of VIP customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::VIP);
		break;
	case 2: 
		cout << "List of Regular customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::REGULAR);
		break;
	default:
		cout << "List of Guest customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::GUEST);
		break;
	}
}

int renItem(ItemList* ItemLst, CtmList* CustomerLst) {
	string tempItem, tempCtm;
	item * rentIt = NULL;
	customer * rentCtm = NULL;
	cout << "////////////////////---RENTING PROCESS START---////////////////////////" << endl;
	cout << "Enter Item ID: ";
	getline(cin, tempItem);
	rentIt = ItemLst->searchItemByID(tempItem);
	if (rentIt == NULL) return -1;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	if (rentCtm->getCtmType() == GUEST && rentIt->getLoanStatus() == false) {
		cout << "GUEST customer can not borrow 2-day item" << endl;
		return -1;
	}
	if (rentCtm->getCtmType() == GUEST && rentCtm->numOfRental() == 2) {
		cout << "GUEST customer just can rent maximum 2 items" << endl;
		return -1;
	}
	if (rentIt->getNumOfCopy() == 0) {
		cout << "The Item: " << rentIt->getTitle() << " is not available" << endl;
		return -1;
	}
	else {
		rentIt->setNumOfCopy(-1);
		CustomerLst->addCtmItemList(rentCtm, rentIt->getID());
	}
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	ItemLst->searchItemByID(tempItem);
	CustomerLst->searchCtmID(tempCtm);
	cout << "////////////////////---RENTING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

int returnItem(ItemList* ItemLst, CtmList* CustomerLst) {
	string tempItem, tempCtm;
	item * rentIt = NULL;
	customer * rentCtm = NULL;
	cout << "////////////////////---RETURNING PROCESS START---////////////////////////" << endl;
	cout << "Enter Item ID: ";
	getline(cin, tempItem);
	rentIt = ItemLst->searchItemByID(tempItem);
	if (rentIt == NULL) return -1;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	rentIt->setNumOfCopy(1);
	if (rentCtm->removeItem(rentIt->getID()) == 0) return -1;
	else {
		rentCtm->successReturn();
		cout << "Customer "<< rentCtm->getName()<< " return successfully: " << rentCtm->getSuccessReturn() << " items"<< endl;
	}
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	ItemLst->searchItemByID(tempItem);
	CustomerLst->searchCtmID(tempCtm);
	cout << "////////////////////---RETURNING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

int PromoteCtmr(CtmList* CustomerLst) {
	string tempCtm;
	string promote;
	customer * rentCtm = NULL;
	cout << "////////////////////---PROMOTING PROCESS START---////////////////////////" << endl;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	switch (rentCtm->getCtmType()) {
	case REGULAR:	promote = "VIP"; break;
	case GUEST:		promote = "Regular"; break;
	default: {
		cout << "Cannot promote VIP" << endl;
		promote = "VIP";
		return -1;
		break;
	}
	}
	CustomerLst->appendHead(rentCtm->getID(),
							rentCtm->getName(),
							rentCtm->getAddr(),
							rentCtm->getPhone(),
							ctmTypeUtil(promote));

	for (int i = 0; i < rentCtm->numOfRental(); i++) {
		CustomerLst->addCtmItemList(CustomerLst->getCtmHead(), *(rentCtm->getListOfRental() + i));
	}
	tempCtm = rentCtm->getID();
	CustomerLst->removeNode(rentCtm);
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	CustomerLst->searchCtmID(tempCtm); 
	cout << "////////////////////---PROMOTING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

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

int finBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	ofstream ctmFile("customers.txt");
	ofstream itemFile("items.txt");


	// Finalize Customer DB
	if (ctmFile.is_open())
	{
		// IN-DEVELOP
		// Iteratively output to buffer
		customer* currCtm = ctmPtr->getCtmHead();
		ctmFile << "#Final Customer Database updated\n";
		do {
			// TODO arr2str Util function, getAllArr function from Ctm/Item cls
			textLine = currCtm->getID() + ','
				+ currCtm->getName() + ','
				+ currCtm->getAddr() + ','
				+ currCtm->getPhone() + ','
				+ std::to_string(currCtm->numOfRental()) + ','
				+ ctmTypeStr(currCtm->getCtmType());

			//TODO add rental List of each Customer
			textLine += "\n";

			for (int i = 0; i < currCtm->numOfRental(); i++) {
				textLine += *(currCtm->getListOfRental() + i) + "\n";
			};
			if (textLine[textLine.length() - 1] != '\n') {
				textLine += "\n";
			}
			 
			ctmFile << textLine;
		} while ((currCtm = currCtm->getNext()) != NULL);
		ctmFile.close();
	}

	// Now Finalize Items DB
	if (itemFile.is_open())
	{
		// IN-DEVELOP
		// Iteratively output to buffer
		item* currItem = itemPtr->getItemHead();
		itemFile << "#Final Item Database updated\n";
		do {
			// TODO arr2str Util function, getAllArr function from Ctm/Item cls
			textLine = currItem->getID() + ','
				+ currItem->getTitle() + ','
				+ rentalTypeStr(currItem->getRentalType()) + ','
				+ rentalPeriodStr(currItem->getLoanStatus()) + ','
				+ std::to_string(currItem->getNumOfCopy()) + ','
				+ double2str(currItem->getRentFee()) 
				+ genreTypeStr(currItem);
			// FIXME getGenreType() virtual function returns NONE except 1st iteration

			if (textLine[textLine.length() - 1] != '\n') {
				textLine += "\n";
			}
			itemFile << textLine;
		} while ((currItem = currItem->getNext()) != NULL);
		itemFile.close();
	}

	// TODO boolean status if necessary
	return -1;
}

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

string rentalTypeStr(rentalTypeEnum rentalEnum) {
	switch (rentalEnum)
	{
	case DVD:
		return "DVD";
	case RECORD:
		return "Record";
	case GAME:
		return "Game";
	default:
		return "";
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

string genreTypeStr(item* its) { 
	switch (its->getRentalType()) {
	case RECORD: {
		switch ((static_cast<record*>(its))->getGenreType()) {
		case ACTION:	return ",Action"; break;
		case HORROR:	return ",Horror"; break;
		case DRAMA:		return ",Drama"; break;
		case COMEDY:	return ",Comedy"; break;
		default: return ""; break;
		}
		break; }
	case DVD: {
		switch ((static_cast<dvd*>(its))->getGenreType()) {
		case ACTION:	return ",Action"; break;
		case HORROR:	return ",Horror"; break;
		case DRAMA:		return ",Drama"; break;
		case COMEDY:	return ",Comedy"; break;
		default: return ""; break;
		}
		break; }
	default: {
		return"";
		break; }
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

string rentalPeriodStr(bool bl) {
	if (bl)
	{
		return "1-week";
	}
	else {
		return "2-day";
	}
}

char* str2arr(string str) {
	char* cTypeStr = new char[str.length() + 1];
	//FIXME swap strcpy_s for Windows supported "safe" String libary
	strcpy_s(cTypeStr, str.length() + 1, str.c_str());
	//strcpy(cTypeStr, str.c_str());
	return cTypeStr;
}

string double2str(double db) {
	char buffer[100];
	sprintf_s(buffer, "%.2f", db);
	std::string str = buffer;
	return str;
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