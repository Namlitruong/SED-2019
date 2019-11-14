// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;
char iString[50];
int arg1;
int arg2;
char op;
int Err;

char *SpaceEliminate(char *);
int ExtractInput(char *, int &, int &, char &);
bool CheckValid(char *);
bool CheckRange(char *, int &);
bool checkValidNumber(char* );
int DoCalculate(int &, int &, char &);
bool ErrMess (int);

int main() {
	while (1) {
		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 50);

		if (!strcmp(iString, "Exit")) {
			cout << "Nam Truong - s3518702" << endl;
			cout << "Tin Nguyen - s3518702" << endl;
			cout << "Hoang Tran - s3518702" << endl;
			return 0;
		}

		cout << "Eliminate Space Input:   |" << SpaceEliminate(iString) << "|" << endl;
		Err = ExtractInput(SpaceEliminate(iString), arg1, arg2, op);
		if (ErrMess(Err)) {
			cout << "int arg1:   |" << arg1 << "|" << endl;
			cout << "int arg2:   |" << arg2 << "|" << endl;
			cout << "out Op:     |" << op << "|" << endl;
			cout << "RESULT:   " << DoCalculate(arg1, arg2, op) << endl;
		}
	}
}

char *SpaceEliminate(char *iString) {
	int StartIndex = 0;
	int EndIndex = strlen(iString);
	char*Data = &(*iString);

	for (int i = 1; iString[i - 1] == ' '; i++) StartIndex = i;
	for (int i = strlen(iString) - 1; iString[i] == ' '; i--) EndIndex = i - 1;
	for (int i = 0; i <= (EndIndex - StartIndex); i++) Data[i] = iString[StartIndex + i];
	Data[(EndIndex - StartIndex) + 1] = '\0';

	return Data;
}

int ExtractInput(char *iData, int &oarg1, int &oarg2, char &op) {
	char arg1[10];
	char arg2[10];
	char temp[10];
	int StartIndex = 0;
	int EndIndex = strlen(iData);

	for (int i = 0; iData[i] != 32; i++) {
		if (i == strlen(iData)) return 5;
	}
	//ARG1
	for (int i = 0; iData[i] != 32; i++) {
		arg1[i] = iData[i];
		StartIndex = i;
	}
	arg1[StartIndex + 1] = '\0';
	//ARG2
	for (int i = strlen(iData) - 1; iData[i] != 32; i--) {
		temp[strlen(iData) - i - 1] = iData[i];
		EndIndex = i;
	}
	temp[strlen(iData) - EndIndex] = '\0';
	for (int i = 0; i < strlen(temp); i++) {
		arg2[i] = temp[strlen(temp) - i - 1];
	}
	arg2[strlen(temp)] = '\0';
	//OP
	for (int i = StartIndex + 1; iData[i] == 32; i++) StartIndex = i + 1;
	for (int i = EndIndex - 1; iData[i] == 32; i--)EndIndex = i - 1;
	op = iData[StartIndex];

	//checkrange
	if (!CheckRange(arg1, oarg1) || !CheckRange(arg2, oarg2)) return 2;
	if (!checkValidNumber(arg1) || !checkValidNumber(arg2)) return 1;
	if (StartIndex != EndIndex) {
		return 5;
	}
	else {
		if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '%')) {
			if ((op == '/') && (oarg2 == 0)) return 4;
			else return 0;
		}
		else {
			return 3;
		}
	}
}

bool CheckValid(char *Input) {
	for (int i = 0; i < strlen(Input); i++) {
		if (i == 0 && (*(Input + i) == '+' || *(Input + i) == '-')) continue;
		if (((*(Input + i) < '0') || (*(Input + i) > '9'))) {
			return 0;
		}
	}
	return 1;
}

bool CheckRange(char *Input, int &oarg) {
	if (strlen(Input) > 6) return 0;
	oarg = atoi(Input);
	if (oarg < -32768 || oarg > 32767) return 0;
	return 1;
}

bool checkValidNumber(char* inputArgv) {
	char usr_input;
	bool exponent = false;
	bool dotDetect = false;
	bool eCharDetect = false;

	for (int i = 0; inputArgv[i] != '\0'; i++) {
		usr_input = inputArgv[i];

		if (!isdigit(usr_input) && usr_input != '+' && usr_input != '-' && usr_input != '.' && usr_input != 'E' && usr_input != 'e') {
			cout << "error: Illegal character in element " << i << " value enter: " << usr_input << endl;
			return false;
		}

		if (i == 0 && (inputArgv[i] == 'e' || inputArgv[i] == 'E')) {
			cout << "Invlaid Scientific format" << endl;
			return false;
		}
		// dummy variable check 5+2+2
		//TODO e/E at i=0

		if (i > 0 && (usr_input == '-' || usr_input == '+') && (inputArgv[i - 1] != 'E' || inputArgv[i - 1] != 'e')) {
			cout << "Dummy variable";
			return false;
		}

		// 1.22E3
		if (usr_input == '.' && dotDetect == false) {
			dotDetect = true;
			//cout << "error: Decimal point in element " << i << " Value entered: " << usr_input << endl;
			return false;
		}
		else if (usr_input == '.' && dotDetect == true) { //detect other dots
			cout << "error: Decimal point in element " << i << " Value entered: " << usr_input << endl;
			return false;
		}
		if (usr_input == 'e' || usr_input == 'E') {
			exponent = true;
		}
	}
	return true;
}

int DoCalculate(int &arg1, int &arg2, char &op) {
	switch (op) {
		case '+': return arg1 + arg2;
		case '-': return arg1 - arg2;
		case '*': return arg1 * arg2;
		case '/': return arg1 / arg2;
		case '%': return arg1 % arg2;
		default: return arg1 + arg2;
	}
}

bool ErrMess(int Err) {
	switch (Err) {
		case 0: return 1;
		case 1:
			cout << "ERROR CHECK 1" << endl;
			return 0;
		case 2: 
			cout << "ERROR CHECK 2" << endl;
			return 0;
		case 3: 
			cout << "ERROR CHECK 3" << endl;
			return 0;
		case 4: 
			cout << "ERROR CHECK 4" << endl;
			return 0;
		case 5: 
			cout << "ERROR CHECK 5" << endl;
			return 0;
		default: return 0;
	}
}
