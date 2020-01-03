//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Lab 2 - Differentiator Program		
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

#include "pch.h"
#include <iostream>	
#define ASCIIspace 32
#define EQLIM 100 // Equation limit length
#define INTUPPERLIMIT 32767
#define INTLOWERLIMIT -32767

using namespace std;

// Define Enum
typedef enum calculationType {
	NONE = -1,
	Const = 1,		// 𝑎
	Linear = 2,		// 𝑎 ∗ 𝑥 
	Power = 3,		// 𝑎 ∗ 𝑥^(𝑏) 
	Log10 = 4,		// 𝑎 ∗ 𝑙𝑜𝑔10( 𝑥) 
	Log10Const = 5,	// 𝑎 ∗ 𝑙𝑜𝑔10(𝑏 ∗ 𝑥)
	LogE = 6,		// 𝑎 ∗ 𝑙𝑜𝑔𝑒(𝑥) 
	LogEConst = 7,	// 𝑎 ∗ 𝑙𝑜𝑔𝑒(𝑏 ∗ 𝑥)
	Exp = 8,		// 𝑎 ∗ 𝑒^(𝑥)
	ExpConst = 9,	// 𝑎 ∗ 𝑒^(𝑏 ∗ 𝑥) 
	Sin = 10,		// 𝑎 ∗ sin(𝑥) 
	SinConst = 11,	// 𝑎 ∗ sin(𝑏 ∗ 𝑥)
	CoSin = 12,		// 𝑎 ∗ cos(𝑥) 
	CoSinConst = 13 // 𝑎 ∗ cos(𝑏 ∗ 𝑥)
} calcType;

//Global variables
char iString[1000];
int indpX = 0, dpA = 0, dpB = 0;

// Function prototype
char* SplitEqTerm(char*);
char* calcAllTerms(char*);
char* calcTypeId(char*);
bool isLog(string);
bool isTrig(string);
bool isExp(string);
string getAllNum(string str);

// Pre-defined
// TODO: Adapt to new Equation format
char* SpaceEliminate(char*); 
bool CheckExit(int); // Checked

//Main program
int main(int argc, char* argv[]) {

	if(CheckExit(argc)){ return 0; }	
	cout << argv[1];

	// TODO Define Linked List & replace argv[1] as input?
	// Use return -1 as boolean for each stage?

	// TODO re-factor Procedural to OOP
	// Traverse through List & calculate all
	calcAllTerms(
		// Identify Calcultion Type via Util funcs
		// Update Linked List->calcType 
		calcTypeId(
			// Split terms into Linked List
			// constA, constB, indp varX, operator Opt, index Idx
			SplitEqTerm(
			// Raw Equation without space
			SpaceEliminate(argv[1])
	)));


	return 0;
}

// Main Functions
char* calcAllTerms(char* iEqtn){

	return iEqtn;
}

char* calcTypeId(char* iEqtn){
	//TODO input argument *EqtnList

	//TODO EqtnList::Node->attributes
	calcType tp;
	string cnstA, cnstB;

	// IN-DEVELOP
	string termsArr[EQLIM] = { "4","2*x","x*2","3*4x^8" };

	//FIXME While current = current->getNext() != NULL
	for each (string term in termsArr)
	{
		// IN-DEVELOP
		term = "24x";

		/* Logarithmic Equation
			Log10 = 4,		// 𝑎 ∗ 𝑙𝑜𝑔10( 𝑥) 
			Log10Const = 5,	// 𝑎 ∗ 𝑙𝑜𝑔10(𝑏 ∗ 𝑥)
			LogE = 6,		// 𝑎 ∗ 𝑙𝑜𝑔𝑒(𝑥) 
			LogEConst = 7,	// 𝑎 ∗ 𝑙𝑜𝑔𝑒(𝑏 ∗ 𝑥)
		*/
		if (isLog(term))
		{
			tp = Const;
		}

		/* Exponential Equation
			Exp = 8,		// 𝑎 ∗ 𝑒^(𝑥)
			ExpConst = 9,	// 𝑎 ∗ 𝑒^(𝑏 ∗ 𝑥) 
		*/
		else if ( isExp(term) ) {
			tp = Linear;
			cnstA = term[0];
			cnstB = term[0];
		}

		/* Trigonometric Equation
			Sin = 10,		// 𝑎 ∗ sin(𝑥)
			SinConst = 11,	// 𝑎 ∗ sin(𝑏 ∗ 𝑥)
			CoSin = 12,		// 𝑎 ∗ cos(𝑥)
			CoSinConst = 13 // 𝑎 ∗ cos(𝑏 ∗ 𝑥)
		*/
		else if (isTrig(term)) {
			tp = Linear;
			cnstA = term[0];
			cnstB = term[0];
		}

		/*
			NONE = -1		// Unsupported
			Const = 1,		// 𝑎
			Linear = 2,		// 𝑎 ∗ 𝑥 
			Power = 3,		// 𝑎 ∗ 𝑥^(𝑏) 
		*/
		else {
			// Unsupported
		}


		// TODO Increment EqtnList::Node->next()
	}

	return iEqtn;
}

char* SplitEqTerm(char* iEqtn){
	string iEqtnStr = iEqtn;
	int cursor = 0, idxCtm = 0;

	// Main Class EqtnList
	string termsArr[EQLIM];

	// EqtnList::Node->attributes
	string term;
	bool isSubtract = false;


	//TODO Split based on delimeter "+" or "-"
	while (( (cursor = iEqtnStr.find("+")) != std::string::npos) 
		  || (cursor = iEqtnStr.find("-")) != std::string::npos) 
	{

		// TODO any other attribute for subtraction ?
		iEqtnStr[cursor] == '-' ? (isSubtract = true) : (isSubtract = false);

		termsArr[idxCtm++] = iEqtnStr.substr(0, cursor);
		iEqtnStr.erase(0, cursor + 1); // Advance next term, +1 for delimeter
	}
		termsArr[idxCtm] = iEqtnStr; // Last term

	//TODO return EqtnList
	return iEqtn;
}

// Util Functions
//FIXME Pass arguments by Reference as EqtnList&
bool isLog(string str) {
}

bool isExp(string str) {


	return false;
}

bool isTrig(string str) {
	return false;
}

string getAllNum(string str) {


	return str;
}

// Pre-defined Functions
/*	Function name: SpaceEliminate.
	Usage: Using to eleiminate spaces before and after the input expression.
	Input: Raw input argument string.
	Output: New expression without spaces at the front and from the back.
*/
char* SpaceEliminate(char* iString) {
	int StartIndex = 0;
	int EndIndex = strlen(iString);
	char* Data = &(*iString);

	for (int i = 1; iString[i - 1] == ' '; i++) StartIndex = i;								// Check space from the front 
	for (int i = strlen(iString) - 1; iString[i] == ' '; i--) EndIndex = i - 1;				// Check space from the back  
	for (int i = 0; i <= (EndIndex - StartIndex); i++) Data[i] = iString[StartIndex + i];	// Take out the expression from 'Start Index' to 'End Index'
	Data[(EndIndex - StartIndex) + 1] = '\0';												// Add NULL at the end of the new string
	return Data;
}

/*	Function name: CheckExit.
	Usage: Check if the input string is Exit or not. If "Exit" is pressed then exit the program and print team information.
	Input: pointer to input raw string.
	Output: Boolean flag to acknowledge "Exit" have been pressed or not.
*/
bool CheckExit(int argTotal) {
	if (argTotal <= 1) { // argv[0] is program name
		cout << "LABORATORY GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
	else if (argTotal >= 3){ // 1 program name + 2 arguments
		cout << "Invalid number of User Input Arguments" << endl;
		return 1;
	}
	return 0;
}
