// Tut1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 11 || argc == 1) {
		cout << "Invalid input: wrong numb of argument" << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
			if ((int)argv[i][j] != 43 && (int)argv[i][j] != 45
				&& !((int)argv[i][j] > 48 && (int)argv[i][j] < 57)) {
				cout << "Invalid input: Not int" << endl;
				return 1;
			}
		}
	}

	return 0;
}
