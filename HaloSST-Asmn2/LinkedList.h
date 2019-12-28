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

class ItemList{
	item *head;
public:
	ItemList() { head = NULL, cout << "Item List is created" << endl; }
	~ItemList() { cout << "Item List is destroyed" << endl; }
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); //Using for Video/Movies
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool); //Using for Game
	void printList();
	void appendTail(string, string, rentalTypeEnum, bool, int, double, bool); //Using for Game
	void appendTail(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); 
	void removeHead();
	void removeTail();
	void searchItem(string);

	/*
	void removeNode(string name);
	void size();
	void deleteList();*/
};

class CtmList {
	customer *head;
public:
	CtmList() { head = NULL, cout << "Item List is created" << endl; }
	~CtmList() { cout << "Item List is destroyed" << endl; }
	void appendHead(string id, string name, string addr, string phone, ctmTypeEnum ctmType);
	void printList();
	void printCtm(customer*);
	void addCtmItemList(string);
	customer* searchCtm(string, string);
	//void printCtmRental();
	/*void appendHead(string, string, rentalTypeEnum, bool, int, int, bool, genreTypeEnum); //Overloading using for Record and DVD
	void removeHead();
	void appendTail(string name);
	void removeTail();
	void removeNode(string name);
	void size();
	void printList();
	void deleteList();*/
};