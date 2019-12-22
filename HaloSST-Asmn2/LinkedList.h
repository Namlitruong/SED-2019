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
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); //Using for Game
	void printList();
	void appendHead(string, string, rentalTypeEnum, bool, int, double, bool);
	/*void appendHead(string, string, rentalTypeEnum, bool, int, int, bool, genreTypeEnum); //Overloading using for Record and DVD
	void removeHead();
	void appendTail(string name);
	void removeTail();
	void removeNode(string name);
	void size();
	void printList();
	void deleteList();*/
};