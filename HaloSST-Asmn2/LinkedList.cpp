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

void ItemList::appendHead(string id, string title, rentalTypeEnum rentalType, bool loanStatus, int numOfCopy, double rentFee, bool isAvailable){
	item *current = head;
	item *newItem = new game(id, title, rentalType, loanStatus, numOfCopy, rentFee, isAvailable);
	if (current == NULL) {
		head = newItem;
	}else {
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
			cout << "Item ID: " << current->getID() <<endl;
			cout << "Item Title: " << current->getTitle() << endl;
			cout << "Item Type: " << current->getRentalType() << endl;
			switch (current->getRentalType()) {
			case 0:{
				//record* child = dynamic_cast<record*>(current);
				cout << "Item Genre: " << (static_cast<record*>(current))->getGenreType() << endl;
				//delete child;
				break;}
			case 1: {
				//dvd* child1 = dynamic_cast<dvd*>(current);
				cout << "Item Genre: " << (static_cast<record*>(current))->getGenreType() << endl;
				//delete child1;
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

/*void ItemList::appendTail(string name)
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