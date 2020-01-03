#pragma once
#include "Term.h"
#include "Constant.h"

// Linked list

class Equation
{
private:
	Term* head;
	string usrInput;
	bool checkTerm(string term);
public:
	Equation();
	~Equation();
	Equation(string usrInput);
	void constructEquation();
	void insertTerm(Term* term);
	void printResult();
	bool scanCharacter();
	bool checkEquation();
};

