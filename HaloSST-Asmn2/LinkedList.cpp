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
	item* current = head;
	if (current == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	else {
		current = head->getNext();
		delete head;
		head = current;
		while (current->getNext() != NULL) { // node exists
			current = current->getNext(); // set current to next node

		}
	}
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

/*
void ItemList::deleteList()
{
	node *currentPtr = head;
	while (currentPtr != NULL)
	{
		currentPtr = currentPtr->getNext();
		delete head;
		head = currentPtr;
	}
}
void ItemList::appendTail(string name)
{
	node *currentPtr = head;
	while (currentPtr->getNext() != NULL)
		currentPtr = currentPtr->getNext();
	currentPtr->setNext(new node(currentPtr->getData() + 1));
	currentPtr->getNext()->setName(name);
	currentPtr->getNext()->setNext(NULL);
}
void ItemList::printList()
{
	node *currentPtr = head;
	if (currentPtr == NULL)
		cout << "No people are in the line" << endl;
	else
	{
		while (currentPtr != NULL)
		{
			cout << "The " << currentPtr->getData() << "th person in line is " << currentPtr->getName() << endl;
			currentPtr = currentPtr->getNext();
		}
	}
}
void ItemList::removeHead()
{
	node *currentPtr = head->getNext();
	delete head;
	head = currentPtr;
	while (currentPtr != NULL)
	{
		currentPtr->setData(currentPtr->getData() - 1);
		currentPtr = currentPtr->getNext();
	}
}
void ItemList::removeTail()
{
	node *currentPtr = head;
	while (currentPtr->getNext()->getNext() != NULL)
		currentPtr = currentPtr->getNext();
	delete currentPtr->getNext();
	currentPtr->setNext(NULL);
}
void ItemList::size()
{
	int count = 0;
	node *currentPtr = head;
	while (currentPtr != NULL)
	{
		count++;
		currentPtr = currentPtr->getNext();
	}
	cout << "There are " << count << " people in line" << endl;
}
void ItemList::removeNode(string name)
{
	node *currentPtr = head;
	if (currentPtr->getName() == name)
		this->removeHead();
	else
	{
		while ((currentPtr->getNext()->getName() != name) && (currentPtr->getNext()->getNext() != NULL))
			currentPtr = currentPtr->getNext();
		if (currentPtr->getNext()->getName() != name)
			cout << "No people called " << name << " are in line" << endl;
		else
		{
			if (currentPtr->getNext()->getNext() == NULL)
				this->removeTail();
			else
			{
				int tempNumber = currentPtr->getData();
				node *tempPtr = currentPtr->getNext();
				currentPtr->setNext(tempPtr->getNext());
				delete tempPtr;
				while (currentPtr->getNext() != NULL)
				{
					currentPtr = currentPtr->getNext();
					currentPtr->setData(++tempNumber);
				}
			}
		}
	}
}*/

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

void CtmList::addCtmItemList(string item) { // Using to test, Can be upgrade when implement successfully search
	head->addItem(item);
}

customer* CtmList::searchCtm(string name, string id) {// TODO: compare string work by work
	customer *current = head;
	while (current != NULL) {
		if (current->getName().compare(name) && current->getID().compare(id)) {
			cout << "Customer found" << endl;
			cout << "Customer ID: " << current->getID() << endl;
			cout << "Customer Name: " << current->getName() << endl;
			return current;
		}
		else {
			cout << "Customer is not exist in the list" << endl;
			return NULL;
		}
		current = current->getNext();
	}
}

void CtmList::printCtm(customer* ctm) {
	cout << "/////////////////////////////////////////////////" << endl;
	cout << "Customer ID: " << ctm->getID() << endl;
	cout << "Customer Name: " << ctm->getName() << endl;
	cout << "Customer Address: " << ctm->getAddr() << endl;
	cout << "Customer Phone: " << ctm->getPhone() << endl;
	cout << "Customer Type: " << ctm->getCtmType() << endl;
	ctm->printCtmRental();
	//ctm->successReturn();
	cout << "Customer Success Return: " << ctm->getSuccessReturn() << endl;
	cout << "Customer MAX: " << ctm->getMaxVid() << endl;

	cout << "/////////////////////////////////////////////////" << endl;
}

void CtmList::printList()
{
	customer *current = head;
	if (current == NULL)
		cout << "No items are in the line" << endl;
	else
	{
		while (current != NULL)
		{
			printCtm(current);
			current = current->getNext();
		}
	}
}