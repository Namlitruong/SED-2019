// Ass2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "IC.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

class parent {
protected:
	int a;
	int b;
	int c;
	parent* next;
public:
	parent() { a = 1; b = 2; c = 3;}
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
	void setA(int A) { this->A = A;}
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

int main()
{
	ItemList *ListOfItem = new ItemList();
	ListOfItem->appendHead("I001-2001", "Medal of Honour", rentalTypeEnum::GAME, true, 3, 3.99, true);
	ListOfItem->appendHead("I005-2015", "Halo", rentalTypeEnum::GAME, true, 2, 3.99, true);
	ListOfItem->appendHead("I004-1999", "Rat Race", rentalTypeEnum::DVD, 1, 3, 1.99, true, genreTypeEnum::HORROR);
	ListOfItem->appendHead("I003-1992", "Alpha Dog", rentalTypeEnum::RECORD, 1, 3, 1.99, true, genreTypeEnum::COMEDY);
	ListOfItem->printList();
	delete ListOfItem;

	/*ItemListTest *ListOfItem = new ItemListTest();
	ListOfItem->appendChild1();
	ListOfItem->appendChild(11, 12, 13, 14);
	ListOfItem->appendChild1();
	ListOfItem->appendChild(21, 22, 23, 24);
	ListOfItem->appendChild1();
	ListOfItem->printList();
	delete ListOfItem;*/

	return 0;
}

