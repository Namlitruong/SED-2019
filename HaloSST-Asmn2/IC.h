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
	int rentFee;
	bool isAvailable; //borrowed or available
	item *next; // pointer to next
public:
	item();//by Defautl
	item(string, string, rentalTypeEnum, bool, int, int, bool, item*); //parameterized
	item(const item&);//copy
	~item();
	//////////////////--Getter--//////////////
	item* getNext() { return next; }
	string getID() { return this->id; }
	string getTitle() { return this->title; }
	rentalTypeEnum getRentalType() { return this->rentalType; }
	bool getLoanStatus() { return this->loanStatus; }
	int getNumOfCopy() { return this->numOfCopy; }
	int getRentFee() { return this->rentFee; }
	bool getIsAvailable() { return this->isAvailable; }
	//////////////////--Setter--//////////////
	void setID(string id) { this->id = id; }
	void setTitle(string title) { this->title = title; }
	void setRentalType(rentalTypeEnum rentalType) { this->rentalType = rentalType; }
	void setLoanStatus(bool loanType) { this->loanStatus = loanType; }
	void setNumOfCopy(int numOfCopy) { this->numOfCopy = numOfCopy; }
	void setRentFee(int rentFee) { this->rentFee = rentFee; }
	void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
	void setNext(item *next) { this->next = next; }
};

class record : protected item {
protected:
	genreTypeEnum genreType;
public:
	record(); //by default
	record(string, string, rentalTypeEnum, bool, int, int, bool, item*, genreTypeEnum); //parameterized
	record(const record&);//copy
	~record();
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class dvd : protected item {
protected:
	genreTypeEnum genreType;
public:
	dvd(); //By default
	dvd(string, string, rentalTypeEnum, bool, int, int, bool, item*, genreTypeEnum); //parameterized
	dvd(const dvd&);//copy
	~dvd();
	void setGenreType(genreTypeEnum genreType) { this->genreType = genreType; }
	genreTypeEnum getGenreType() { return this->genreType; }
};

class game : protected item {
public:
	game();//By default
	game(string, string, rentalTypeEnum, bool, int, int, bool, item*); //parameterized
	game(const game&);//copy
	~game();
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
	string *listOfRental;
	customer *next; // pointer to next
public:
	customer();//by Defautl
	customer(string, string, string, ctmTypeEnum, string, string*, customer*); //parameterized
	customer(const customer&);//copy
	~customer();
	//////////////////--Getter--//////////////
	customer* getNext() { return next; }
	string getID() { return this->id; }
	string getName() { return this->name; }
	string getAddr() { return this->addr; }
	ctmTypeEnum getCtmType() { return this->ctmType; }
	string getPhone() { return this->phone; }
	//////////////////--Setter--//////////////
	void setNext(customer *next) { this->next = next; }
	void setID(string id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAddr(string addr) { this->addr = addr; }
	void setCtmType(ctmTypeEnum ctmType) { this->ctmType = ctmType; }
	void setPhone(string phone) { this->phone = phone; }
	//////////////////--RentalList--//////////////
	void appendRental(string *);
	void removeRental(string *);
	void printRental();
};
class guest : protected customer {
protected:
	int maxVid;
	int successReturn;
public:
	guest(); //by default
	guest(string, string, string, ctmTypeEnum, string, string*, customer*); //parameterized
	guest(const guest&);//copy
	~guest();
};

class regular : protected customer {
protected:
	int successReturn;
public:
	regular(); //by default
	regular(string, string, string, ctmTypeEnum, string, string*, customer*); //parameterized
	regular(const regular&);//copy
	~regular();
};

class vip : protected customer {
protected:
	int rewardPoint;
public:
	vip(); //by default
	vip(string, string, string, ctmTypeEnum, string, string*, customer*); //parameterized
	vip(const vip&);//copy
	~vip();
};