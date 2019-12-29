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
	next = NULL;
}
customer::customer(string idS, string nameS, string addrS, string phoneS, ctmTypeEnum ctmTypeS) { //parameterized
	id = idS;
	name = nameS;
	addr = addrS;
	ctmType = ctmTypeS;
	phone = phoneS;
}
customer::customer(const customer& Obj) {//copy
	id = Obj.id;
	name = Obj.name;
	addr = Obj.addr;
	ctmType = Obj.ctmType;
	phone = Obj.phone;
}
customer::~customer() { delete next; /*delete listOfRental;*/ }

int customer::numOfRental() {
	int i;
	for (i = 0; !this->listOfRental[i].empty(); i++) {}
	return i;
}

void customer::addItem(string item) {
	this->listOfRental[this->numOfRental()] = item;
}

/*char* str2arr1(string str) {
	char* cTypeStr = new char[str.length() + 1];
	strcpy_s(cTypeStr, str.length() + 1, str.c_str());
	return cTypeStr;
}*/

int customer::removeItem(string item) {
	int flag = 0;
	for (int i = 0; i < this->numOfRental(); i++) {
		if (strcmp(this->listOfRental[i].c_str(), item.c_str()) == 0) {
			for (int j = i; j < this->numOfRental() - 1; j++) {
				this->listOfRental[j] = this->listOfRental[j + 1];
			}
			flag++;
			break;
		}
	}
	this->listOfRental[this->numOfRental()-1] = "";
	if (flag == 0) return 0;
	else return 1;
}

void customer::printCtmRental() {
	cout << "Rental list of customer: "<< this->getName() <<" rent "<< this->numOfRental() <<" items"<< endl;
	for (int i = 0; i < this->numOfRental(); i++) {
		cout << this->listOfRental[i] << endl;
	}
}
/////////////////////////--Guest--//////////////////////////
guest::guest() : customer::customer() { //by default
	maxVid = 2;
	successReturnNumb = 0;
}
guest::guest(string idS, string nameS, string addrS, string phoneS, ctmTypeEnum ctmTypeS) //parameterized
	: customer::customer(idS, nameS, addrS, phoneS, ctmTypeS) {
	maxVid = 2;
	successReturnNumb = 0;
}
guest::guest(const guest& Obj)//copy
	: customer::customer(Obj) {
	maxVid = 2;
	successReturnNumb = 0;
}
guest::~guest(void) {}
/////////////////////////--Guest--//////////////////////////
/////////////////////////--Regular--//////////////////////////
regular::regular() : customer::customer() { //by default
	successReturnNumb = 0;
}
regular::regular(string idS, string nameS, string addrS, string phoneS, ctmTypeEnum ctmTypeS) //parameterized
	: customer::customer(idS, nameS, addrS, phoneS, ctmTypeS) {
	successReturnNumb = 0;
}
regular::regular(const regular& Obj)//copy
	: customer::customer(Obj) {
	successReturnNumb = 0;
}
regular::~regular(void) {}
/////////////////////////--Regular--//////////////////////////
/////////////////////////--VIP--//////////////////////////
vip::vip() : customer::customer() { //by default
	rewardPoint = 0;
}
vip::vip(string idS, string nameS, string addrS, string phoneS, ctmTypeEnum ctmTypeS) //parameterized
	: customer::customer(idS, nameS, addrS, phoneS, ctmTypeS) {
	rewardPoint = 0;
}
vip::vip(const vip& Obj)//copy
	: customer::customer(Obj) {
	rewardPoint = 0;
}
vip::~vip(void) {}
/////////////////////////--VIP--//////////////////////////
/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////

