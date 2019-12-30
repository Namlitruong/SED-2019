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
#include "DB.h"

using namespace std;

string genItemID(ItemList* ItsLst, const char* year) {
	char ID[10] = "I000-";
	ID[5] = *(year + 0);
	ID[6] = *(year + 1);
	ID[7] = *(year + 2);
	ID[8] = *(year + 3);
	char tempID[4];
	srand(ItsLst->size());
	item *Its = NULL;
	int range = 999 - 0 + 1;
	bool flag = false;

	while (!flag) {
		int num = rand() % range + 0;
		cout << "num in int: " << num << endl;
		_itoa_s(num, tempID, 10);
		cout << "Length: " << strlen(tempID) << endl;
		switch (strlen(tempID)) {
		case 1:
			ID[3] = tempID[0];
			break;
		case 2:
			ID[2] = tempID[0];
			ID[3] = tempID[1];
			break;
		default:
			ID[1] = tempID[0];
			ID[2] = tempID[1];
			ID[3] = tempID[2];
			break;
		}
		Its = ItsLst->searchItemByID(ID);
		if (Its == NULL) flag = true;
	}
	cout << ID << " can be used for new item" << endl;
	return ID;
}

string genCtmID(CtmList* CtmLst) {
	char ID[5] = "C000";
	char tempID[4];
	srand(CtmLst->size());
	customer *Ctm = NULL;
	int range = 999 - 0 + 1;
	bool flag = false;

	while (!flag) {
		int num = rand() % range + 0;
		_itoa_s(num, tempID, 10);
		switch (strlen(tempID)) {
		case 1:
			ID[3] = tempID[0];
			break;
		case 2:
			ID[2] = tempID[0];
			ID[3] = tempID[1];
			break;
		default:
			ID[1] = tempID[0];
			ID[2] = tempID[1];
			ID[3] = tempID[2];
			break;
		}
		Ctm = CtmLst->searchCtmID(ID);
		if (Ctm == NULL) flag = true;
	}
	cout << ID << " can be used for new customer" << endl;
	return ID;
}

void SearchItemCtmr(CtmList* CustomerLst, ItemList* ItemLst) {
	string select;
	string tempCtm;
	string tempItem;
	customer* rentCtm = NULL;
	item* rentItem = NULL;
	bool flag = false;
	while (!flag) {
		cout << "\nEnter an option below." << endl;
		cout << "1. Search Customers" << endl;
		cout << "2. Search Items" << endl;
		cout << "3. Exit Searching" << endl;
		getline(cin, select);
		switch (atoi(select.c_str()))
		{
		case 1:
			cout << "Search Customer. Please enter customer ID or name: ";
			getline(cin, tempCtm);
			rentCtm = CustomerLst->searchCtmName(tempCtm);
			if (rentCtm == NULL) {
				cout << "Find with ID customer. " << endl;
				rentCtm = CustomerLst->searchCtmID(tempCtm);
			};
			break;
		case 2:
			cout << "Search Item. Please enter Item ID or title: ";
			getline(cin, tempItem);
			rentItem = ItemLst->searchItemByTitle(tempItem);
			if (rentItem == NULL) {
				cout << "Find with ID Item. " << endl;
				rentItem = ItemLst->searchItemByID(tempItem);
			};
			break;
		default:
			flag = true;
			break;
		}

	}
}

void ModifyItem(ItemList* ItemLst) {
	string select, temp;
	string year, title, rentalType, genType, numbOfCopy, rentFee;
	bool loanStatus;
	bool flag = false;
	item * rentIts = NULL;

	cout << "\nEnter an option below." << endl;
	cout << "1. New item" << endl;
	cout << "2. Update item information" << endl;
	cout << "3. Remove item" << endl;
	cout << "Exit." << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		cout << "1. New Item" << endl;
		cout << "Enter Item Title: "; getline(cin, title);
		cout << "Enter Item publised year: "; getline(cin, year);
		//rental type
		while (!flag) {
			cout << "Select rental Type:" << endl;
			cout << "1. RECORD" << endl;
			cout << "2. DVD" << endl;
			cout << "3. GAME" << endl;
			getline(cin, select);
			switch (atoi(select.c_str())) {
			case 1: rentalType = "Record"; flag = true; break;
			case 2:	rentalType = "DVD"; flag = true; break;
			case 3:	rentalType = "Game"; flag = true; break;
			default:
				cout << "Enter rental type again !!!";
				flag = false;
				break;
			}
		}
		flag = false;
		//genre type
		if (rentalType != "Game") {
			while (!flag) {
				cout << "Select genre Type:" << endl;
				cout << "1. ACTION" << endl;
				cout << "2. HORROR" << endl;
				cout << "3. DRAMA" << endl;
				cout << "4. COMEDY" << endl;
				getline(cin, select);
				switch (atoi(select.c_str())) {
				case 1: genType = "Action"; flag = true; break;
				case 2:	genType = "Horror"; flag = true; break;
				case 3:	genType = "Drama"; flag = true; break;
				case 4:	genType = "Comedy"; flag = true; break;
				default:
					cout << "Enter genre type again !!!";
					flag = false;
					break;
				}
			}
		}
		flag = false;
		//Loan type
		while (!flag) {
			cout << "Select loan type:" << endl;
			cout << "1. 1-week loan" << endl;
			cout << "2. 2-day loan" << endl;
			getline(cin, select);
			switch (atoi(select.c_str())) {
			case 1: loanStatus = true; flag = true; break;
			case 2:	loanStatus = false; flag = true; break;
			default:
				cout << "Enter loan type again !!!";
				flag = false;
				break;
			}
		}
		flag = false;
		cout << "Enter Item Number of Copy: "; getline(cin, numbOfCopy);
		cout << "Enter Item Rent Fee: "; getline(cin, rentFee);

		if (rentalType != "Game") ItemLst->appendTail(genItemID(ItemLst, year.c_str()), title, rentalTypeUtil(rentalType), loanStatus, atoi(numbOfCopy.c_str()), atof(rentFee.c_str()));
		else
			ItemLst->appendTail(genItemID(ItemLst, year.c_str()), title, rentalTypeUtil(rentalType), loanStatus, atoi(numbOfCopy.c_str()), atof(rentFee.c_str()), genreTypeUtil(genType));
		break;
	case 2:
		cout << "2. Update item information" << endl;
		cout << "Enter Item ID: ";
		getline(cin, temp);
		rentIts = ItemLst->searchItemByID(temp);
		if (rentIts == NULL) break;
		while (!flag) {
			cout << "Select information that want to change (update):" << endl;
			cout << "1. Item Title" << endl;
			cout << "2. Rental Type" << endl;
			cout << "3. Loan Type" << endl;
			cout << "4. Number Of Copy" << endl;
			cout << "5. Rent Fee" << endl;
			cout << "6. Genre Type" << endl;
			cout << "7. Exit" << endl;
			getline(cin, select);
			switch (atoi(select.c_str())) {
			case 1:
				cout << "Enter updated item title: ";
				getline(cin, title);
				rentIts->setTitle(title);
				break;
			case 2:
				while (!flag) {
					cout << "Select rental Type:" << endl;
					cout << "1. RECORD" << endl;
					cout << "2. DVD" << endl;
					cout << "3. GAME" << endl;
					getline(cin, select);
					switch (atoi(select.c_str())) {
					case 1: rentalType = "Record"; flag = true; break;
					case 2:	rentalType = "DVD"; flag = true; break;
					case 3:	rentalType = "Game"; flag = true; break;
					default:
						cout << "Enter rental type again !!!";
						flag = false;
						break;
					}
				}
				flag = false;
				rentIts->setRentalType(rentalTypeUtil(rentalType));
				break;
			case 3:
				while (!flag) {
					cout << "Select loan type:" << endl;
					cout << "1. 1-week loan" << endl;
					cout << "2. 2-day loan" << endl;
					getline(cin, select);
					switch (atoi(select.c_str())) {
					case 1: loanStatus = true; flag = true; break;
					case 2:	loanStatus = false; flag = true; break;
					default:
						cout << "Enter loan type again !!!";
						flag = false;
						break;
					}
				}
				flag = false;
				rentIts->setLoanStatus(loanStatus);
				break;
			case 4:
				cout << "Enter updated Item Number of Copy: ";
				getline(cin, numbOfCopy);
				rentIts->setNumOfCopy(atoi(numbOfCopy.c_str()));
				break;
			case 5:
				cout << "Enter updated Item Rent Fee: ";
				getline(cin, rentFee);
				rentIts->setRentFee(atof(rentFee.c_str()));
				break;
			case 6:
				if (rentalType == "Game") break;
				while (!flag) {
					cout << "Select genre Type:" << endl;
					cout << "1. ACTION" << endl;
					cout << "2. HORROR" << endl;
					cout << "3. DRAMA" << endl;
					cout << "4. COMEDY" << endl;
					getline(cin, select);
					switch (atoi(select.c_str())) {
					case 1: genType = "Action"; flag = true; break;
					case 2:	genType = "Horror"; flag = true; break;
					case 3:	genType = "Drama"; flag = true; break;
					case 4:	genType = "Comedy"; flag = true; break;
					default:
						cout << "Enter genre type again !!!";
						flag = false;
						break;
					}
				}
				static_cast<record*>(rentIts)->setGenreType(genreTypeUtil(genType));
				flag = false;
				break;
			default:
				flag = true;
				break;
			}
		}
		break;
	case 3:
		cout << "3. Remove item" << endl;
		cout << "Enter Item ID: ";
		getline(cin, temp);
		rentIts = ItemLst->searchItemByID(temp);
		if (rentIts == NULL) break;
		ItemLst->removeItemNode(rentIts);
		break;
	default: break;
	}
}

void ModifyCtmr(CtmList* CustomerLst) {
	string select, tempCtm;
	string id, name, addr, phone, ctmType;
	bool flag = false;
	customer * rentCtm = NULL;
	cout << "\nEnter an option below." << endl;
	cout << "1. New customers" << endl;
	cout << "2. Update customer information" << endl;
	cout << "Exit." << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		cout << "1. New customers" << endl;
		cout << "Enter customer Name: "; getline(cin, name);
		cout << "Enter customer Address: "; getline(cin, addr);
		cout << "Enter customer Phone: "; getline(cin, phone);
		cout << "Select customer Type:" << endl;
		cout << "1. VIP" << endl;
		cout << "2. REGULAR" << endl;
		cout << "3. GUEST" << endl;
		getline(cin, select);
		switch (atoi(select.c_str())) {
		case 1: ctmType = "VIP"; break;
		case 2:	ctmType = "Regular"; break;
		default: ctmType = "Guest"; break;
		}
		CustomerLst->appendTail(genCtmID(CustomerLst), name, addr, phone, ctmTypeUtil(ctmType));
		break;
	case 2:
		cout << "2. Update customer information" << endl;
		cout << "Enter Customer ID: ";
		getline(cin, tempCtm);
		rentCtm = CustomerLst->searchCtmID(tempCtm);
		if (rentCtm == NULL) break;
		while (!flag) {
			cout << "Select information that want to change (update):" << endl;
			cout << "1. Name" << endl;
			cout << "2. Address" << endl;
			cout << "3. Phone" << endl;
			cout << "4. Exit" << endl;
			getline(cin, select);
			switch (atoi(select.c_str())) {
			case 1:
				cout << "Enter updated customer Name: ";
				getline(cin, name);
				rentCtm->setName(name);
				break;
			case 2:
				cout << "Enter updated customer Address: ";
				getline(cin, addr);
				rentCtm->setAddr(addr);
				break;
			case 3:
				cout << "Enter updated customer Phone: ";
				getline(cin, phone);
				rentCtm->setPhone(phone);
				break;
			default:
				flag = true;
				break;
			}
		}
	default: break;
	}
}

void DisplayOutofStock(ItemList* ItemLst) {
	cout << "//////////////////////---LIST OF OUT OF STOCK ITEMS---////////////////////////" << endl;
	ItemLst->printOosItem();
	cout << "//////////////////////---LIST OF OUT OF STOCK ITEMS---////////////////////////" << endl;
}

void DispGroupCtmr(CtmList* CustomerLst) {
	string select;
	cout << "\nEnter an option below." << endl;
	cout << "1. List of VIP customers" << endl;
	cout << "2. List of Regular customers" << endl;
	cout << "3. List of Guest customers" << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		cout << "List of VIP customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::VIP);
		break;
	case 2:
		cout << "List of Regular customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::REGULAR);
		break;
	default:
		cout << "List of Guest customers" << endl;
		CustomerLst->printListByCtmType(ctmTypeEnum::GUEST);
		break;
	}
}

int renItem(ItemList* ItemLst, CtmList* CustomerLst) {
	string tempItem, tempCtm;
	item * rentIt = NULL;
	customer * rentCtm = NULL;
	cout << "////////////////////---RENTING PROCESS START---////////////////////////" << endl;
	cout << "Enter Item ID: ";
	getline(cin, tempItem);
	rentIt = ItemLst->searchItemByID(tempItem);
	if (rentIt == NULL) return -1;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	if (rentCtm->getCtmType() == GUEST && rentIt->getLoanStatus() == false) {
		cout << "GUEST customer can not borrow 2-day item" << endl;
		return -1;
	}
	if (rentCtm->getCtmType() == GUEST && rentCtm->numOfRental() == 2) {
		cout << "GUEST customer just can rent maximum 2 items" << endl;
		return -1;
	}
	if (rentIt->getNumOfCopy() == 0) {
		cout << "The Item: " << rentIt->getTitle() << " is not available" << endl;
		return -1;
	}
	else {
		rentIt->setNumOfCopy(-1);
		CustomerLst->addCtmItemList(rentCtm, rentIt->getID());
	}
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	ItemLst->searchItemByID(tempItem);
	CustomerLst->searchCtmID(tempCtm);

	if (rentCtm->getCtmType() == VIP) {
		if (rentCtm->getSuccessReturn() == 100)
			cout << "This VIP customer " << rentCtm->getName() << " can rent 1 Item for free." << endl;
	}
	cout << "////////////////////---RENTING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

int returnItem(ItemList* ItemLst, CtmList* CustomerLst) {
	string tempItem, tempCtm;
	item * rentIt = NULL;
	customer * rentCtm = NULL;
	cout << "////////////////////---RETURNING PROCESS START---////////////////////////" << endl;
	cout << "Enter Item ID: ";
	getline(cin, tempItem);
	rentIt = ItemLst->searchItemByID(tempItem);
	if (rentIt == NULL) return -1;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	rentIt->setNumOfCopy(1);
	if (rentCtm->removeItem(rentIt->getID()) == 0) {
		cout << "The customer do not rent this item" << endl;
		return -1;
	}
	else {
		rentCtm->successReturn();
	}
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	ItemLst->searchItemByID(tempItem);
	CustomerLst->searchCtmID(tempCtm);
	if (rentCtm->getCtmType() != VIP)	cout << "Customer " << rentCtm->getName() << " return successfully: " << rentCtm->getSuccessReturn() << " items" << endl;
	else cout << "This VIP customer " << rentCtm->getName() << " return " << rentCtm->getSuccessReturn() / 10 << " successfully." << endl;
	cout << "////////////////////---RETURNING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

int autoPromoteCtmr(CtmList* CustomerLst) {
	customer *current = CustomerLst->getCtmHead();
	while (current != NULL) {
		if (current->getSuccessReturn() == 3) {
			customer *temp = current->getNext();
			promoteCtm(current, CustomerLst);
			current = temp;
		}
		current = current->getNext();
	}
	return 0;
}

int PromoteCtmrByID(CtmList* CustomerLst) {
	string tempCtm;
	customer * rentCtm = NULL;
	cout << "////////////////////---PROMOTING PROCESS START---////////////////////////" << endl;
	cout << "Enter Customer ID: ";
	getline(cin, tempCtm);
	rentCtm = CustomerLst->searchCtmID(tempCtm);
	if (rentCtm == NULL) return -1;
	tempCtm = rentCtm->getID();
	if (promoteCtm(rentCtm, CustomerLst) == -1) return -1;
	cout << "////////////////////---UPDATE STATUS---////////////////////////" << endl;
	CustomerLst->searchCtmID(tempCtm);
	cout << "////////////////////---PROMOTING PROCESS DONE---////////////////////////" << endl;
	return 0;
}

int promoteCtm(customer * rentCtm, CtmList* CustomerLst) {
	string promote;
	switch (rentCtm->getCtmType()) {
	case REGULAR:	promote = "VIP"; break;
	case GUEST:		promote = "Regular"; break;
	default: {
		cout << "Cannot promote VIP" << endl;
		promote = "VIP";
		return -1;
		break;
	}
	}
	CustomerLst->appendHead(rentCtm->getID(),
		rentCtm->getName(),
		rentCtm->getAddr(),
		rentCtm->getPhone(),
		ctmTypeUtil(promote));

	for (int i = 0; i < rentCtm->numOfRental(); i++) {
		CustomerLst->addCtmItemList(CustomerLst->getCtmHead(), *(rentCtm->getListOfRental() + i));
	}
	CustomerLst->removeNode(rentCtm);
	return 0;
}

/*	Function name: CheckExit.
Usage: Check if the input string is Exit or not. If "Exit" is pressed then exit the program and print team information.
Input: pointer to input raw string.
Output: Boolean flag to acknowledge "Exit" have been pressed or not.
*/
bool CheckExit(string optSel_str) {
	if ((optSel_str.compare("Exit") == 0) || optSel_str.compare("exit") == 0) { // Consider both Capital (Exit) and non-capital (exit) of the first character to compare with the input string.
		cout << "ASSIGNMENT 2 - GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
	return 0;
}


int initBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	bool isCtmProfile = false;
	long totalRental = 0;
	ifstream ctmFile("customers.txt");
	ifstream itemFile("items.txt");

	// initialize Customer DB

	if (ctmFile.is_open())
	{
		while (getline(ctmFile, textLine))
		{
			char firstChr = textLine[0];

			// Skip comments
			if (firstChr == (char)commentTag) {
				continue;
			}

			// Detect customer identifier
			if (firstChr == (char)ctmIdentifier) {
				isCtmProfile = true;

				//TODO append to CtmList
				string inputVal[ctmDbInLength];
				const char delimeter = ',';
				int curCtm = 0, idxCtm = 0;

				// String Tokenizer into String Array
				while ((curCtm = textLine.find(delimeter)) != std::string::npos)
				{
					inputVal[idxCtm++] = textLine.substr(0, curCtm);
					textLine.erase(0, curCtm + 1); // Advance next term, +1 for delimeter
					//NOTE curCtm.length() would be redundant, unnecessary
				}
				inputVal[idxCtm] = textLine; // Last term

				// Update Customer Pointer
				ctmPtr->appendHead(inputVal[0], inputVal[1], inputVal[2], inputVal[3], ctmTypeUtil(inputVal[5]));
				//NOTE confirm no. of rentals
				totalRental = atoi(inputVal[4].c_str());
				continue;
			}

			// TODO check error based on totalRental
			if (firstChr == (char)itemIdentifier) {
				if (totalRental >= 0)
				{
					ctmPtr->addCtmItemList(ctmPtr->getCtmHead(), textLine);
					totalRental--;
				}
			}
		}
		ctmFile.close();
	}


	// Now initialize Items DB
	if (itemFile.is_open())
	{
		while (getline(itemFile, textLine))
		{
			char firstChr = textLine[0];

			// Skip comments
			if (firstChr == (char)commentTag) {
				continue;
			}

			// Update Item Database
			if (firstChr == (char)itemIdentifier) {
				string inputVal[itemDbInLength];
				const char delimeter = ',';
				int curItem = 0, idxItem = 0;

				// String Tokenizer into String Array
				while ((curItem = textLine.find(delimeter)) != std::string::npos)
				{
					inputVal[idxItem++] = textLine.substr(0, curItem);
					textLine.erase(0, curItem + 1); // Advance next term, +1 for delimeter
					//NOTE curItem.length() would be redundant, unnecessary
				}
				inputVal[idxItem] = textLine; // Last term

				// Update Customer Pointer
				// (				string id, 
				//				 string title, 
				//  rentalTypeEnum rentalType, 
				//			  bool loanStatus, 
				//				int numOfCopy, 
				//			   double rentFee, 
				//			 bool isAvailable, //TODO redundant, not provided in items.txt
				//	 genreTypeEnum genreType); // DVD || Record Only

				if (inputVal[2] == "DVD" || inputVal[2] == "Record") {
					itemPtr->appendHead(inputVal[0],
						inputVal[1],
						rentalTypeUtil(inputVal[2]),
						rentalPeriodUtil(inputVal[3]),
						atoi(inputVal[4].c_str()),
						std::stod(inputVal[5]),
						genreTypeUtil(inputVal[6].c_str()));
				}
				else if (inputVal[2] == "Game") {
					itemPtr->appendHead(inputVal[0],
						inputVal[1],
						rentalTypeUtil(inputVal[2]),
						rentalPeriodUtil(inputVal[3]),
						atoi(inputVal[4].c_str()),
						std::stod(inputVal[5]));
				}
				else {
					// Redundant
					// Extra error check
				}
				continue;
			}
		}
		itemFile.close();
	}
	// TODO boolean status if necessary
	return -1;
}

int finBaseDb(ItemList* itemPtr, CtmList* ctmPtr) {
	string textLine;
	ofstream ctmFile("customers.txt");
	ofstream itemFile("items.txt");


	// Finalize Customer DB
	if (ctmFile.is_open())
	{
		// IN-DEVELOP
		// Iteratively output to buffer
		customer* currCtm = ctmPtr->getCtmHead();
		ctmFile << "#Final Customer Database updated\n";
		do {
			// TODO arr2str Util function, getAllArr function from Ctm/Item cls
			textLine = currCtm->getID() + ','
				+ currCtm->getName() + ','
				+ currCtm->getAddr() + ','
				+ currCtm->getPhone() + ','
				+ std::to_string(currCtm->numOfRental()) + ','
				+ ctmTypeStr(currCtm->getCtmType());

			//TODO add rental List of each Customer
			textLine += "\n";

			for (int i = 0; i < currCtm->numOfRental(); i++) {
				textLine += *(currCtm->getListOfRental() + i) + "\n";
			};
			if (textLine[textLine.length() - 1] != '\n') {
				textLine += "\n";
			}

			ctmFile << textLine;
		} while ((currCtm = currCtm->getNext()) != NULL);
		ctmFile.close();
	}

	// Now Finalize Items DB
	if (itemFile.is_open())
	{
		// IN-DEVELOP
		// Iteratively output to buffer
		item* currItem = itemPtr->getItemHead();
		itemFile << "#Final Item Database updated\n";
		do {
			// TODO arr2str Util function, getAllArr function from Ctm/Item cls
			textLine = currItem->getID() + ','
				+ currItem->getTitle() + ','
				+ rentalTypeStr(currItem->getRentalType()) + ','
				+ rentalPeriodStr(currItem->getLoanStatus()) + ','
				+ std::to_string(currItem->getNumOfCopy()) + ','
				+ double2str(currItem->getRentFee())
				+ genreTypeStr(currItem);
			// FIXME getGenreType() virtual function returns NONE except 1st iteration

			if (textLine[textLine.length() - 1] != '\n') {
				textLine += "\n";
			}
			itemFile << textLine;
		} while ((currItem = currItem->getNext()) != NULL);
		itemFile.close();
	}

	// TODO boolean status if necessary
	return -1;
}

ctmTypeEnum ctmTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "VIP") == 0)
	{
		return ctmTypeEnum::VIP;
	}
	else if ((strcmp(str2arr(str.c_str()), "Regular")) == 0)
	{
		return ctmTypeEnum::REGULAR;
	}
	else if ((strcmp(str2arr(str.c_str()), "Guest")) == 0)
	{
		return ctmTypeEnum::GUEST;
	}
}

string ctmTypeStr(ctmTypeEnum ctmEnum) {

	switch (ctmEnum)
	{
	case GUEST:
		return "Guest";
	case REGULAR:
		return "Regular";
	case VIP:
		return "VIP";
	default:
		return "";
	}
}

rentalTypeEnum rentalTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "Game") == 0)
	{
		return rentalTypeEnum::GAME;
	}
	else if ((strcmp(str2arr(str.c_str()), "DVD")) == 0)
	{
		return rentalTypeEnum::DVD;
	}
	else if ((strcmp(str2arr(str.c_str()), "Record")) == 0)
	{
		return rentalTypeEnum::RECORD;
	}
}

string rentalTypeStr(rentalTypeEnum rentalEnum) {
	switch (rentalEnum)
	{
	case DVD:
		return "DVD";
	case RECORD:
		return "Record";
	case GAME:
		return "Game";
	default:
		return "";
	}
}

genreTypeEnum genreTypeUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "Action") == 0)
	{
		return genreTypeEnum::ACTION;
	}
	else if ((strcmp(str2arr(str.c_str()), "Comedy")) == 0)
	{
		return genreTypeEnum::COMEDY;
	}
	else if ((strcmp(str2arr(str.c_str()), "Drama")) == 0)
	{
		return genreTypeEnum::DRAMA;
	}
	else if ((strcmp(str2arr(str.c_str()), "Horror")) == 0)
	{
		return genreTypeEnum::HORROR;
	}
}

string genreTypeStr(item* its) {
	switch (its->getRentalType()) {
	case RECORD: {
		switch ((static_cast<record*>(its))->getGenreType()) {
		case ACTION:	return ",Action"; break;
		case HORROR:	return ",Horror"; break;
		case DRAMA:		return ",Drama"; break;
		case COMEDY:	return ",Comedy"; break;
		default: return ""; break;
		}
		break; }
	case DVD: {
		switch ((static_cast<dvd*>(its))->getGenreType()) {
		case ACTION:	return ",Action"; break;
		case HORROR:	return ",Horror"; break;
		case DRAMA:		return ",Drama"; break;
		case COMEDY:	return ",Comedy"; break;
		default: return ""; break;
		}
		break; }
	default: {
		return"";
		break; }
	}
}

bool rentalPeriodUtil(string str) {
	if (strcmp(str2arr(str.c_str()), "1-week") == 0)
	{
		return true;
	}
	else if ((strcmp(str2arr(str.c_str()), "2-day")) == 0)
	{
		return false;
	}
}

string rentalPeriodStr(bool bl) {
	if (bl)
	{
		return "1-week";
	}
	else {
		return "2-day";
	}
}

char* str2arr(string str) {
	char* cTypeStr = new char[str.length() + 1];
	//FIXME swap strcpy_s for Windows supported "safe" String libary
	strcpy_s(cTypeStr, str.length() + 1, str.c_str());
	//strcpy(cTypeStr, str.c_str());
	return cTypeStr;
}

string double2str(double db) {
	char buffer[100];
	sprintf_s(buffer, "%.2f", db);
	std::string str = buffer;
	return str;
}

void printItemList(ItemList* itemPtr) {
	string select;

	cout << "\nEnter an option below." << endl;
	cout << "1. Item list sorted by Title" << endl;
	cout << "2. Item list sorted by ID (Default)" << endl;
	cout << "Exit." << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		itemPtr->prtSortedItemList(byTitle);
	case 2:
		itemPtr->prtSortedItemList(byID);
	default:
		break;
	}
}

void printCtmList(CtmList* ctmPtr) {
	string select;

	cout << "\nEnter an option below." << endl;
	cout << "1. Customer list sorted by Name" << endl;
	cout << "2. Customerlist sorted by ID (Default)" << endl;
	cout << "Exit." << endl;
	getline(cin, select);
	switch (atoi(select.c_str())) {
	case 1:
		ctmPtr->prtSortedCtmList(byName);
	case 2:
		ctmPtr->prtSortedCtmList(byID);
	default:
		break;
	}
}