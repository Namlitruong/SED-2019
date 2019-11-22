// Tut1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;



bool isFloat(char*);

int main(int argc, char *argv[])
{
	char inNum[10][10];
	cout << "Input 10 numbers: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> inNum[i];
	}
	for (int i = 0; i < 10; i++) {
		if (isFloat(inNum[i])) {
			cout << "Valid floating point: " << inNum[i] << endl;
		}else {
			cout << "Invalid floating point: " << inNum[i] << endl;
		}
	}
	return 0;
}

bool isFloat(char *val) {
	int decPoint = 0;
	for (int i = 0; i < strlen(val); i++) {
		if (i == 0 && (val[i] == '+' || val[i] == '-')) continue;
		if (val[i] == '.') { // Alter way: using flag.
			decPoint++;
			if (decPoint >= 2) {
				cout << "Error 2" << endl;
				return false;
			}
		}
		else if (val[i] < '0' || val[i]>'9') {
			cout << "Error 3" << endl;
			return false;
		}
	}
	return true;
}
