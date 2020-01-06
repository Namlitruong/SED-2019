#pragma once
#include "pch.h"
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
	void formEquation();
	void appendTerm(Term* term);
	void printResult();
	bool checkCharacter();
	bool checkEquation();
};

