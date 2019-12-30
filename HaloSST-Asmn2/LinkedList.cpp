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

// Function of adding new head item for Game
void ItemList::appendHead(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee) {
	// set current pointer to head and create new item node
	item *current = head;
	item *newItem = new game(id, title, rentalType, loanStatus, numOfCopy, rentFee);
	if (current == NULL) { //item not exists, add new item to head
		head = newItem;
	}
	else { // item exists, move current to next item & new item as head.
		newItem->setNext(current);
		head = newItem;
	}
}

//Overloading function of adding new head item for DVD & Record
void ItemList::appendHead(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, genreTypeEnum genreType) {
	// set current pointer to head and create new item node
	item *current = head;
	item *newItem;
	switch (rentalType) {
	case 0: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	case 1: newItem = new dvd(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	default: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	}
	if (current == NULL) { //item not exists, add new item to head
		head = newItem;
	}
	else { // item exists, move current to next item & new item as head.
		newItem->setNext(current);
		head = newItem;
	}
}

//TODO remove deprecated function

// Function of displaying list of items
void ItemList::printList()
{
	item *current = head;
	if (current == NULL)
		cout << "No items are in the line" << endl;
	else
	{
		item *temp = NULL;
		// items exist, display to console and move pointer to next item.
		while (current != NULL)
		{
			printItem(current);
			current = current->getNext();
		}
	}
}

void swapItem(item* thisNode, item* nextNode) {
	string tmpID = thisNode->getID();
	thisNode->setID(nextNode->getID());
	nextNode->setID(tmpID);

	string tmpTitle = thisNode->getTitle();
	thisNode->setTitle(nextNode->getTitle());
	nextNode->setTitle(tmpTitle);

	rentalTypeEnum tmpRentalType = thisNode->getRentalType();
	thisNode->setRentalType(nextNode->getRentalType());
	nextNode->setRentalType(tmpRentalType);

	bool tmpLoanStatus = thisNode->getLoanStatus();
	thisNode->setLoanStatus(nextNode->getLoanStatus());
	nextNode->setLoanStatus(tmpLoanStatus);

	//FIXME incorrect value
	int tmpNumOfCopy = thisNode->getNumOfCopy();
	thisNode->setNumOfCopy(nextNode->getNumOfCopy());
	nextNode->setNumOfCopy(tmpNumOfCopy);

	double tmpRentFee = thisNode->getRentFee();
	thisNode->setRentFee(nextNode->getRentFee());
	nextNode->setRentFee(tmpRentFee);

	/*
	bool isAvailable = thisNode->getID();
	thisNode->setID(nextNode->getID());
	nextNode->setID(tmp);
	*/

}

void ItemList::prtSortedItemList(prtSortedList printType)
{
	//NOTE Bubble Sort. Merge would be better for Linked List
	item *current = head;
	int itemCtr = ItemList::size(); // ItemList size, i.e. Total Items

	if (current == NULL)
		cout << "No items are in the line" << endl;
	else
	{

		// Traverse through list element
		for (int itemIdx = 0; itemIdx < itemCtr; itemIdx++)
		{
			// For each element
			while (current->getNext())
			{
				switch (printType)
				{
				case byTitle:
					if (current->getTitle() > current->getNext()->getTitle()) {
						swapItem(current, current->getNext());
						current = current->getNext();
					} else { current = current->getNext(); }

					break;
				case byID:
				default:
					if (current->getID() > current->getNext()->getID()) {
						swapItem(current, current->getNext());
						current = current->getNext();
					}
					else { current = current->getNext(); }
					break;
				}
			}
			// Now update current as last Node (LIFO)
			current = head;
		}

		// Print out the list
		while (current)
		{
			printItem(current);
			current = current->getNext();
		}
	}
}

// Function of displaying out of stock items
void ItemList::printOosItem() {
	// set current pointer to head item and initialize count variable
	item *current = head;
	int count = 0;
	while (current != NULL)
	{ // get number of copy of current & compare. If equal 0, display to console
		if (current->getNumOfCopy() == 0) {
			printItem(current);
			count++;
		}
		current = current->getNext(); // move to next current
	}
	// otherwise, display message that not having out of stock items
	if (count == 0)cout << "No Out of Stock Item" << endl;
}

void ItemList::printItem(item* its)
{
	cout << "/////////////////////////////////////////////////" << endl;
	cout << "Item ID: " << its->getID() << endl;
	cout << "Item Title: " << its->getTitle() << endl;
	//cout << "Item Type: " << its->getRentalType() << endl;
	switch (its->getRentalType()) {
	case RECORD: {
		cout << "Item Type: RECORD" << endl;
		switch ((static_cast<record*>(its))->getGenreType()) {
		case ACTION:	cout << "Item Genre: ACTION" << endl; break;
		case HORROR:	cout << "Item Genre: HORROR" << endl; break;
		case DRAMA:		cout << "Item Genre: DRAMA" << endl; break;
		case COMEDY:	cout << "Item Genre: COMEDY" << endl; break;
		default: break;
		}
		break; }
	case DVD: {
		cout << "Item Type: DVD" << endl;
		switch ((static_cast<record*>(its))->getGenreType()) {
		case ACTION:	cout << "Item Genre: ACTION" << endl; break;
		case HORROR:	cout << "Item Genre: HORROR" << endl; break;
		case DRAMA:		cout << "Item Genre: DRAMA" << endl; break;
		case COMEDY:	cout << "Item Genre: COMEDY" << endl; break;
		default: break;
		}
		break; }
	default: {
		cout << "Item Type: GAME" << endl;
		break; }
	}
	cout << "Item Number of Copy: " << its->getNumOfCopy() << endl;

	if (its->getLoanStatus()) cout << "Item Loan tyle: 1-week loan" << endl;
	else cout << "Item Loan tyle: 2-day loan" << endl;

	cout << "Item Rent Fee: " << its->getRentFee() << endl;
	cout << "/////////////////////////////////////////////////" << endl;
}

// Function of adding tail item for Game
void ItemList::appendTail(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee) {
	// set current pointer to head and create new item node
	item* current = head;
	item* newItem = new game(id, title, rentalType, loanStatus, numOfCopy, rentFee);
	// items not exist, add to head
	if (current == NULL) {
		head = newItem;
	}
	else {
		while (current->getNext() != NULL)	current = current->getNext(); // find tail node
		current->setNext(newItem); // link to new item
		newItem->setNext(NULL);
	}

}

// Overloading function of adding tail item using for Record and DVD
void ItemList::appendTail(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, genreTypeEnum genreType) {
	// set current pointer to head and create new item node
	item* current = head;
	item* newItem;
	switch (rentalType)
	{
	case 0: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	case 1: newItem = new dvd(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	default: newItem = new record(id, title, rentalType, loanStatus, numOfCopy, rentFee, genreType); break;
	}
	// items not exist, add to head
	if (current == NULL) {
		head = newItem;
	}
	else {
		while (current->getNext() != NULL)	current = current->getNext(); // find tail node
		current->setNext(newItem); // link to new item
		newItem->setNext(NULL);
	}
}
// Function of removing head item
void ItemList::removeHead() {
	if (head == NULL) {
		cout << "Linked list does not exit" << endl;
	}
	// set temp pointer to head, then move head to next item and delete temp
	item* temp = head;
	head = temp->getNext();
	temp->setNext(NULL);
	delete temp;
}
// Function of removing tail item
void ItemList::removeTail() {
	item* current = head; // set current pointer to head
	if (current == NULL) { // item not exist, display message to console
		cout << "Linked list does not exist" << endl;
	}
	else {
		while (current->getNext()->getNext() != NULL) { // node exists
			current = current->getNext(); // set current to next node
		}
		delete current->getNext(); // delete the next item until NULL
		current->setNext(NULL);
	}
}

//Function of searching item by title
item *ItemList::searchItemByTitle(string title) {
	item* current = head;
	// loop through the existing list, compare the contents of both string.
	while (current != NULL) {
		if (strcmp(current->getTitle().c_str(), title.c_str()) == 0) {
			cout << "ITEM FOUND" << endl;
			// In case it return value = 0, means that equal, display item to the console
			printItem(current);
			return current;
		}
		current = current->getNext();
	}
	cout << "Item with Title: " << title << " is not exist in the list" << endl;
	return NULL;
}

// Function of searching item by id
item *ItemList::searchItemByID(string id) {
	item* current = head;
	// loop through the existing list, compare the contents of both string.
	while (current != NULL) {
		if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
			cout << "ITEM FOUND" << endl;
			// In case it return value = 0, means that equal, display item to the console
			printItem(current);
			return current;
		}
		current = current->getNext();
	}
	cout << "Item with ID: " << id << " is not exist in the list" << endl;
	return NULL;
}

bool ItemList::removeItemByID(string id) {
	item* current = head;
	item* previous = NULL;
	item* after = current->getNext();
	if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
		this->removeHead();
		return true;
	}
	else {
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

bool ItemList::removeItemNode(item* node) {
	item* current = head;
	item* previous = NULL;
	item* after = current->getNext();
	if (current == node) {
		this->removeHead();
		return true;
	}
	else {
		while (current != node) {
			previous = current;
			current = current->getNext();
			after = current->getNext();
			if (after == NULL) {//	return false;
				if (current == node) {
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

// Function of get number of existing items in list
int ItemList::size()
{
	int count = 0;
	item* current = head;
	// loop through the list, increase 1 when having item
	while (current != NULL)
	{
		count++;
		current = current->getNext(); // move current to next item
	}
	return count;
}

// Function of delete list of items
void ItemList::deleteList()
{  // if the head item is not null, remove it until it is NULL
	while (head != NULL)	this->removeHead();
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

customer* CtmList::searchCtmID(string id) {
	customer *current = head;
	while (current != NULL) {
		if (strcmp(current->getID().c_str(), id.c_str()) == 0) {
			cout << "CUSTOMER FOUND" << endl;
			printCtm(current);
			return current;
		}
		current = current->getNext();
	}
	cout << "Customer with ID: " << id << " is not exist in the list" << endl;
	return NULL;
}


customer* CtmList::searchCtmName(string name) {
	customer *current = head;
	while (current != NULL) {
		if (strcmp(current->getName().c_str(), name.c_str()) == 0) {
			cout << "CUSTOMER FOUND" << endl;
			printCtm(current);
			return current;
		}
		current = current->getNext();
	}
	cout << "Customer with Name: " << name << " is not exist in the list" << endl;
	return NULL;
}

void CtmList::printListByCtmType(ctmTypeEnum input) {
	customer *current = head;
	while (current != NULL)
	{
		if (current->getCtmType() == input) printCtm(current);
		current = current->getNext();
	}
}

void CtmList::printCtm(customer* ctm) {
	cout << "/////////////////////////////////////////////////" << endl;
	cout << "Customer ID: " << ctm->getID() << endl;
	cout << "Customer Name: " << ctm->getName() << endl;
	cout << "Customer Phone: " << ctm->getPhone() << endl;
	cout << "Customer Address: " << ctm->getAddr() << endl;
	switch (ctm->getCtmType()) {
	case REGULAR: cout << "Customer Type: REGULAR" << endl; break;
	case VIP:	cout << "Customer Type: VIP" << endl; break;
	default:	cout << "Customer Type: GUEST" << endl; break;
	}
	ctm->printCtmRental();
	cout << "/////////////////////////////////////////////////" << endl;
}

// TODO remove deprecated function
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

void swapCtm(customer* thisNode, customer* nextNode) {
	string tmpID = thisNode->getID();
	thisNode->setID(nextNode->getID());
	nextNode->setID(tmpID);

	string tmpName = thisNode->getName();
	thisNode->setName(nextNode->getName());
	nextNode->setName(tmpName);

	string tmpAddr = thisNode->getAddr();
	thisNode->setAddr(nextNode->getAddr());
	nextNode->setAddr(tmpAddr);

	ctmTypeEnum tmpCtmType = thisNode->getCtmType();
	thisNode->setCtmType(nextNode->getCtmType());
	nextNode->setCtmType(tmpCtmType);

	string tmpPhone = thisNode->getPhone();
	thisNode->setPhone(nextNode->getPhone());
	nextNode->setPhone(tmpPhone);

	//TODO no. of Rental
	//int tmpNumOfRental;

	//TODO list of rental print
	// string *getListOfRental;
}

void CtmList::prtSortedCtmList(prtSortedList printType)
{
	//NOTE Bubble Sort. Merge would be better for Linked List
	customer *current = head;

	int ctmCtr = CtmList::size(); // ItemList size, i.e. Total Items

	if (current == NULL)
		cout << "No items are in the line" << endl;
	else
	{

		// Traverse through list element
		for (int itemIdx = 0; itemIdx < ctmCtr; itemIdx++)
		{
			// For each element
			while (current->getNext())
			{
				switch (printType)
				{
				case byName:
					if (current->getName() > current->getNext()->getName()) {
						swapCtm(current, current->getNext());
						current = current->getNext();
					}
					else { current = current->getNext(); }

					break;
				case byID:
				default:
					if (current->getID() > current->getNext()->getID()) {
						swapCtm(current, current->getNext());
						current = current->getNext();
					}
					else { current = current->getNext(); }
					break;
				}
			}
			// Now update current as last Node (LIFO)
			current = head;
		}

		// Print out the list
		while (current)
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
		while (current->getNext() != NULL)	current = current->getNext(); // find tail node
		current->setNext(newItem);
		newItem->setNext(NULL);
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

bool CtmList::removeNode(customer* node) {
	customer* current = head;
	customer* previous = NULL;
	customer* after = current->getNext();
	if (current == node) {
		this->removeHead();
		return true;
	}
	else {
		while (current != node) {
			previous = current;
			current = current->getNext();
			after = current->getNext();
			if (after == NULL) {//	return false;
				if (current == node) {
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
