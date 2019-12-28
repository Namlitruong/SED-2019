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
#include "LinkedList.h"
////////////////////////////--ITEM--/////////////////////////////////////////
void ItemList::appendHead(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, bool isAvailable) {
	item *current = head;
	item *newItem = new game(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable);
	if (current == NULL) {
		head = newItem;
	}
	else {
		newItem->setNext(current);
		head = newItem;
	}
}

void ItemList::appendHead(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, bool isAvailable, genreTypeEnum genreType) {
	item *current = head;
	item *newItem;
	switch (rentalType) {
	case 0: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	case 1: newItem = new dvd(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	default: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	}
	if (current == NULL) {
		head = newItem;
	}
	else {
		newItem->setNext(current);
		head = newItem;
	}
}

void ItemList::printList()
{
	item *current = head;
	if (current == NULL)
		cout << "No items are in the line" << endl;
	else
	{
		while (current != NULL)
		{
			cout << "/////////////////////////////////////////////////" << endl;
			cout << "Item ID: " << current->getID() << endl;
			cout << "Item Title: " << current->getTitle() << endl;
			cout << "Item Type: " << current->getRentalType() << endl;
			switch (current->getRentalType()) {
			case 0: {
				cout << "Item Genre: " << (static_cast<record*>(current))->getGenreType() << endl;
				break; }
			case 1: {
				cout << "Item Genre: " << (static_cast<dvd*>(current))->getGenreType() << endl;
				break; }
			}
			cout << "Item Number of Copy: " << current->getNumOfCopy() << endl;
			cout << "Item Rent Fee: " << current->getRentFee() << endl;
			cout << "Item Status: " << current->getIsAvailable() << endl;
			cout << "/////////////////////////////////////////////////" << endl;
			current = current->getNext();
		}
	}
}

void ItemList::appendTail(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, bool isAvailable) {
	item* current = head;
	item* newItem = new game(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable);

	if (current == NULL) {
		head = newItem;
	}
	else {
		while (current->getNext() != NULL)
			current = current->getNext(); // find tail node
		current->setNext(newItem);
	}

}

void ItemList::appendTail(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, bool isAvailable, genreTypeEnum genreType) {
	item* current = head;
	item* newItem;
	switch (rentalType)
	{
	case 0: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	case 1: newItem = new dvd(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	default: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable, genreType); break;
	}
	if (current == NULL) {
		head = newItem;
	}
	else {
		while (current->getNext() != NULL)
			current = current->getNext(); // find tail node
		current->setNext(newItem);
	}
}

void ItemList::removeHead() {
	if (head == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	item* temp = head;
	head = temp->getNext();
	temp->setNext(NULL);
	delete temp;
}

void ItemList::removeTail() {
	item* current = head;
	if (current == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	else {
		while (current->getNext()->getNext() != NULL) { // node exists
			current = current->getNext(); // set current to next node
		}
		delete current->getNext();
		current->setNext(NULL);
	}
}

void ItemList::searchItem(string id) {
	item* current = head;
	if (current == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	else {
		while (current != NULL) {
			if (current->getID() == id) {
				cout << "found" << endl;
				cout << "Item ID: " << current->getID() << endl;
			}

			else if (current->getID() != id) {

				cout << "not found" << endl;
			}
			current = current->getNext();

		}
	}
}
////////////////////////////--CUSTOMER--/////////////////////////////////////////
void CtmList::appendHead(string id, string name, string addr, string phone, ctmTypeEnum ctmType) {
	customer *current = head;
	customer *newItem;
	switch (ctmType) {
	case 1: newItem = new regular(id, name, addr, phone, ctmType); break;
	case 2: newItem = new vip(id, name, addr, phone, ctmType); break;
	default: newItem = new guest(id, name, addr, phone, ctmType); break;
	}
	if (current == NULL) {
		head = newItem;
	}
	else {
		newItem->setNext(current);
		head = newItem;
	}
}

void CtmList::addCtmItemList(customer* Ctm, string item) { // Using to test, Can be upgrade when implement successfully search
	Ctm->addItem(item);
}

customer* CtmList::searchCtmName(string name) {// TODO: compare string work by work
	customer *current = head;
	while (current != NULL) {
		if (strcmp(current->getName().c_str(), name.c_str()) == 0) {
			cout << "CUSTOMER FOUND" << endl;
			cout << "Customer ID: " << current->getID() << endl;
			cout << "Customer Name: " << current->getName() << endl;
			cout << "Customer Phone: " << current->getPhone() << endl;
			cout << "Customer Address: " << current->getAddr() << endl;
			return current;
		}
		current = current->getNext();
	}
	cout << "Customer " << name << " is not exist in the list" << endl;
	return NULL;
}

customer* CtmList::searchCtmID(string id) {// TODO: compare string work by work
	customer *current = head;
	while (current != NULL) {
		if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
			cout << "CUSTOMER FOUND" << endl;
			cout << "Customer ID: " << current->getID() << endl;
			cout << "Customer Name: " << current->getName() << endl;
			cout << "Customer Phone: " << current->getPhone() << endl;
			cout << "Customer Address: " << current->getAddr() << endl;
			return current;
		}
		current = current->getNext();
	}
	cout << "Customer " << id << " is not exist in the list" << endl;
	return NULL;
}

void CtmList::printCtm(customer* ctm) {
	cout << "/////////////////////////////////////////////////" << endl;
	cout << "Customer ID: " << ctm->getID() << endl;
	cout << "Customer Name: " << ctm->getName() << endl;
	cout << "Customer Address: " << ctm->getAddr() << endl;
	cout << "Customer Phone: " << ctm->getPhone() << endl;
	cout << "Customer Type: " << ctm->getCtmType() << endl;
	ctm->printCtmRental();
	cout << "Customer Success Return: " << ctm->getSuccessReturn() << endl;
	cout << "Customer MAX: " << ctm->getMaxVid() << endl;
	cout << "/////////////////////////////////////////////////" << endl;
}

void CtmList::printList()
{
	customer *current = head;
	if (current == NULL)
		cout << "No items are in the list" << endl;
	else
	{
		while (current != NULL)
		{
			printCtm(current);
			current = current->getNext();
		}
	}
}

void CtmList::removeHead() {
	if (head == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	customer* temp = head;
	head = temp->getNext();
	temp->setNext(NULL);
	delete temp;
}

void CtmList::appendTail(string id, string name, string addr, string phone, ctmTypeEnum ctmType) {
	customer* current = head;
	customer* newItem;
	switch (ctmType) {
	case 1: newItem = new regular(id, name, addr, phone, ctmType); break;
	case 2: newItem = new vip(id, name, addr, phone, ctmType); break;
	default: newItem = new guest(id, name, addr, phone, ctmType); break;
	}
	if (current == NULL) {
		head = newItem;
	}
	else {
		while (current->getNext() != NULL)
			current = current->getNext(); // find tail node
			current->setNext(newItem);
	}
}

void CtmList::removeTail() {
	customer* current = head;
	if (current == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	else {
		while (current->getNext()->getNext() != NULL) { // node exists
			current = current->getNext(); // set current to next node
		}
		delete current->getNext();
		current->setNext(NULL);
	}
}

bool CtmList::removeNodeByID(string id) {
	customer* current = head;
	customer* previous = NULL;
	customer* after = current->getNext();
	if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
		this->removeHead();
		return true;
	}
	else{
		while (strcmp(current->getID().c_str(), id.c_str()) != 0) {
			previous = current;
			current = current->getNext();
			after = current->getNext();
			if (after == NULL) {//	return false;	
				if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
					this->removeTail();
					return true;
				}
				else return false;
			}
		}
		previous->setNext(after);
		current->setNext(NULL);
		delete current;	
	}
	return true;
}

void CtmList::deleteList()
{
	while (head != NULL)	this->removeHead();
}

int CtmList::size()
{
	int count = 0;
	customer *current = head;
	while (current != NULL)
	{
		count++;
		current = current->getNext();
	}
	return count;
}