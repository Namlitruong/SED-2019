//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Lab 1 - Simple 2-Argument Calculator		
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

#include "pch.h"
#include <iostream>
#define ASCIIspace 32
#define INPUTLIMIT 100
#define INTUPPERLIMIT 32767
#define INTLOWERLIMIT -32767

using namespace std;

//Global variables
char iString[1000];
int arg1;
int arg2;
char op;

// Function prototype
char* SpaceEliminate(char*);					
int ExtractInput(char*, int&, int&, char&);		
bool CheckRange(char*, int&);						
bool checkValidNumber(char*);					
int DoCalculate(int&, int&, char&);				
bool ErrMess(int);								
bool CheckExit(char *);							
void PrintResult (int&, int&, char&, int);		

//Main program
int main() {
	while (1) {
		cout << "___________________________________________________________\n";
		cout << "\n#NOTE: Input String cannot larger than 100 character." << endl;					//Acknowledge user the input constraint
		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 1000);																	//Declare and set the input lenght of iString is 1000, but just allow user to input 100 characters.
																									//This action to prevent buffer overflow which will cause fatal error and exit the program immediately.
		if (strlen(iString) < INPUTLIMIT) {
			if (CheckExit(iString)) return 0;														//If the "Exit" is recognised, return 0 to exit the program and print team information.
			if (ErrMess(ExtractInput(SpaceEliminate(iString), arg1, arg2, op))) 
				PrintResult(arg1, arg2, op, DoCalculate(arg1, arg2, op));							//If no errors are detected, the result of the calculation will display.
		}else cout << "ERROR: Too many characters. Please input the expression again !!!" << endl;	//Print error message if too many characters have been input
	}
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
/*	Function name: ExtractInput.
	Usage: Extract correct form of data from the input string to arg1, arg2 and op.
	Input: The address of arg1, arg2, op (oarg1 mean output argument 1).
	Output: Return error code if any invalid inputs are being detected.
*/
int ExtractInput(char* iData, int& oarg1, int& oarg2, char& op) { 
	char arg1[50];	//Buffer for arg1
	char arg2[50];	//Buffer for arg2
	char temp[50];	//Temporary buffer is reserved 
	int StartIndex = 0;
	int EndIndex = strlen(iData);
	//If the input just have one argument and it is not "Exit", then return error code 5.
	for (int i = 0; iData[i] != ASCIIspace; i++) {
		if (i == strlen(iData)-1) return 5;
	}
	//If the input just have spaces and no arguments, then return error code 5.
	for (int i = 0; iData[i] == ASCIIspace; i++) {
		if (i == strlen(iData)-1) return 5;
	}
	//Extract ARG1 from the input string by scanning from the front until detect 'space'
	for (int i = 0; iData[i] != ASCIIspace; i++) {
		arg1[i] = iData[i];
		StartIndex = i;
	}
	arg1[StartIndex + 1] = '\0'; // Add NULL at the end of the arg1 string.
	//Extract ARG2 from the input string by scanning from the back until detect 'space' and store it in the temporary array
	//Because scan and extract from the back, thus, it is in the reverse form.
	for (int i = strlen(iData) - 1; iData[i] != ASCIIspace; i--) {
		temp[strlen(iData) - i - 1] = iData[i];
		EndIndex = i;
	}
	temp[strlen(iData) - EndIndex] = '\0';
	//Flip the temporary array and store the correct data in the arg2 string.
	for (unsigned int i = 0; i < strlen(temp); i++) {
		arg2[i] = temp[strlen(temp) - i - 1];
	}
	arg2[strlen(temp)] = '\0';// Add NULL at the end of the arg2 string.

	if (!checkValidNumber(arg1) || !checkValidNumber(arg2)) return 1;	// Check if the arg1 and arg2 are in the valid form or not. If not return error code 1
	if (!CheckRange(arg1, oarg1) || !CheckRange(arg2, oarg2)) return 2;	// Check if the arg1 and arg2 are in the valid range or not. If not return error code 2

	// Advancing StartIndex by 2 to skip the white space between arg1 and op
	// Substracting EndIndex by 2 to skip the white space between op and arg2
	// Because just one single white space is allowed between argument.
	StartIndex = StartIndex + 2;
	EndIndex = EndIndex - 2;
	if (StartIndex != EndIndex) {																				// If StartIndex is not equal to EndIndex, then error occur. there will be two cases.
		for (StartIndex; iData[StartIndex] != ASCIIspace; StartIndex++) if (StartIndex == EndIndex)	return 3;	// Case 1: If the argument between StartIndex and EndIndex do not have white space, then return invalid operator
		return 5;																								// Case 2: If white space exist in the mentioned range, then return dummy variables.
	} else {
		op = iData[StartIndex];	// If SatrtIndex equal to EndIndex, then that is the position of the operand. Since op just can represent by a single character.
		if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '%')) {	// Consider whether the character 'op' is the correct form of valid operand.
			if ((op == '/') && (oarg2 == 0)) return 4;									// If the operation is division or modulo and the srg2 is 0, then return error code 4.
			else if ((op == '%') && (oarg2 == 0)) return 4;
			else return 0;																// If not in the mentioned cases above then return no error.
		}else return 3;																	// Return error code 3 if op is not in any operands form.
	}
}
/*	Function name: CheckRange.
	Usage: Check the input argument in the range of signed 16 bits interger.
	Input: Input argument in the text form, and the address of the argument in the interger form.
	Output: Boolean flag if the argument is in the range or not.
*/
bool CheckRange(char* Input, int& oarg) {
	oarg = atoi(Input);	// Convernt into interger to check the value easier.
	if (oarg < INTLOWERLIMIT || oarg > INTUPPERLIMIT) return 0;
	return 1;
}
/*	Function name: checkValidNumber.
	Usage: Check if the input argument is in the valid integer form.
	Input: Argument in test form.
	Output: Boolean flag if the argument is a valid integer or not.
*/
bool checkValidNumber(char* inputArgv) {
	bool dotDetect = false;

	for (int i = 0; inputArgv[i] != '\0'; i++) {	// Using loop to scan the iput string

		if (!isdigit(inputArgv[i]) && inputArgv[i] != '+' && inputArgv[i] != '-' && inputArgv[i] != '.') return false; // A number, '+', '-', and a dot are allowed at the first index. If not return false.

		if (i > 0 && (inputArgv[i] == '-' || inputArgv[i] == '+')) return false;	// After the first Index, just number is allowed, and maybe a dot if it not present at the first index.
		// A dot just can present one time inside the string and after the dot, everything must be zero or NULL.
		if (dotDetect) {
			if (inputArgv[i] == '.') return false;
			else if (inputArgv[i] != '0') return false;
		} else {
			if (inputArgv[i] == '.') dotDetect = true;
		}
	}
	return true;
}
/*	Function name: DoCalculate.
	Usage: Do the calculation between 2 arguments respect to the operand have been detected.
	Input: Pass the address of two arguments and the operand.
	Output: Result of the calculation.
*/
int DoCalculate(int& arg1, int& arg2, char& op) {
	switch (op) {  // Using switch statement to detect correct operand, by default it will return an addition.
	case '+': return arg1 + arg2;
	case '-': return arg1 - arg2;
	case '*': return arg1 * arg2;
	case '/': return arg1 / arg2;
	case '%': return arg1 % arg2;
	default: return arg1 + arg2;
	}
}
/*	Function name: ErrMess.
	Usage: Print out the error messeage
	Input: Error code
	Output: Boolean flag to detect if any error occurs during the process. 0 mean no error and will return 1, other cases mean error occurs and return 0.  
*/
bool ErrMess(int Err) {
	switch (Err) {	//Using switch statement to print out correct error message.
	case 0: return 1;
	case 1:
		cout << "ERROR CHECK 1: Invalid Number Input" << endl;
		return 0;
	case 2:
		cout << "ERROR CHECK 2: Invalid Range of Input" << endl;
		return 0;
	case 3:
		cout << "ERROR CHECK 3: Invalid Operator Input" << endl;
		return 0;
	case 4:
		cout << "ERROR CHECK 4: Division by 0" << endl;
		return 0;
	case 5:
		cout << "ERROR CHECK 5: Dummy Variable" << endl;
		return 0;
	default: return 0;
	}
}
/*	Function name: CheckExit.
	Usage: Check if the input string is Exit or not. If "Exit" is pressed then exit the program and print team information.
	Input: pointer to input raw string.
	Output: Boolean flag to acknowledge "Exit" have been pressed or not.
*/
bool CheckExit(char * iString) {
	if (!strcmp(iString, "Exit") || !strcmp(iString, "exit")) { // Consider both Capital (Exit) and non-capital (exit) of the first character to compare with the input string.
		cout << "LABORATORY GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
	return 0;
}
/*	Function name: PrintResult.
	Usage: Print the values of each argument as well as the result.
	Input: The address of arg1, arg2, op and value of the result.
	Output: NULL - void function.
*/
void PrintResult(int& arg1, int& arg2, char& op, int Result) {
		cout << "int arg1:   |" << arg1 << "|" << endl;
		cout << "int arg2:   |" << arg2 << "|" << endl;
		cout << "out Op:     |" << op << "|" << endl;
		cout << "RESULT:   " << Result << endl;
}
