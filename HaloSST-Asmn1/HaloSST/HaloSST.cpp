//##########################################################################################################################################
//	School of Science & Technology				
//	EEET2482 - Software Engineering Design		
//	Asigment 1 - C++ Scientific Calculator		
//	Team name: HaloSST							
//	Member 1: Nam Truong - s3518702				
//	Member 2: Tin Nguyen - s3607833				
//	Member 3: Hoang Tran - s3618889				
//###########################################################################################################################################

#include "pch.h"
#include <iostream>
#define INTUPPERLIMIT 32767
#define INTLOWERLIMIT -32767
#define MAX 1000
#define unaryOp '!'
#define INPUTLIMIT 100

using namespace std;

//////////////////////////--Stack--/////////////////////////////
class Stack {
	int *arr;
	char *arrSub;
	int top;
	int capacity;
public:
	Stack(int size = MAX);     // constructor
	~Stack();                   // destructor

	void push(int);
	void pushSub(char);
	int pop();
	char popSub();
	int peek();
	char peekSub();
	int size();
	bool isEmpty();
	bool isFull();
};

Stack::Stack(int size)
{
	arr = new int[size];
	arrSub = new char[size];
	capacity = size;
	top = -1;
}

// Destructor to free memory allocated to the stack
Stack::~Stack()
{
	delete arr;
	delete arrSub;
}

void Stack::push(int x)
{
	if (isFull())
	{
	}
	arr[++top] = x;
}

void Stack::pushSub(char x)
{
	if (isFull())
	{
	}
	arrSub[++top] = x;
}

//removes or pops elements out of the stack
int Stack::pop()
{
	if (isEmpty())
	{
		return 0;
	}


	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

char Stack::popSub()
{
	if (isEmpty())
	{
		return 0;
	}


	// decrease stack size by 1 and (optionally) return the popped element
	return arrSub[top--];
}

int Stack::size()
{
	return top + 1;
}

int Stack::peek()
{
	if (!isEmpty()) {
		return arr[top];
	}
	return -1;
}

char Stack::peekSub()
{
	if (!isEmpty()) {
		return arrSub[top];
	}
	return -1;
}

//check if stack is empty
bool Stack::isEmpty()
{
	return top == -1;    // or return size() == 0;
}
bool Stack::isFull()
{
	return top == capacity - 1;    // or return size() == capacity;
}
//////////////////////////--Stack--/////////////////////////////

//Global variables
char iString[1000];
class Stack Expr;

//Function prototype
bool CheckExit(char *);
int CheckExpr(char*);
bool CheckOp(char);
bool CheckOpSci(char);
int CheckNum(char*, Stack&);
bool CharSci(char);
bool Check1stNum(char);
void ScitoInt(char *, int&);
int checkValidNumberAndRange(char*, int&);
char* ExtractFromStack(char *, Stack &);
void errCheck(int,int , bool);
char *Filter(char *);
int constructEvalStack(string, bool&);
int opPrecedence(char);
int evaluateExp(int, int, char, bool&);

//Main Program
int main()
{
	while (1) {
		bool err5 = false;
		int err1 = 0, err2 = 0;
		int result;
		cout << "___________________________________________________________\n";
		cout << "\n#NOTE: Input String cannot larger than 100 character." << endl;					//Acknowledge user the input constraint
		cout << "#NOTE: Input String cannot contain whitespace." << endl;
		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 1000);

		if (strlen(iString) < INPUTLIMIT) {
			if (CheckExit(iString)) return 0;
			err1 = CheckExpr(iString);
			Filter(iString);
			if (err1 == 0) err2 = CheckNum(iString, Expr);
			if (err2 == 0) result = constructEvalStack(ExtractFromStack(iString, Expr), err5);
			if (err1 == 0 && err2 == 0 && err5 == 0) cout << "The Final Result:    " << result << endl;
			errCheck(err1, err2, err5);
		}else cout << "ERROR: Too many characters. Please input the expression again !!!" << endl;
	}
}
/*	Function name: errCheck.
	Usage: Print out the error message
	Input: error codes from the error variables 
	Output: NULL - void function.
*/
void errCheck(int err1, int err2, bool err5) {
	switch (err1) {
	case 3: {
		cout << "ERROR CHECK 3: Valid Operator Input" << endl;
		break;
	}
	case 4: {
		cout << "ERROR CHECK 4: Valid Expression" << endl;
		break;
	}
	}

	switch (err2) {
	case 1: {
		cout << "ERROR CHECK 1: Valid Number Input" << endl;
		break;
	}
	case 2: {
		cout << "ERROR CHECK 2: Number Input Range Check" << endl;
		break;
	}
	}

	if (err5) cout << "ERROR CHECK 5: Division by 0" << endl;
}
/*	Function name: ExtractFromStack.
	Usage: Take out all the data from a stack and put it in a assigned string
	Input: Pointer to the target string, the address of the stack
	Output: Pointer to the target string
*/
char* ExtractFromStack(char *oStr, Stack &iStack) {
	char temp[100];
	char*Data = &(*oStr);
	int count;
	for (count = 0; !Expr.isEmpty(); count++) {		//Pop out all the data from the stack
		temp[count] = (char)iStack.pop();
	}
	temp[count] = '\0';

	for (count = 0; count < strlen(temp); count++) {	//Flip the string, since stack is LIFO (Last In First Out)
		Data[count] = temp[strlen(temp) - count - 1];
	}
	Data[strlen(temp)] = '\0';
	return Data;
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
/*	Function name: CheckOp.
	Usage: Check whether the input char is operator
	Input: Character
	Output: Boolean flag to acknowledge the input is an operator or not
*/
bool CheckOp(char op) {
	if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '%') || (op == '^')) return true;
	return false;
}
/*	Function name: CheckOpSci.
	Usage: Support to check Valid Expression
	Input: Character
	Output: Boolean flag to acknowledge the input is a character use to seperate digit
*/
bool CheckOpSci(char op) {
	if (CheckOp(op) || (op == '.') || (op == 'e') || (op == 'E')) return true;
	return false;
}
/*	Function name: CharSci.
	Usage: Check whether the input char is a character use to seperate digit
	Input: Character
	Output: Boolean flag to acknowledge the input is a character use to seperate digit
*/
bool CharSci(char op) {
	if (CheckOp(op) || (op == ')') || (op == '(') || (op == '!')) return true;
	return false;
}
/*	Function name: Check1stNum.
	Usage: Support for CheckNum function to extract number
	Input: Character
	Output: Boolean flag to acknowledge the input is in the defined set
*/
bool Check1stNum(char c) {
	if (isdigit(c) || c == '.' || c == 'e' || c == 'E') return true;
	return false;
}
/*	Function name: Filter.
	Usage: Detect and replace unary signs ('-' into '!' and '+' into '0')
	Input: Pointer to the input string
	Output: Pointer to the target string
*/
char *Filter(char *iData) {// Unary can appear on the first index, after operators, after open parentheses and e-notation
	char *Data = &(*iData);
	for (int i = 0; i < strlen(Data); i++) {
		if (i == 0 && Data[i] == '-') iData[i] = '!';// Change '-' with '!'
		if ((CheckOp(Data[i - 1]) || Data[i - 1] == '(' || Data[i - 1] == 'e' || Data[i - 1] == 'E') && Data[i] == '-') Data[i] = '!';

		if (i == 0 && Data[i] == '+') iData[i] = '0';// Change '+' with '0'
		if ((CheckOp(Data[i - 1]) || Data[i - 1] == '(' || Data[i - 1] == 'e' || Data[i - 1] == 'E') && Data[i] == '+') Data[i] = '0';
	}
	return Data;
}
/*	Function name: CheckExpr.
	Usage: Check the validation of the input expression or operators 
	Input: Pointer to the input string
	Output: Return error code for expression and operator validation (return 0 = no error)
*/
int CheckExpr(char* iData) {
	bool flagOp = false;
	int Left = 0, Right = 0;
	// Invalid Expression Error Check
	for (int i = 0; i < strlen(iData); i++) {
		//Check for invalid char
		if (!(isdigit(iData[i]) || CheckOpSci(iData[i]) || iData[i] == ')' || iData[i] == '(')) return 3;
		//Check First index 
		if ((iData[0] == '*' || iData[0] == '/' || iData[0] == '%' || iData[0] == '^' || iData[0] == 'e' || iData[0] == 'E')) return 4;
		//Check Last index 
		if (i == strlen(iData) - 1 && (CheckOp(iData[i]) || iData[i] == 'e' || iData[i] == 'E' || iData[i] == '.')) return 4;
		//Check empty parentheses
		if (iData[i] == ')' && iData[i - 1] == '(') return 4;
		if (iData[i - 1] == ')' && iData[i] == '(') return 4;
		//Check Op
		if (!isdigit(iData[i]) && (iData[i] != '(') && flagOp) return 4; // After '(' just operator can appear, that operator is unary.
		if (CheckOp(iData[0]) && CheckOp(iData[1])) return 4;// The first number just have an unary sign. Then 2 operators at the beginning is error.
		if ((CheckOpSci(iData[i]) && CheckOpSci(iData[i - 1])) || (CheckOpSci(iData[i]) && iData[i - 1] == '(')) flagOp = true; // Set operator flag
		if (isdigit(iData[i]) || iData[i] == '(') flagOp = false;
		if ((iData[i] == '*' ||
			iData[i] == '/' ||
			iData[i] == '%' ||
			iData[i] == '^') &&
			CheckOpSci(iData[i - 1])) return 4; // If 2 operators appear in a row, just '-' and '+' can appear in the second index
		//Check numb of parentheses
		if (iData[i] == '(') Left++;
		if (iData[i] == ')') Right++;
	}
	if (Left != Right) return 4; // Return error if the number of open and closing parentheses are not equal. 
	return 0;
}
/*	Function name: CheckNum.
	Usage: Using stack to detect, validate, store and convert numbers form an input string to an standard form. (Example: 2e2 = 200, 13.00 = 13)
	Input: pointer to input string and the address of the stack 
	Output: Boolean flag to acknowledge the input is a character use to determin digit (include scientific form)
*/
int CheckNum(char* iData, Stack &Expr) {
	bool flagOp = false;
	char temp[50], analysedStr[50];
	int count = 0;
	char subData;
	int oarg;
	// Using the characters in the CharSci function to separated number. However, the first, the last or might be both numbers might not enclose 
	// by those characters. Therefore, using Finite State Machine (FSM) to handle the mentioned cases.
	enum Scenario { NORMAL = 1, FIRST = 2, LAST = 3, BOTH = 4 };
	Scenario Sce = NORMAL;

	for (int i = 0; i < strlen(iData); i++) {
		Expr.push(iData[i]);
		/////////////////////////--Define State--///////////////////////////
		if (i == 0 && isdigit(iData[i])) Sce = FIRST;
		if ((i == strlen(iData) - 1) && isdigit(iData[i])) {
			Sce = LAST;
			if (Check1stNum(iData[0]) && flagOp == false) Sce = BOTH;
		}
		/////////////////////////--Define State--//////////////////////////
		if (i == 0 && (iData[i] == '-' || iData[i] == '+') || iData[i] == '!') continue; // Skip the first index if it is an unary sign
		if (CheckOp(iData[i]) || iData[i] == '!') flagOp = true; // Support to detect 'BOTH' state

		if ((CheckOp(iData[i]) || iData[i] == ')' || i == strlen(iData) - 1) || iData[i] == '!') { //Enter the FSM to start to extract and analyse number
			switch (Sce) {
			case NORMAL: {
				subData = iData[i]; // Store 
				Expr.pop();
				for (count = 0; !(CharSci(Expr.peek())); count++) {
					temp[count] = Expr.pop();
					if (Expr.peek() == '!') {
						Expr.pop();
						if (Expr.peek() == 'e' || Expr.peek() == 'E') {
							Expr.push('?');
						}
						else {
							Expr.push('!');
						}
					}
				}
				break;
			}
			case FIRST: {
				subData = iData[i];
				Expr.pop();
				for (count = 0; !Expr.isEmpty(); count++) {
					temp[count] = Expr.pop();
				}
				Sce = NORMAL;
				break;
			}
			case LAST: {
				for (count = 0; !(CharSci(Expr.peek())); count++) {
					temp[count] = Expr.pop();
					if (Expr.peek() == '!') {
						Expr.pop();
						if (Expr.peek() == 'e' || Expr.peek() == 'E') {
							Expr.push('?');
						}else {
							Expr.push('!');
						}
					}
				}
				break;
			}
			case BOTH: {
				for (count = 0; !Expr.isEmpty(); count++) {
					temp[count] = Expr.pop();
				}
				break;
			}
			}

			temp[count] = '\0';
			for (unsigned int i = 0; i < strlen(temp); i++) {
				analysedStr[i] = temp[strlen(temp) - i - 1];
			}
			analysedStr[strlen(temp)] = '\0';
			//////////////////////////////////////
			int Select = checkValidNumberAndRange(analysedStr, oarg);
			switch (Select) {
			case 0:
				snprintf(analysedStr, sizeof(analysedStr), "%d", oarg);
				break;
			case 1:
				snprintf(analysedStr, sizeof(analysedStr), "%d", oarg);
				return 1;
			case 2:
				snprintf(analysedStr, sizeof(analysedStr), "%d", oarg);
				return 2;
			case 3:break;
			}
			///////////////////////////////

			for (int j = 0; j < strlen(analysedStr); j++) {
				if (analysedStr[j] == '-') Expr.push('!');
				else Expr.push(analysedStr[j]);
			}

			switch (Sce) {
			case NORMAL: {
				Expr.push(subData);
				break;
			}
			case FIRST: {
				Expr.push(subData);
				Sce = NORMAL;
				break;
			}
			case LAST:
				break;
			case BOTH:
				break;
			}
		}

	}
	return 0;
}

/*	Function name: checkValidNumberAndRange.
	Usage: Check if the input number is in the valid integer form and in the defined range and convert it from text form into integer form.
	Input: Pointer to an input argument, and address of the number in int datatype
	Output: Error code for valid number and valid number range. 
*/
int checkValidNumberAndRange(char* inputArgv, int& oarg) {
	bool dotDetect = false;
	bool sciDetect = false;
	bool numDetect = false;

	for (int i = 0; inputArgv[i] != '\0'; i++) {	// Using loop to scan the iput string

		if (isdigit(inputArgv[i])) numDetect = true;

		if (i == 0 && inputArgv[i] == '+' && inputArgv[i] == '-' && inputArgv[i] == '.') continue;// A number, '+', '-', and a dot are allowed at the first index. If not return false.

		if (i > 0 && (inputArgv[i] == '-' || inputArgv[i] == '+')) return 1;	// After the first Index, just number is allowed, and maybe a dot if it not present at the first index.
		// A dot just can present one time inside the string and after the dot, everything must be zero or NULL.
		if (inputArgv[i] == '!' || inputArgv[i] == '?') inputArgv[i] = '-';
		if (dotDetect) {
			if (inputArgv[i] == '.') return 1;
			else if (inputArgv[i] != '0') return 1;
		}
		else {
			if (inputArgv[i] == '.') dotDetect = true;
		}

		if (sciDetect) {
			if (inputArgv[i] == 'e' || inputArgv[i] == 'E') return 1;
			else if (inputArgv[i] == '.') return 1;
		}
		else {
			if (inputArgv[i] == 'e' || inputArgv[i] == 'E') sciDetect = true;
		}
	}
	if (!numDetect) return 3;

	if (sciDetect) {
		ScitoInt(inputArgv, oarg);
	}else{
		oarg = atoi(inputArgv);
	}

	if (oarg < INTLOWERLIMIT || oarg > INTUPPERLIMIT) return 2;
	return 0;
}
/*	Function name: ScitoInt
	Usage: Convert a scientific number in a text form to int.
	Input: Pointer to the input number in text form, the address of a number in int form.
	Output: NULL - void funvtion.
*/
void ScitoInt(char *Input, int& oarg) {
	int Pow, Numb, temp = 1;
	int count = 0;
	bool flagNegPow = false;

	for (int i = 0; i < strlen(Input); i++) {
		if (Input[i] == 'e' || Input[i] == 'E') count = i;
		if (i != 0 && Input[i] == '-') flagNegPow = true;
	}

	Pow = atoi(&Input[count + 1]);
	Numb = atoi(Input);

	for (int i = 0; i < Pow; i++) {
		temp = temp * 10;
	}
	if (flagNegPow) oarg = 0;
	else oarg = Numb * temp;
}

int constructEvalStack(string f_str, bool &Err5) {
	int idx = 0, idx_Grp = 0;
	Stack opt_stk(500), val_stk(500);

	for (idx = 0; idx < f_str.length(); idx++)
	{
		// Input is Number
		if (isdigit(f_str[idx])) {

			int val = 0;

			while (idx < f_str.length() && isdigit(f_str[idx])) {
				// Next decimal (* 10) + ASCII number of Integer
				val = (val * 10) + (f_str[idx] - '0');

				if (!isdigit(f_str[idx + 1])) {
					break;
				}
				else {
					idx++;
				}
			}

			val_stk.push(val);
		}

		// Input is Opening Parenthesis
		else if (f_str[idx] == '(') {

			if (idx > 0 && f_str[idx - 1] == unaryOp) {
				idx_Grp++;
			}
			// Case x + (-A * x)
			// FIXME else if to if. Corner case -(-A * x)
			if (f_str[idx + 1] == unaryOp && isdigit(f_str[idx + 2])) {
				opt_stk.pushSub(f_str[idx]); // Push closing bracket

				// Then jump to number and evaluate in order to stack
				idx += 2;
				int val = 0;

				while (idx < f_str.length() && isdigit(f_str[idx])) {
					// Next decimal (* 10) + ASCII number of Integer
					val = (val * 10) + (f_str[idx] - '0');

					if (!isdigit(f_str[idx + 1])) {
						break;
					}
					else {
						idx++;
					}
				}

				val *= -1; // For clarity
				val_stk.push(val);
				continue;
			}

			opt_stk.pushSub(f_str[idx]);
		}

		// Input is Closing Parenthesis
		else if (f_str[idx] == ')') {

			while (!opt_stk.isEmpty() && opt_stk.peekSub() != '(') {
				int arg2 = val_stk.pop();

				int arg1 = val_stk.pop();

				char op = opt_stk.popSub();

				val_stk.push(evaluateExp(arg1, arg2, op, Err5));
			}

			if (opt_stk.peekSub() == '(') {
				opt_stk.popSub();

				if (idx_Grp >= 1) {
					int swapVal_temp = val_stk.pop();

					swapVal_temp *= -1; // For clarity
					val_stk.push(swapVal_temp);

					idx_Grp--;
				}

			}

		}
		// TODO && not an operator condition
		else if (f_str[idx] == unaryOp) {

			if (isdigit(f_str[idx + 1])) {
				int val = 0;
				idx++;

				while (idx < f_str.length() && isdigit(f_str[idx])) {
					// Next decimal (* 10) + ASCII number of Integer
					val = (val * 10) + (f_str[idx] - '0');

					if (!isdigit(f_str[idx + 1])) {
						break;
					}
					else {
						idx++;
					}
				}

				val *= -1; // For clarity
				val_stk.push(val);
			}
			// TODO bracket group counter array
			// NOTE approach from bracket detector
			else {
				continue;
			}

		}

		// Input is Operator 
		else {

			while (!opt_stk.isEmpty()
				&& (opPrecedence(opt_stk.peekSub()) >= opPrecedence(f_str[idx]))
				&& opt_stk.peekSub() != '(') {

				int arg2 = val_stk.pop();

				int arg1 = val_stk.pop();

				char op = opt_stk.popSub();

				val_stk.push(evaluateExp(arg1, arg2, op, Err5));
			}

			opt_stk.pushSub(f_str[idx]);
		}
	}

	// Final Calculation
	while (!opt_stk.isEmpty() && !val_stk.isEmpty()) {
		int arg2 = val_stk.pop();

		int arg1 = val_stk.pop();

		char op = opt_stk.popSub();

		val_stk.push(evaluateExp(arg1, arg2, op, Err5));
	}

	return val_stk.peek();
}

int opPrecedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}

	if (op == '*' || op == '/' || op == '%') {
		return 2;
	}

	if (op == '^') {
		return 3;
	}

	if (op == '!') {
		return 4;
	}

	if (op == '(' || op == ')') {
		return 5;
	}

	// Else
	return 0;
}

int evaluateExp(int arg1, int arg2, char op, bool &Err5) {
	switch (op) {
	case '+': return arg1 + arg2;
	case '-': return arg1 - arg2;
	case '*': return arg1 * arg2;
	case '/': {
		if (arg2 == 0) {
			Err5 = true;
			break;
		}
		return arg1 / arg2;
	}
	case '%': {
		if (arg2 == 0) {
			Err5 = true;
			break;
		}
		return arg1 % arg2;
	}
	case '^': {
		int result_tmp = 1;
		if (arg2 < 0) return 0;
		else {
			for (int i = 0; i < arg2; i++)
			{
				result_tmp *= arg1;
			};
			return result_tmp;
		}
	}
	}
	return 0;
}
