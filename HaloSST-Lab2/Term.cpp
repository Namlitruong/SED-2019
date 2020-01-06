#include "Term.h"

Term::Term() {
	nextTerm = NULL;
	a = 0;
}

Term::~Term() {}

Term::Term(int newCoeff) {
	nextTerm = NULL;
	a = newCoeff;
}

Term::Term(int newCoeff, Term* nextTerm) {
	a = newCoeff;
	this->nextTerm = nextTerm;
}

int Term::getCoeff() {
	return a;
}

void Term::setData(int newCoeff) {
	this->a = newCoeff;
}

Term* Term::getNext() {
	return nextTerm;
}

void Term::setNextTerm(Term* nextTerm) {
	this->nextTerm = nextTerm;
}

string Term::getResult() {
	return result;
}

void Term::diff() {
	result = "0";
}


