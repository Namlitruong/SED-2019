#pragma once
#include "pch.h"
#include <string>

using namespace std;
// Node
class Term
{
protected:
	int a;
	string result;
	Term* nextTerm;
public:
	Term();
	~Term();
	Term(int newCoeff);
	Term(int newCoeff, Term* nextTerm);
	int getCoeff();
	void setData(int newCoeff);
	Term* getNext();
	void setNextTerm(Term* nextTerm);
	string equationStr;
	string getResult();
	virtual void diff();

};

