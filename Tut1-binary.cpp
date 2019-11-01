// Tut1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string BinaryBase1 = "0b";
string BinaryBase2 = "0b";

int main(int argc, char *argv[])
{
	if (argc != 3) {
		cout << "Error: Invalid input" << endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (strlen(argv[i]) > 8) {
			cout << "Error: Invalid input 1 " << endl;
			return 1;
		}
		for (int j = 0; j < strlen(argv[i]); j++) {
			if (argv[i][j] != '0' && argv[i][j] != '1') {
				cout << "Error: Invalid input 2" << endl;
				return 1;
			}
		}
	}

	cout << "The first binary numb: " << BinaryBase1.append(argv[1]) << endl;
	cout << "The second binary numb: " << BinaryBase2.append(argv[2]) << endl;

	return 0;
}
