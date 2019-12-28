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

/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////
enum rentalTypeEnum {
	RECORD,
	DVD,
	GAME,
};

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
	int numOfCopy;
	double rentFee;
	bool isAvailable; //borrowed or available
	item *next = NULL; // pointer to next
public:
	item();//by Defautl
	item(string, string, rentalTypeEnum, bool, int, double, bool); //parameterized
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
	bool getIsAvailable() { return this->isAvailable; }
	//////////////////--Setter--//////////////
	void setNext(item *next) { this->next = next; }
	void setID(string id) { this->id = id; }
	void setTitle(string title) { this->title = title; }
	void setRentalType(rentalTypeEnum rentalType) { this->rentalType = rentalType; }
	void setLoanStatus(bool loanType) { this->loanStatus = loanType; }
	void setNumOfCopy(int numOfCopy) { this->numOfCopy = numOfCopy; }
	void setRentFee(double rentFee) { this->rentFee = rentFee; }
	void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
	//////////////////////////////VIRTTUAL
	virtual void setGenreType(genreTypeEnum genreType) = 0;
	virtual genreTypeEnum getGenreType() = 0;
};

class record : public item {
protected: 
	genreTypeEnum genreType;
public:
	record(); //by default
	record(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); //parameterized
	record(const record&);//copy
	~record();
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class dvd : public item {
protected:
	genreTypeEnum genreType;
public:
	dvd(); //By default
	dvd(string, string, rentalTypeEnum, bool, int, double, bool, genreTypeEnum); //parameterized
	dvd(const dvd&);//copy
	~dvd();
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class game : public item {
public:
	game();//By default
	game(string, string, rentalTypeEnum, bool, int, double, bool); //parameterized
	game(const game&);//copy
	~game();
	void setGenreType(genreTypeEnum genreType) {}
	genreTypeEnum getGenreType() { return NONE; }
};
/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////



/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
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
	string listOfRental[20];
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
	//////////////////--Setter--//////////////
	void setNext(customer *next) { this->next = next; }
	void setID(string id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAddr(string addr) { this->addr = addr; }
	void setCtmType(ctmTypeEnum ctmType) { this->ctmType = ctmType; }
	void setPhone(string phone) { this->phone = phone; }
	////////////////--Processing Item--/////////////////////////
	void addItem(string);
	void printCtmRental();
	////////////////--VIRYUAL
	virtual int getSuccessReturn() = 0;
	virtual void successReturn() = 0;
	virtual int getMaxVid() = 0;
};
class guest : public customer {
protected:
	int maxVid;
	int successReturnNumb;
public:
	guest(); //by default
	guest(string, string, string, string, ctmTypeEnum); //parameterized
	guest(const guest&);//copy
	~guest();
	int getMaxVid() { return this->maxVid; }
	void successReturn() { this->successReturnNumb++; }
	int getSuccessReturn() { return this->successReturnNumb; }
};

class regular : public customer {
protected:
	int successReturnNumb;
public:
	regular(); //by default
	regular(string, string, string, string, ctmTypeEnum); //parameterized
	regular(const regular&);//copy
	~regular();
	int getMaxVid() { return 1000; }
	void successReturn() { this->successReturnNumb++; }
	int getSuccessReturn() { return this->successReturnNumb; }
};

class vip : public customer {
protected:
	int rewardPoint;
public:
	vip(); //by default
	vip(string, string, string, string, ctmTypeEnum); //parameterized
	vip(const vip&);//copy
	~vip();
	int getMaxVid() { return 1000; }
	void successReturn() { this->rewardPoint = this->rewardPoint + 10; }
	int getSuccessReturn() { return this->rewardPoint; }
};