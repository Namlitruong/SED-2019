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
#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "IC.h"

using namespace std;

class ItemList {
	item *head = NULL;
public:
	ItemList() { head = NULL, cout << "Item List is created" << endl; }
	~ItemList() { cout << "Item List is destroyed" << endl; }
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); //Using for Video/Movies
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool); //Using for Game
	void printList();
	void printItem(item*);
	void appendTail(string, string, rentalTypeEnum, bool, int, double, bool); //Using for Game
	void appendTail(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum);
	void removeHead();
	void removeTail();
	item *searchItemByTitle(string);
	item *searchItemByID(string);
	item *getItemHead() { return this->head; }
	bool removeItemByID(string);
	int size();
	void deleteList();
};

class CtmList {
	customer *head = NULL;
public:
	CtmList() { head = NULL, cout << "Customer List is created" << endl; }
	~CtmList() { cout << "Customer List is destroyed" << endl; }
	void appendHead(string id, string name, string addr, string phone, ctmTypeEnum ctmType);
	void printList();
	void printListByCtmType(ctmTypeEnum);
	void printCtm(customer*);
	void addCtmItemList(customer*, string);
	customer* getCtmHead() { return this->head; }
	customer* searchCtmName(string);
	customer* searchCtmID(string);
	void removeHead();
	void appendTail(string id, string name, string addr, string phone, ctmTypeEnum ctmType);
	void removeTail();
	bool removeNodeByID(string name);
	bool removeNode(customer*);
	int size();
	void deleteList();
};