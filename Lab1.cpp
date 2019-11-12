// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <istream>

using namespace std;
char iString[50];
char arg1;
char arg2;
char op;
char *SpaceEliminate(char *);
int ExtractInput(char *);

int main() {
	while (1) {
		char iString[50];
		int Err;

		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 50);
		cout << "Eliminate Space Input:   |" << SpaceEliminate(iString) << "|" << endl;
		Err = (ExtractInput(SpaceEliminate(iString)));
		
		
		//cout << "DATA index 0:    |" << *(ExtractInput(SpaceEliminate(iString)) + 1) << endl;
		/*cout << "DATA index 1:    |" << Data[1] << endl;
		cout << "DATA index 2:    |" << Data[2] << endl;
		cout << "DATA index 3:    |" << Data[3] << endl;*/
	}
}

char *SpaceEliminate(char *iString) {
	int StartIndex = 0;
	int EndIndex = strlen(iString);
	char*Data =  &(*iString);

	for (int i = 1; iString[i - 1] == ' '; i++) StartIndex = i;
	for (int i = strlen(iString) - 1; iString[i] == ' '; i--) EndIndex = i - 1;
	for (int i = 0; i <= (EndIndex - StartIndex); i++) Data[i] = iString[StartIndex + i];
	Data[(EndIndex - StartIndex) + 1] = '\0';

	return Data;
}

int ExtractInput(char *iData) {
	char arg1[10];
	char arg2[10];
	char temp[10];
	char op[2];
	int StartIndex = 0;
	int EndIndex = strlen(iData);
	cout << "strlen iDATA   " << strlen(iData) << endl;
	cout << "iDATA:   |" << iData << "|" << endl;
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

	cout << "StartIndex:   " << StartIndex << "   EndIndex:   " << EndIndex << endl;
	//OP
	for (int i = StartIndex + 1; iData[i] == 32; i++) StartIndex = i + 1;
	for (int i = EndIndex - 1; iData[i] == 32; i--)EndIndex = i - 1;
	cout << "StartIndex:   " << StartIndex << "   EndIndex:   " << EndIndex << endl;
	if (StartIndex != EndIndex) {
		cout << "ERROR MESSAGE 5" << endl;
	}
	else {
		op[0] = iData[StartIndex];
		op[1] = '\0';
	}

	cout << "arg1:   |" << arg1 << "|" << endl;
	cout << "arg2:   |" << arg2 << "|" << endl;
	cout << "Op:     |" << op << "|" << endl;

	Expression = {arg1, arg2, op};
	cout << endl << "Input:   |" << Expression << "|" << endl << endl;

	cout << "arg1:   |" << *Expression << "|" << endl;
	cout << "arg2:   |" << *(Expression + 1) << "|" << endl;
	cout << "Op:     |" << *(Expression + 2) << "|" << endl;
	return Expression;
}
