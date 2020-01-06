// HaloSST-Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Equation.h"


using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) {
		cout << "LABORATORY GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
	}
	else if (argc == 2) {
		string usrInput = "";
		for (int i = 0; argv[1][i] != '\0'; i++) {
			usrInput += argv[1][i];
		}
		Equation inputStr(usrInput);
		if (inputStr.checkCharacter()) {
			if (inputStr.checkEquation()) {
				inputStr.formEquation();
				inputStr.printResult();
			}
			else return 1;
		}
		else return 1;
	}
	else {
		cout << "Wrong input argument." << endl;
	}
	return 0;
}

