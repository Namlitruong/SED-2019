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
//////////////////////////--Define Macro--/////////////////////////////
using namespace std;
// Enum type for sorting list
enum prtSortedList {
	byName,
	byTitle,
	byID
};

/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////
//Enum type for rental type
enum rentalTypeEnum {
	RECORD,
	DVD,
	GAME,
};
//Enum type for genre type
enum genreTypeEnum {
	NONE,
	ACTION,
	HORROR,
	DRAMA,
	COMEDY,
};
class item { //Parent class
protected:
	string id;
	string title;
	rentalTypeEnum rentalType;
	bool loanStatus;//1 weeks or 2 days
	int numOfCopy = 0;
	double rentFee;
	bool isAvailable; //borrowed or available
	item *next = NULL; // pointer to next
public:
	item();//by Defautl
	item(string, string, rentalTypeEnum, bool, int, double); //parameterized
	item(const item&);//copy
	~item();
	//////////////////--Getter--//////////////
	item* getNext() { return next; }
	string getID() { return this->id; }
	string getTitle() { return this->title; }
	rentalTypeEnum getRentalType() { return this->rentalType; }
	bool getLoanStatus() { return this->loanStatus; }
	int getNumOfCopy() { return this->numOfCopy; }
	double getRentFee() { return this->rentFee; }
	virtual genreTypeEnum getGenreType() = 0;
	//////////////////--Setter--//////////////
	void setNext(item *next) { this->next = next; }
	void setID(string id) { this->id = id; }
	void setTitle(string title) { this->title = title; }
	void setRentalType(rentalTypeEnum rentalType) { this->rentalType = rentalType; }
	void setLoanStatus(bool loanType) { this->loanStatus = loanType; }
	void setNumOfCopy(int numOfCopy) { this->numOfCopy = this->numOfCopy + numOfCopy; }
	void setRentFee(double rentFee) { this->rentFee = rentFee; }
	virtual void setGenreType(genreTypeEnum genreType) = 0;
};

class record : public item { // Child class
protected: 
	genreTypeEnum genreType;
public:
	record(); //by default
	record(string, string, rentalTypeEnum, bool, int, double, genreTypeEnum); //parameterized
	record(const record&);//copy
	~record();
	// Predefined virtual function
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class dvd : public item {// Child class
protected:
	genreTypeEnum genreType;
public:
	dvd(); //By default
	dvd(string, string, rentalTypeEnum, bool, int, double, genreTypeEnum); //parameterized
	dvd(const dvd&);//copy
	~dvd();
	// Predefined virtual function
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class game : public item { // Child class
protected:
	genreTypeEnum genreType;
public:
	game();//By default
	game(string, string, rentalTypeEnum, bool, int, double); //parameterized
	game(const game&);//copy
	~game();
	// Predefined virtual function
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};
/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////



/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
//Enum type for customer type
enum ctmTypeEnum {
	GUEST,
	REGULAR,
	VIP,
};
class customer { //Parent class
protected:
	string id;
	string name;
	string addr;
	string phone;
	ctmTypeEnum ctmType;
	string listOfRental[50]; // It suppose to be infinite, but set limit to 50, because in reality no one borrow 50 itmes at a time. Setting 50 to prevent buffer overflow.
	customer *next = NULL; // pointer to next
public:
	customer();//by Defautl
	customer(string, string, string, string, ctmTypeEnum); //parameterized
	customer(const customer&);//copy
	~customer();
	//////////////////--Getter--//////////////
	customer* getNext() { return next; }
	string getID() { return this->id; }
	string getName() { return this->name; }
	string getAddr() { return this->addr; }
	ctmTypeEnum getCtmType() { return this->ctmType; }
	string getPhone() { return this->phone; }
	int numOfRental();
	string *getListOfRental(){ return this->listOfRental; }
	virtual int getSuccessReturn() = 0;
	virtual int getMaxVid() = 0;
	//////////////////--Setter--//////////////
	void setNext(customer *next) { this->next = next; }
	void setID(string id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAddr(string addr) { this->addr = addr; }
	void setCtmType(ctmTypeEnum ctmType) { this->ctmType = ctmType; }
	void setPhone(string phone) { this->phone = phone; }
	virtual void successReturn() = 0;
	////////////////--Processing Item Function--/////////////////////////
	void addItem(string);
	int removeItem(string);
	void printCtmRental();
};

class guest : public customer {//Child class
protected:
	int maxVid;
	int successReturnNumb;
public:
	guest(); //by default
	guest(string, string, string, string, ctmTypeEnum); //parameterized
	guest(const guest&);//copy
	~guest();
	// Predefined virtual function
	int getMaxVid() { return this->maxVid; }
	void successReturn() { this->successReturnNumb++; }
	int getSuccessReturn() { return this->successReturnNumb; }
};

class regular : public customer {//Child class
protected:
	int successReturnNumb;
public:
	regular(); //by default
	regular(string, string, string, string, ctmTypeEnum); //parameterized
	regular(const regular&);//copy
	~regular();
	// Predefined virtual function
	int getMaxVid() { return 1000; }
	void successReturn() { this->successReturnNumb++; }
	int getSuccessReturn() { return this->successReturnNumb; }
};

class vip : public customer {//Child class
protected:
	int rewardPoint;
public:
	vip(); //by default
	vip(string, string, string, string, ctmTypeEnum); //parameterized
	vip(const vip&);//copy
	~vip();
	// Predefined virtual function
	int getMaxVid() { return 1000; }
	void successReturn();
	int getSuccessReturn();
};