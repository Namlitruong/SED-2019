// HaloSST-Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


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
		cout << "Valid input" << endl;
	}
	else {
		cout << "Wrong input argument." << endl;
	}
	return 0;
}

