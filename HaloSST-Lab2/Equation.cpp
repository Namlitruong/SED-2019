#include "Equation.h"
#include <iostream>
#include "Constant.h"
#include "Linear.h"
#include "Power.h"
#include "Exponential.h"
#include "Log10.h"
#include "LogE.h"
#include "Sinusoidal.h"
#include "Cosinusoidal.h"

Equation::Equation(){}
Equation::~Equation(){}

Equation::Equation(string eqtnInput) {
	usrInput = eqtnInput;
}

void Equation::appendTerm(Term* term) {
	Term* current = NULL;
	term->setNextTerm(NULL);
	if (head == NULL) {
		head = term;
	}
	else {
		current = head;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNextTerm(term);
	}

}

// check each character
bool Equation::checkCharacter() {
	for (int i = 0; i < usrInput.length(); i++) {
		char inputCharacter = usrInput[i];
		if (!isdigit(inputCharacter) && inputCharacter != '+' && inputCharacter != '-'
			&& inputCharacter != '*' && inputCharacter != 'x' && inputCharacter != '('
			&& inputCharacter != ')' && inputCharacter != 'l' && inputCharacter != 'o'
			&& inputCharacter != 'g' && inputCharacter != 'c' && inputCharacter != 's'
			&& inputCharacter != 'i' && inputCharacter != 'n' && inputCharacter != '^' && inputCharacter != 'e') {
			cout << "Error: Invalid character: " << inputCharacter << " at index " << i << endl;
			return false;
		}
	} return true;
}

bool Equation::checkTerm(string term)
{
	bool cnstA = false;
	bool cnstB = false;
	bool firstMulti = false;
	bool secondMulti = false;
	bool xDetect = false;
	bool powDetect = false;
	bool openBracket = false;
	bool closeBracket = false;
	bool xBDetect = false;
	bool eDetect = false;
	bool logDetect = false;
	bool sinDetect = false;
	bool cosDetect = false;
	bool secondxDetect = false;
	for (int i = 0; i < term.length(); i++) {
		char inputCharacter = term[i];

		
		if (cnstA && !isdigit(inputCharacter) && inputCharacter != '*' && inputCharacter != ')') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		if (firstMulti && inputCharacter != 'e' && inputCharacter != 'l' && inputCharacter != 's'
			&& inputCharacter != 'x' && inputCharacter != 'c') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// after e must be ^ and (
		if ((eDetect == true) && inputCharacter != '^' && inputCharacter != '(' && !secondxDetect && inputCharacter == ')') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// after pow (^) must be (
		if (powDetect && inputCharacter != '(') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// after openBracket ( must be x or number
		if (openBracket && inputCharacter != 'x' && !isdigit(inputCharacter)) {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// after b constant must be ) or * 
		if (cnstB && !isdigit(inputCharacter) && inputCharacter != ')' && inputCharacter != '*') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// after multiply in bracket must be x
		if (secondMulti && inputCharacter != 'x') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		// second x in bracket
		if (xBDetect && inputCharacter != ')') {
			cout << "Invalid character at: " << inputCharacter << endl;
			return false;
		}
		if (logDetect) {
			if (inputCharacter == 'o' && term[i + 1] == 'g') {
				if (term[i + 2] == '1' && term[i + 3] == '0' && term[i + 4] == '(') {
					i = i + 3;
				}
				else if (term[i + 2] == 'e' && term[i + 3] == '(') {
					i = i + 2;
				}
				else {
					return false;
				}
			}
			else if (secondxDetect) {
				return false;
			}
		}
		if (sinDetect) {
			if (inputCharacter == 'i' && term[i + 1] == 'n' && term[i + 2] == '(') {
				i = i + 1;
			}
			else if (secondxDetect) {
				return false;
			}
		}
		if (cosDetect) {
			if (inputCharacter == 'o' && term[i + 1] == 's' && term[i + 2] == '(') {
				i = i + 1;
			}
			else if (secondxDetect) {
				return false;
			}
		}

		if (!cnstA && isdigit(inputCharacter) && !openBracket) {
			cnstA = true;
		}
		if (cnstA && inputCharacter == '*' && !firstMulti) {
			firstMulti = true;
			cnstA = false;
		}


		if (inputCharacter == 'x' && !xDetect) {
			firstMulti = false;
			xDetect = true;
		}
		if (inputCharacter == 'e' && !eDetect) {
			if (i == term.length() - 1) {
				return false;
			}
			eDetect = true;
			firstMulti = false;
		}
		if (inputCharacter == 'l' && !logDetect) {
			if (i == term.length() - 1) {
				return false;
			}
			firstMulti = false;
			logDetect = true;
		}
		if (inputCharacter == 's' && !sinDetect) {
			if (i == term.length() - 1) {
				return false;
			}
			firstMulti = false;
			sinDetect = true;
		}
		if (inputCharacter == 'c' && !cosDetect) {
			if (i == term.length() - 1) {
				return false;
			}
			firstMulti = false;
			cosDetect = true;
		}
		if (inputCharacter == '^' && !powDetect) {
			if (i == term.length() - 1) {
				return false;
			}
			if (!xDetect) {
				powDetect = true;
			}
			else {
				powDetect = false;
			}
		}
		if ((sinDetect || cosDetect || logDetect) && !secondxDetect && inputCharacter == 'x') {
			secondxDetect = true;
		}
		if (eDetect && !secondxDetect && inputCharacter == 'x') {
			secondxDetect = true;
			eDetect = false;
		}
		if (inputCharacter == '(' && !openBracket) {
			if (i == term.length() - 1) {
				cout << "open bracket detect invalid end" << endl;
				return false;
			}
			powDetect = false;
			openBracket = true;
		}
		if (isdigit(inputCharacter) && openBracket) {
			if (i == term.length() - 1) {
				cout << "coeff B detect invalid end" << endl;
				return false;
			}
			openBracket = false;
			cnstB = true;
		}

		if (cnstB && inputCharacter == '*') {
			if (i == term.length() - 1) {
				cout << "multiply B detect invalid end" << endl;
				return false;
			}
			secondMulti = true;
			cnstB = false;
		}
		if (cnstB && i == term.length() - 1 && inputCharacter != ')') {
			return false;
		}
		if ((sinDetect || cosDetect || logDetect) && !secondxDetect && inputCharacter == ')') {
			cout << "Wrong input format at term: " << term << endl;
			return false;
		}
		if ((secondMulti || openBracket) && inputCharacter == 'x') {
			if (i == term.length() - 1) {
				return false;
			}
			xDetect = false;
			xBDetect = true;
			secondMulti = false;
			openBracket = false;
			secondxDetect = false;
			cosDetect = false;
			sinDetect = false;
			logDetect = false;

		}
	}
	return true;
}

//TODO checkEquation
bool Equation::checkEquation(){}

// TODO printResult
void Equation::printResult() {}

// TODO formEquation
void Equation::formEquation(){}