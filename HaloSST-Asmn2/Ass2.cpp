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
ctmTypeEnum ctmTypeUtil(string);
rentalTypeEnum rentalTypeUtil(string);
genreTypeEnum genreTypeUtil(string);
bool rentalPeriodUtil(string);
char* str2arr(string);

int main()
{
	ItemList* ItemLst = new ItemList();
	// ----------Testing-----------
	/*ItemLst->appendHead("I000-2000", "111111111111111", rentalTypeEnum::GAME, true, 3, 3.99, true);
	ItemLst->appendTail("I001-2001", "Medal of Honour", rentalTypeEnum::DVD, true, 3, 6.99, false, genreTypeEnum::NONE);
	ItemLst->appendTail("I002-2002", "Captain America", rentalTypeEnum::GAME, true, 2, 3.99, true);
	ItemLst->appendTail("I003-2003", "Pes 2020: New Era", rentalTypeEnum::RECORD, true, 3, 4.99, true, genreTypeEnum::ACTION);
	ItemLst->removeHead();
	ItemLst->removeTail();
	ItemLst->printList();
	ItemLst->searchItem("I001-2001");
	ItemLst->searchItem("I008-2001");*/

	CtmList* CustomerLst = new CtmList();
	initBaseDb(ItemLst, CustomerLst);
	CustomerLst->printList();

	cout << "TESTTTTTTTTTT:   " << CustomerLst->getCtmHead()->getName() << endl;
	cout << "TESTTTTTTTTTT1:   " << CustomerLst->getCtmHead()->getAddr() << endl;
	cout << "TESTTTTTTTTTT2:   " << CustomerLst->getCtmHead()->getID() << endl;

	delete ItemLst;
	delete CustomerLst;

	/*ListOfItem->appendHead("C001", "Minh Dinh", "18 Irwin Street", "0421473243", ctmTypeEnum::VIP);
	ListOfItem->addCtmItemList("I005-2015");
	ListOfItem->addCtmItemList("I002-1988");
	ListOfItem->addCtmItemList("I001-2001");
	ListOfItem->appendHead("C002", "Hong Wang", "20 Irwin Street", "0424173255", ctmTypeEnum::GUEST);
	ListOfItem->appendHead("C003", "Linh Nguyen", "12 Brunswick Street","0424173255", ctmTypeEnum::VIP);
	ListOfItem->appendHead("C004", "Antony Zinc","114 Fraser Avenue","0424512345", ctmTypeEnum::VIP);
	ListOfItem->appendHead("C005", "John Cain","45 Sydney Road","0424325123", ctmTypeEnum::VIP);
	cout << "?????????????????????????????????" << endl;
	ListOfItem->printCtm(ListOfItem->searchCtm("Linklqweqh Nguyen", "C0qqwe02"));
	cout << ListOfItem->searchCtm("Linh Nguyen", "C002")->getPhone() <<endl;
	ListOfItem->printList();
	delete ListOfItem;*/

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
					ctmPtr->addCtmItemList(textLine);
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
	strcpy_s(cTypeStr, str.length() + 1, str.c_str());
	return cTypeStr;
}