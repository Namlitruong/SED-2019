//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Asignment 2 - A VIDEO STORE	
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################
#include "pch.h"
#include "IC.h"

/////////////////////////////////////////////////////////////--Class Declare--/////////////////////////////////////////////////////////////////////////
item::item() {//by Defautl
	id = "none";
	title = "none";
	rentalType = RECORD;
	loanStatus = 1;
	numOfCopy = 1;
	rentFee = 0;
	isAvailable = 1; //borrowed(0) or available(1)
	next = NULL;
}
item::item(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS, bool isAvailableS) { //parameterized
	id = idS;
	title = titleS;
	rentalType = rentalTypeS;
	loanStatus = loanStatusS;
	numOfCopy = numOfCopyS;
	rentFee = rentFeeS;
	isAvailable = isAvailableS;
	next = NULL;
}
item::item(const item& Obj) {//copy
	id = Obj.id;
	title = Obj.title;
	rentalType = Obj.rentalType;
	loanStatus = Obj.loanStatus;
	numOfCopy = Obj.numOfCopy;
	rentFee = Obj.rentFee;
	isAvailable = Obj.isAvailable;
	next = NULL;
}
item::~item(void) { };
/////////////////////////--ITEMS--//////////////////////////
/////////////////////////--RECORD--//////////////////////////
record::record() : item::item() {//By default
	genreType = ACTION;
}
record::record(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS, bool isAvailableS, genreTypeEnum genreTypeS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS) {
	genreType = genreTypeS;
}
record::record(const record& Obj) //Copy
	: item::item(Obj) {
	genreType = Obj.genreType;
}
record::~record(void) {}
/////////////////////////--RECORD--//////////////////////////
/////////////////////////--DVD--//////////////////////////
dvd::dvd() : item::item() {//By default
	genreType = ACTION;
}
dvd::dvd(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS, bool isAvailableS, genreTypeEnum genreTypeS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS) {
	genreType = genreTypeS;
}
dvd::dvd(const dvd& Obj) //Copy
	: item::item(Obj) {
	genreType = Obj.genreType;
}
dvd::~dvd(void) {}
/////////////////////////--DVD--//////////////////////////
/////////////////////////--GAME--//////////////////////////
game::game() : item::item() {}//By default
game::game(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS, bool isAvailableS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS) {}
game::game(const game& Obj) //Copy
	: item::item(Obj) {}
game::~game(void) {}
/////////////////////////--GAME--//////////////////////////
/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////
/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
customer::customer() {//by Defautl
	id = "";
	name = "";
	addr = "";
	ctmType = GUEST;
	phone = "";
	listOfRental = NULL;
	next = NULL;
}
customer::customer(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS) { //parameterized
	id = idS;
	name = nameS;
	addr = addrS;
	ctmType = ctmTypeS;
	phone = phoneS;
	listOfRental = listOfRentalS;
}
customer::customer(const customer& Obj) {//copy
	id = Obj.id;
	name = Obj.name;
	addr = Obj.addr;
	ctmType = Obj.ctmType;
	phone = Obj.phone;
	listOfRental = Obj.listOfRental;
}
customer::~customer() { delete next; delete listOfRental; }
/////////////////////////--Guest--//////////////////////////
guest::guest() : customer::customer() {} //by default
guest::guest(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS) {
	this->maxVid = 2;
	this->successReturn = 0;
}
guest::guest(const guest& Obj)//copy
	: customer::customer(Obj) {}
guest::~guest(void) {}
/////////////////////////--Guest--//////////////////////////
/////////////////////////--Regular--//////////////////////////
regular::regular() : customer::customer() {} //by default
regular::regular(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS) {
	this->successReturn = 0;
}
regular::regular(const regular& Obj)//copy
	: customer::customer(Obj) {}
regular::~regular(void) {}
/////////////////////////--Regular--//////////////////////////
/////////////////////////--VIP--//////////////////////////
vip::vip() : customer::customer() {} //by default
vip::vip(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS) {
	this->rewardPoint = 0;
}
vip::vip(const vip& Obj)//copy
	: customer::customer(Obj) {}
vip::~vip(void) {}
/////////////////////////--VIP--//////////////////////////
/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
