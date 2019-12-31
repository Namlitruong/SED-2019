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

// Util funcs


// Pre-defined
char* SpaceEliminate(char*);
bool CheckExit(int);

//Main program
int main(int argc, char* argv[]) {

	if(CheckExit(argc)){ return 0; }	
	cout << argv[1];
	
	SplitEqTerm(
		SpaceEliminate(argv[1])
	);

}

char* SplitEqTerm(char* iEqtn){
	//TODO Split based on delimeter "+" or "-"
	return iEqtn;
}
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
