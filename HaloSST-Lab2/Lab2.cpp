// HaloSST-Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Equation.h"


using namespace std;

// Main Program
int main(int argc, char* argv[])
{
	// If no argument provided
	// Default 1: Program name
	if (argc == 1) {
		cout << "LABORATORY GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
	}
	// Once an equation provided
	else if (argc == 2) {
		// Initialize string input 
		string usrInput = "";
		for (int i = 0; argv[1][i] != '\0'; i++) {
			usrInput += argv[1][i];
		}
		
		// Create instance of Equation class
		Equation inputStr(usrInput);
		// Syntax Checker
		if (inputStr.checkCharacter()) {
			// Validate the equation format
			if (inputStr.checkEquation()) {
				// Tokenize and calculate & print success terms
				inputStr.formEquation();
				inputStr.printResult();
			}
			// On Error
			else return 1;
		}
		// On Error
		else return 1;
	}
	// Too many inputs. Not supported
	else {
		cout << "Wrong input argument." << endl;
	}
	return 0;
}

