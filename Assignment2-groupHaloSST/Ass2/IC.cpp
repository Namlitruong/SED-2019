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
//Class Constructor by Defautl
item::item() {
	id = "none";
	title = "none";
	rentalType = RECORD;
	loanStatus = 1;
	numOfCopy = 1;
	rentFee = 0;
	isAvailable = 1; //borrowed(0) or available(1)
	next = NULL;
}
//Class Constructor by parameterized
item::item(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS) { 
	id = idS;
	title = titleS;
	rentalType = rentalTypeS;
	loanStatus = loanStatusS;
	numOfCopy = numOfCopyS;
	rentFee = rentFeeS;
	next = NULL;
}
//Class Constructor by copy
item::item(const item& Obj) {
	id = Obj.id;
	title = Obj.title;
	rentalType = Obj.rentalType;
	loanStatus = Obj.loanStatus;
	numOfCopy = Obj.numOfCopy;
	rentFee = Obj.rentFee;
	next = NULL;
}
//Class Destructor
item::~item(void) { };
/////////////////////////--ITEMS--//////////////////////////
/////////////////////////--RECORD--//////////////////////////
//Class Constructor by Defautl
record::record() : item::item() {
	genreType = ACTION;
}
//Class Constructor by parameterized
record::record(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS, genreTypeEnum genreTypeS)
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS) {
	genreType = genreTypeS;
}
//Class Constructor by Copy
record::record(const record& Obj) 
	: item::item(Obj) {
	genreType = Obj.genreType;
}
//Class Destructor
record::~record(void) {}
/////////////////////////--RECORD--//////////////////////////
/////////////////////////--DVD--////////////////////////////
//Class Constructor by default
dvd::dvd() : item::item() {
	genreType = ACTION;
}
//Class Constructor by parameterized
dvd::dvd(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS , genreTypeEnum genreTypeS)
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS) {
	genreType = genreTypeS;
}
//Class Constructor by Copy
dvd::dvd(const dvd& Obj) 
	: item::item(Obj) {
	genreType = Obj.genreType;
}
//Class Destructor
dvd::~dvd(void) {}
/////////////////////////--DVD--//////////////////////////
/////////////////////////--GAME--//////////////////////////
//Class Constructor by default
game::game() : item::item() {}
//Class Constructor by parameterized
game::game(string idS, string titleS, rentalTypeEnum rentalTypeS, bool loanStatusS, int numOfCopyS, double rentFeeS) //parameterized
	: item::item(idS, titleS, rentalTypeS, loanStatusS, numOfCopyS, rentFeeS) {}
//Class Constructor by Copy
game::game(const game& Obj) 
	: item::item(Obj) {}
//Class Destructor
game::~game(void) {}
/////////////////////////--GAME--//////////////////////////
/////////////////////////---------------------------------------------------------------------ITEMS SECTION-------------------------------------------------------------------//////////////////////////



/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////
//Constructor
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
//Destructor
customer::~customer() { delete next; /*delete listOfRental;*/ }

/*	Function name: numOfRental.
Usage: To return the number of rental of a customer
Input:	None -- inside the class
Output: Return number of rental
*/
int customer::numOfRental() {
	int i;
	for (i = 0; !this->listOfRental[i].empty(); i++) {}
	return i;
}

/*	Function name: addItem.
Usage: Add item into listOfRental
Input:	ID of an item
Output: NULL -- void function
*/
void customer::addItem(string item) {
	this->listOfRental[this->numOfRental()] = item;
}

/*	Function name: removeItem.
Usage: Remove item into listOfRental
Input:	ID of an item
Output: NULL -- void function
*/
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

/*	Function name: printCtmRental.
Usage: Print all items of listOfRental
Input:	None -- inside the class
Output: NULL -- void function
*/
void customer::printCtmRental() {
	cout << "Rental list of customer: "<< this->getName() <<" rent "<< this->numOfRental() <<" items"<< endl;
	for (int i = 0; i < this->numOfRental(); i++) {
		cout << this->listOfRental[i] << endl;
	}
}
/////////////////////////--Guest--//////////////////////////
//Constructor
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
//Destructor
guest::~guest(void) {}
/////////////////////////--Guest--//////////////////////////
/////////////////////////--Regular--//////////////////////////
//Constructor
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
//Destructor
regular::~regular(void) {}
/////////////////////////--Regular--//////////////////////////
/////////////////////////--VIP--//////////////////////////
//Constructor
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
//Destructor
vip::~vip(void) {}

/*	Function name: successReturn.
Usage: Adding reward points for VIP
Input:	None -- inside the class
Output: NULL -- void function
*/
void vip::successReturn() {
	this->rewardPoint = this->rewardPoint + 10;
	if (this->rewardPoint == 100) this->rewardPoint = 0;
}
// Getter of reward points
int vip::getSuccessReturn() {return this->rewardPoint;}
/////////////////////////--VIP--//////////////////////////
/////////////////////////--------------------------------------------------------------------CUSTOMER SECTION-------------------------------------------------------------------//////////////////////////

