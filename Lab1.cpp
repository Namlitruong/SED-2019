// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
char iString[50];
int arg1;
int arg2;
char op;

char *SpaceEliminate(char *);
int ExtractInput(char *, int &, int &, char &);
bool CheckValid(char *);
bool CheckRange(char *, int &);

int main() {
	while (1) {
		char iString[50];
		int Err;

		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 50);
		cout << "Eliminate Space Input:   |" << SpaceEliminate(iString) << "|" << endl;
		Err = ExtractInput(SpaceEliminate(iString), arg1, arg2, op);

		cout << "int arg1:   |" << arg1 << "|" << endl;
		cout << "int arg2:   |" << arg2 << "|" << endl;
		cout << "out Op:     |" << op << "|" << endl;
		cout << "SUM:     |" << arg1 + arg2 << "|" << endl;

		cout << "Err Message:   " << Err << endl;
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

	cout << "string arg1:   |" << arg1 << "|" << endl;
	cout << "string arg2:   |" << arg2 << "|" << endl;
	cout << "out Op:     |" << op << "|" << endl << endl << endl;

	//checkrange
	if (!CheckRange(arg1, oarg1) || !CheckRange(arg2, oarg2)) return 2;
	if (!CheckValid(arg1) || !CheckValid(arg2)) return 1;
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
