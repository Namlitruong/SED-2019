// Ass2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

#define dbInputLength 5




class parent {
protected:
	int a;
	int b;
	int c;
	parent* next;
public:
	parent() { a = 1; b = 2; c = 3; }
	~parent() {}
	parent* getNext() { return next; }
	void setNext(parent *next) { this->next = next; }
	virtual void setA(int A) = 0;
	virtual int getA() = 0;
};

class child : public parent {
protected:
	int A;
public:
	child() { a = 1; b = 2; c = 3; A = 4; }
	child(int a, int b, int c, int A) { this->a = a; this->b = b; this->c = c; this->A = A; }
	~child() {}
	void setA(int A) { this->A = A; }
	int getA() { return this->A; }
};

class child1 : public parent {
protected:
	int B;
public:
	child1() { a = 1; b = 2; c = 3; B = 10; }
	~child1() {}
	void setA(int A) {}
	int getA() { return 0; }
};

class ItemListTest {
	parent *head;
public:
	ItemListTest() { head = NULL, cout << "Item List is created" << endl; }
	~ItemListTest() { cout << "Item List is destroyed" << endl; }
	void appendChild(int a, int b, int c, int AB) {
		parent *current = head;
		parent *newChild = new child(a, b, c, AB);
		if (current == NULL) {
			head = newChild;
		}
		else {
			newChild->setNext(current);
			head = newChild;
		}
	}

	void appendChild1() {
		parent *current = head;
		parent *newChild = new child();
		if (current == NULL) {
			head = newChild;
		}
		else {
			newChild->setNext(current);
			head = newChild;
		}
	}

	void printList() {
		parent *current = head;
		if (current == NULL)
			cout << "No items are in the line" << endl;
		else
		{
			while (current != NULL)
			{
				cout << "/////////////////////////////////////////////////" << endl;
				cout << "TEST:   " << (dynamic_cast<child*>(current))->getA() << endl;
				cout << "/////////////////////////////////////////////////" << endl;
				current = current->getNext();
			}
		}
	}
};

int initBaseDb(ItemList*, CtmList*);
ctmTypeEnum ctmTypeUtil(string);
char* str2arr(string);

int main()
{
	ItemList *ItemLst = new ItemList();
	CtmList *CustomerLst = new CtmList();

	initBaseDb(ItemLst, CustomerLst);

	ItemLst->appendHead("I001-2001", "Medal of Honour", rentalTypeEnum::GAME, true, 3, 3.99, true);
	ItemLst->appendHead("I005-2015", "Halo", rentalTypeEnum::GAME, true, 2, 3.99, true);
	ItemLst->appendHead("I004-1999", "Rat Race", rentalTypeEnum::DVD, 1, 3, 1.99, true, genreTypeEnum::HORROR);
	ItemLst->appendHead("I003-1992", "Alpha Dog", rentalTypeEnum::RECORD, 1, 3, 1.99, true, genreTypeEnum::COMEDY);
	ItemLst->printList();
	delete ItemLst;

	/*ItemListTest *ListOfItem = new ItemListTest();
	ListOfItem->appendChild1();
	ListOfItem->appendChild(11, 12, 13, 14);
	ListOfItem->appendChild1();
	ListOfItem->appendChild(21, 22, 23, 24);
	ListOfItem->appendChild1();
	ListOfItem->printList();
	delete ListOfItem;*/

	
	// ListOfItem->appendHead("C001", "Minh Dinh", "18 Irwin Street", "0421473243", ctmTypeEnum::VIP);
	// ListOfItem->addCtmItemList("I005-2015");
	// ListOfItem->addCtmItemList("I002-1988");
	// ListOfItem->addCtmItemList("I001-2001");
	// ListOfItem->appendHead("C002", "Hong Wang", "20 Irwin Street", "0424173255", ctmTypeEnum::GUEST);
	// ListOfItem->appendHead("C003", "Linh Nguyen", "12 Brunswick Street","0424173255", ctmTypeEnum::VIP);
	// ListOfItem->appendHead("C004", "Antony Zinc","114 Fraser Avenue","0424512345", ctmTypeEnum::VIP);
	// ListOfItem->appendHead("C005", "John Cain","45 Sydney Road","0424325123", ctmTypeEnum::VIP);
	// cout << "?????????????????????????????????" << endl;
	// ListOfItem->printCtm(ListOfItem->searchCtm("Linklqweqh Nguyen", "C0qqwe02"));
	// //cout << ListOfItem->searchCtm("Linh Nguyen", "C002")->getPhone() <<endl;
	// ListOfItem->printList();
	// delete ListOfItem;

	return 0;
}

int initBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	bool isCtmProfile = false;
	long totalRental = 0;
	ifstream iFile("customers.txt");

	if (iFile.is_open())
	{
		while ( getline(iFile, textLine) )
		{
			cout << textLine << '\n';
			char firstChr = textLine[0];
			

			if (firstChr == (char) commentTag) {
				continue;
			}

			// Detect customer identifier
			if (firstChr == (char) ctmIdentifier) {
				isCtmProfile = true;

				//TODO write to CtmList
				string inputVal[dbInputLength];
				const char delimeter = ',';
				int cursor = 0, idxInput = 0;

				while ( (cursor = textLine.find(delimeter) ) != std::string::npos ) 
				{
					inputVal[idxInput++] = textLine.substr(0, cursor);
					textLine.erase(0, cursor + 1); // +1 for delimeter
				}

				ctmPtr->appendHead(inputVal[0], inputVal[1], inputVal[2], inputVal[3], ctmTypeUtil(inputVal[5]));

				//NOTE confirm no. of rentals
				totalRental = atoi(inputVal[4].c_str());
				continue;
			}
			
			if (firstChr == (char) itemIdentifier) {

				cout << textLine << '\n';
			}
		}
		iFile.close();
	}
	return -1;
}

ctmTypeEnum ctmTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "VIP"))
	{
		return ctmTypeEnum::VIP;
	}
	else if ( (strcmp(str2arr(str.c_str()), "REGULAR")) )
	{
		return ctmTypeEnum::REGULAR;
	}
	else if ((strcmp(str2arr(str.c_str()), "GUEST")))
	{
		return ctmTypeEnum::GUEST;
	}
}

char* str2arr(string str) {
	char* cTypeStr = new char[str.length() + 1];
	strcpy(cTypeStr, str.c_str() );
	return cTypeStr;
}

