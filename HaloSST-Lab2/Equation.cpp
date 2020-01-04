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

bool Equation::checkEquation()
{
	string term = "";
	for (int i = 0; i < usrInput.length(); i++) {
		char inputCharacter = usrInput[i];
		if ((inputCharacter == '+' || inputCharacter == '-') && i != 0 && usrInput[i - 1] != '(') {

			if (term == "" || i == usrInput.length() - 1) return false;
			else {
				if (!checkTerm(term)) {
					cout << "invalid term: " << term << endl;
					return false;
				}
				term = "";
			}
		}
		else {
			if (inputCharacter != '+' && inputCharacter != '-') term += inputCharacter;
			if (i == usrInput.length() - 1) {
				if (!checkTerm(term)) {
					cout << "invalid term: " << term << endl;
					return false;
				}
			}
		}
	}
	return true;
}

void Equation::printResult() {
	string result = "The result is: ";
	Term* current = head;
	bool isFirstNumber = false;
	while (current != NULL) {
		current->diff();
		int coeff = current->getCoeff();
		if (!isFirstNumber) {
			result += "";
			isFirstNumber = true;
			result += current->getResult();
		}
		else if (coeff > 0) {
			result += "+";
			result += current->getResult();
		}
		else if (coeff == 0 && current->getResult() != "0") {

			result += "";
		}
		else if (coeff == 0) {
			result += "";
		}
		else {
			result += current->getResult();
		}
		current = current->getNext();
	}

	cout << endl;
	cout << result << endl;
}

// TODO check x^b without bracket
void Equation::formEquation() {
	int strLength = usrInput.length();
	int coeffA = 0;
	int coeffB = 0;
	int pow = 0;
	string coeffAstr = "";
	string coeffBstr = "";
	string powStr = "";
	string func = "";
	bool xDetect = false;
	bool eDetect = false;
	bool funcDetect = false;
	bool consDetect = false;
	bool digitDetect = false;
	bool bracket = false;
	int track = 0;
	for (int i = 0; i < strLength; i++) {
		char inputCharacter = usrInput[i];
		track = i + 1;
		if (inputCharacter == '+' || inputCharacter == '-' || track == strLength - 1) {
			digitDetect = true;
		}
		if (!xDetect && !eDetect && !funcDetect && !consDetect) {
			if (inputCharacter == 'x') {
				if (i == strLength - 1) {
					i = strLength - 2;
				}
				xDetect = true, digitDetect = false, func += inputCharacter;
			}
			else if (digitDetect && (inputCharacter == '+' || inputCharacter == '-' || i == strLength - 1) && i != 0) {
				if (i == strLength - 1) {
					coeffAstr += inputCharacter;
				}
				if (inputCharacter == '+' || inputCharacter == '-')coeffAstr += inputCharacter;
				consDetect = true, func = "none";
			}
			else if (inputCharacter == 'e') eDetect = true, digitDetect = false, func += inputCharacter;
			else if (isalpha(inputCharacter) && inputCharacter != 'x' && inputCharacter != 'e') funcDetect = true, digitDetect = false;
			else if (inputCharacter != '(' && inputCharacter != ')') coeffAstr += inputCharacter;
		}
		else if (xDetect) {
			if (inputCharacter == '(') bracket = true;
			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
			else if (coeffAstr == "-") {
				coeffA = -1;
			}
			else coeffA = atoi(coeffAstr.c_str());
			// insert linear to term
			if (bracket) {
				if (inputCharacter == ')' || i == strLength - 1) {
					xDetect = false;
					if (powStr == "") pow = 1;
					else if (i == strLength - 1) {
						powStr += inputCharacter;
					}
					pow = atoi(powStr.c_str());
					if (func.compare("x")==0) {
						Term* newterm = new Power(coeffA, pow);
						appendTerm(newterm);
					}
					else {
						Term* newterm = new Linear(coeffA);
						appendTerm(newterm);
					}

					func = "";
					coeffAstr = "";
					coeffBstr = "";
					powStr = "";
					coeffA = 0;
					coeffB = 0;
					pow = 0;
					bracket = false;
				}
				else if (inputCharacter == '^') func += inputCharacter;
				else if (isdigit(inputCharacter) || inputCharacter == '-')powStr += inputCharacter;
			}
			else {
				// insert power to term
				if ((!isdigit(inputCharacter) && inputCharacter != '^') || i == strLength - 1) {
					xDetect = false;
					if (i == strLength - 1) {
						powStr += inputCharacter;
					}
					if (powStr == "") pow = 1;
					else pow = atoi(powStr.c_str());
					if (func.compare("x^")==0) {
						Term* newterm = new Power(coeffA, pow);
						appendTerm(newterm);
					}
					else {
						Term* newterm = new Linear(coeffA);
						appendTerm(newterm);
					}

					func = "";
					coeffAstr = inputCharacter;
					coeffBstr = "";
					powStr = "";
					coeffA = 0;
					coeffB = 0;
					pow = 0;
				}
				else if (inputCharacter == '^') func += inputCharacter;
				else if (isdigit(inputCharacter) || inputCharacter == '-')powStr += inputCharacter;
			}

		}
		if (eDetect) {
			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
			else if (coeffAstr == "-") {
				coeffA = -1;
			}
			else coeffA = atoi(coeffAstr.c_str());
			if (inputCharacter == 'x') {
				eDetect = false;
				if (coeffBstr == "") coeffB = 1;
				else if (coeffBstr == "-")coeffB = -1;
				else coeffB = atoi(coeffBstr.c_str());
				Term* newterm = new Exponential(coeffA, coeffB);
				appendTerm(newterm);
				func = "";
				coeffAstr = "";
				coeffBstr = "";
				powStr = "";
				coeffA = 0;
				coeffB = 0;
				pow = 0;
			}
			else if (inputCharacter == '^') func += inputCharacter;
			else if (inputCharacter != 'e' && inputCharacter != '^' && inputCharacter != '(') coeffBstr += inputCharacter;
		}
		if (consDetect) {
			coeffA = atoi(coeffAstr.c_str());
			consDetect = false;
			if (coeffA != 0) {
				Term* newterm = new Constant(coeffA);
				appendTerm(newterm);
				coeffAstr = "";
				coeffBstr = "";
				powStr = "";
				coeffA = 0;
				coeffB = 0;
				pow = 0;
			}
			func = "";
		}
		if (funcDetect) {
			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
			else if (coeffAstr == "-") {
				coeffA = -1;
			}
			else coeffA = atoi(coeffAstr.c_str());
			if (inputCharacter == ')') {
				funcDetect = false;
				if (coeffBstr == "") coeffB = 1;
				else if (coeffBstr == "-") coeffB = -1;
				else if (func == "log") {
					size_t remove = coeffBstr.find("10");
					coeffBstr.replace(remove, 2, "");
					if (coeffBstr == "") coeffB = 1;
					else if (coeffBstr == "-") coeffB = -1;
					else coeffB = atoi(coeffBstr.c_str());
				}
				else {
					coeffB = atoi(coeffBstr.c_str());
				}
				if (func == "loge") {
					Term* newterm = new LogE(coeffA, coeffB);
					appendTerm(newterm);
				}
				else if (func == "log") {
					Term* newterm = new Log10(coeffA, coeffB);
					appendTerm(newterm);
				}
				else if (func == "sin") {
					Term* newterm = new Sinusoidal(coeffA, coeffB);
					appendTerm(newterm);
				}
				else if (func == "cos") {
					Term* newterm = new Cosinusoidal(coeffA, coeffB);
					appendTerm(newterm);
				}
				func = "";
				coeffAstr = "";
				coeffBstr = "";
				powStr = "";
				coeffA = 0;
				coeffB = 0;
				pow = 0;
			}
			else if (isalpha(inputCharacter) && inputCharacter != 'x') func += inputCharacter;
			else if (isdigit(inputCharacter) || inputCharacter == '-')coeffBstr += inputCharacter;
		}

	}
}