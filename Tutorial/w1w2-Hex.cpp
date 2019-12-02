// tut1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int Task1(int, char ***);
int Task1Addition(int , char ***);

int main(int argc, char **argv) {
	//return Task1(argc, &argv);
	return Task1Addition(argc, &argv);
}

int Task1(int argc, char ***argv) {
	if (argc != 2 || *(*argv + 1) == NULL || (*(*(*argv + 1) + 4)) != '\0') {
		cout << "Invalid Input" << endl;
		return 1;
	}

	if ((**(*argv + 1)) != '0' || ((*(*(*argv + 1) + 1) != 'x') && (*(*(*argv + 1) + 1) != 'X'))) {
		cout << "Invalid Input 1" << endl;
		return 1;
	}

	for (int i = 2; i < 4; i++) {
		if (((*(*(*argv + 1) + i) < 48) || (*(*(*argv + 1) + i) > 57)) && ((*(*(*argv + 1) + i) < 65) || (*(*(*argv + 1) + i) > 70))) {
			cout << "Invalid Input 2" << endl;
			return 1;
		}
	}

	cout << "The Hexadecimal number: " << *(*argv + 1) << endl;
	return 0;
}

int Task1Addition(int argc, char ***argv) {

	if (argc > 4) {
		cout << "Invalid Input" << endl;
		return 1;
	}

	for (int i = 1; i < 4; i++) {
		if (*(*argv + i) == NULL || (*(*(*argv + i) + 4)) != '\0') {
			cout << "Invalid Input 1" << endl;
			return 1;
		}

		if ((**(*argv + i)) != '0' || ((*(*(*argv + i) + 1) != 'x') && (*(*(*argv + i) + 1) != 'X'))) {
			cout << "Invalid Input 2" << endl;
			return 1;
		}

		for (int j = 2; j < 4; j++) {
			if (((*(*(*argv + i) + j) < 48) || (*(*(*argv + i) + j) > 57)) && ((*(*(*argv + i) + j) < 65) || (*(*(*argv + i) + j) > 70))) {
				cout << "Invalid Input 3" << endl;
				return 1;
			}
		}

		cout << "The " << i << " Hexadecimal number: " << *(*argv + i) << endl;
	}
	return 0;
}