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
item::item(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, int rentFeeS, bool isAvailableS, item *nextS) { //parameterized
	id = idS;
	title = titleS;
	rentalType = rentalTypeS;
	loanStatus = loanStatusS;
	numOfCopy = numOfCopyS;
	rentFee = rentFeeS;
	isAvailable = isAvailableS;
	next = nextS;
}
item::item(const item& Obj) {//copy
	id = Obj.id;
	title = Obj.title;
	rentalType = Obj.rentalType;
	loanStatus = Obj.loanStatus;
	numOfCopy = Obj.numOfCopy;
	rentFee = Obj.rentFee;
	isAvailable = Obj.isAvailable;
	next = Obj.next;
}
item::~item(void) { delete next; }
/////////////////////////--ITEMS--//////////////////////////
/////////////////////////--RECORD--//////////////////////////
record::record() : item::item() {//By default
	genreType = ACTION;
}
record::record(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, int rentFeeS, bool isAvailableS, item *nextS, genreTypeEnum genreTypeS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS, nextS) {
	genreType = genreTypeS;
}
record::record(const record& Obj) //Copy
	: item::item(Obj) {
	genreType = Obj.genreType;
}
record::~record(void) { delete next; }
/////////////////////////--RECORD--//////////////////////////
/////////////////////////--DVD--//////////////////////////
dvd::dvd() : item::item() {//By default
	genreType = ACTION;
}
dvd::dvd(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, int rentFeeS, bool isAvailableS, item *nextS, genreTypeEnum genreTypeS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS, nextS) {
	genreType = genreTypeS;
}
dvd::dvd(const dvd& Obj) //Copy
	: item::item(Obj) {
	genreType = Obj.genreType;
}
dvd::~dvd(void) { delete next; }
/////////////////////////--DVD--//////////////////////////
/////////////////////////--GAME--//////////////////////////
game::game() : item::item() {}//By default
game::game(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, int rentFeeS, bool isAvailableS, item *nextS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS, isAvailableS, nextS) {}
game::game(const game& Obj) //Copy
	: item::item(Obj) {}
game::~game(void) { delete next; }
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
customer::customer(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS, customer* nextS) { //parameterized
	id = idS;
	name = nameS;
	addr = addrS;
	ctmType = ctmTypeS;
	phone = phoneS;
	listOfRental = listOfRentalS;
	next = nextS;
}
customer::customer(const customer& Obj) {//copy
	id = Obj.id;
	name = Obj.name;
	addr = Obj.addr;
	ctmType = Obj.ctmType;
	phone = Obj.phone;
	listOfRental = Obj.listOfRental;
	next = Obj.next;
}
customer::~customer() { delete next; delete listOfRental; }
/////////////////////////--Guest--//////////////////////////
guest::guest() : customer::customer() {} //by default
guest::guest(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS, customer* nextS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS, nextS) {
	this->maxVid = 2;
	this->successReturn = 0;
}
guest::guest(const guest& Obj)//copy
	: customer::customer(Obj) {}
guest::~guest(void) {}
/////////////////////////--Guest--//////////////////////////
/////////////////////////--Regular--//////////////////////////
regular::regular() : customer::customer() {} //by default
regular::regular(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS, customer* nextS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS, nextS) {
	this->successReturn = 0;
}
regular::regular(const regular& Obj)//copy
	: customer::customer(Obj) {}
regular::~regular(void) {}
/////////////////////////--Regular--//////////////////////////
/////////////////////////--VIP--//////////////////////////
vip::vip() : customer::customer() {} //by default
vip::vip(string idS, string nameS, string addrS, ctmTypeEnum ctmTypeS, string phoneS, string* listOfRentalS, customer* nextS) //parameterized
	: customer::customer(idS, nameS, addrS, ctmTypeS, phoneS, listOfRentalS, nextS) {
	this->rewardPoint = 0;
}
vip::vip(const vip& Obj)//copy
	: customer::customer(Obj) {}
vip::~vip(void) {}
/////////////////////////--VIP--//////////////////////////
/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
