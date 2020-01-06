#include "pch.h"
//#include "Poly.h"
//#include <iostream>
//#include "Cosinusoidal.h"
//#include "Linear.h"
//#include "Sinusoidal.h"
//#include "Log10.h"
//#include "LogE.h"
//#include "Power.h"
//#include "Constant.h"
//#include "Exponential.h"
//using namespace std;
//Poly::Poly()
//{
//}
//
//Poly::~Poly()
//{
//}
//
//Poly::Poly(std::string userInput)
//{
//	this->userInput = userInput;
//}
//void Poly::insertTerm(Term* term) {
//	Term* current = NULL;
//	term->setNextTerm(NULL);
//	if (head == NULL) {
//		head = term;
//	}
//	else {
//		current = head;
//		while (current->getNext() != NULL) {
//			current = current->getNext();
//		}
//		current->setNextTerm(term);
//	}
//}
//void Poly::constructPoly() {
//	int strLength = userInput.length();
//	int coeffA = 0;
//	int coeffB = 0;
//	int pow = 0;
//	string coeffAstr = "";
//	string coeffBstr = "";
//	string powStr = "";
//	string func = "";
//	bool xDetect = false;
//	bool eDetect = false;
//	bool funcDetect = false;
//	bool consDetect = false;
//	bool digitDetect = false;
//	bool bracket = false;
//	int track = 0;
//	for (int i = 0; i < strLength; i++) {
//		char current_char = userInput[i];
//		track = i + 1;
//		//check +/-
//		if (current_char == '+' || current_char == '-' || track == strLength - 1) {
//			digitDetect = true;
//		}
//
//		if (!xDetect && !eDetect && !funcDetect && !consDetect) {
//			if (current_char == 'x') {
//				if (i == strLength - 1) {
//					i = strLength - 2;
//				}
//				xDetect = true, digitDetect = false, func += current_char;
//			}
//			else if (digitDetect && (current_char == '+' || current_char == '-' || i == strLength - 1) && i != 0) {
//				if (i == strLength - 1) {
//					coeffAstr += current_char;
//				}
//				if (current_char == '+' || current_char == '-')coeffAstr += current_char;
//				consDetect = true, func = "none";
//			}
//			else if (current_char == 'e') eDetect = true, digitDetect = false, func += current_char;
//			else if (isalpha(current_char) && current_char != 'x' && current_char != 'e') funcDetect = true, digitDetect = false;
//			else if (current_char != '(' && current_char != ')') coeffAstr += current_char;
//		}
//		else if (xDetect) {
//			if (current_char == '(') bracket = true;
//			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
//			else if (coeffAstr == "-") {
//				coeffA = -1;
//			}
//			else coeffA = atoi(coeffAstr.c_str());
//			if (bracket) {
//				if (current_char == ')' || i == strLength - 1) {
//					xDetect = false;
//					if (powStr == "") pow = 1;
//					else if (i == strLength - 1) {
//						powStr += current_char;
//					}
//					pow = atoi(powStr.c_str());
//					if (func == "x^") {
//						Term* newterm = new Power(coeffA, pow);
//						insertTerm(newterm);
//					}
//					else {
//						Term* newterm = new Linear(coeffA);
//						insertTerm(newterm);
//					}
//
//					func = "";
//					coeffAstr = "";
//					coeffBstr = "";
//					powStr = "";
//					coeffA = 0;
//					coeffB = 0;
//					pow = 0;
//					bracket = false;
//				}
//				else if (current_char == '^') func += current_char;
//				else if (isdigit(current_char) || current_char == '-')powStr += current_char;
//			}
//			else {
//				if ((!isdigit(current_char) && current_char != '^') || i == strLength - 1) {
//					xDetect = false;
//					if (i == strLength - 1) {
//						powStr += current_char;
//					}
//					if (powStr == "") pow = 1;
//					else pow = atoi(powStr.c_str());
//					if (func == "x^") {
//						Term* newterm = new Power(coeffA, pow);
//						insertTerm(newterm);
//					}
//					else {
//						Term* newterm = new Linear(coeffA);
//						insertTerm(newterm);
//					}
//
//					func = "";
//					coeffAstr = current_char;
//					coeffBstr = "";
//					powStr = "";
//					coeffA = 0;
//					coeffB = 0;
//					pow = 0;
//				}
//				else if (current_char == '^') func += current_char;
//				else if (isdigit(current_char) || current_char == '-')powStr += current_char;
//			}
//
//		}
//		if (eDetect) {
//			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
//			else if (coeffAstr == "-") {
//				coeffA = -1;
//			}
//			else coeffA = atoi(coeffAstr.c_str());
//			if (current_char == 'x') {
//				eDetect = false;
//				if (coeffBstr == "") coeffB = 1;
//				else if (coeffBstr == "-")coeffB = -1;
//				else coeffB = atoi(coeffBstr.c_str());
//				Term* newterm = new Exponential(coeffA, coeffB);
//				insertTerm(newterm);
//				func = "";
//				coeffAstr = "";
//				coeffBstr = "";
//				powStr = "";
//				coeffA = 0;
//				coeffB = 0;
//				pow = 0;
//			}
//			else if (current_char == '^') func += current_char;
//			else if (current_char != 'e' && current_char != '^' && current_char != '(') coeffBstr += current_char;
//		}
//		if (consDetect) {
//			coeffA = atoi(coeffAstr.c_str());
//			consDetect = false;
//			if (coeffA != 0) {
//				Term* newterm = new Constant(coeffA);
//				insertTerm(newterm);
//				coeffAstr = "";
//				coeffBstr = "";
//				powStr = "";
//				coeffA = 0;
//				coeffB = 0;
//				pow = 0;
//			}
//			func = "";
//		}
//		if (funcDetect) {
//			if (coeffAstr == "" || coeffAstr == "+") coeffA = 1;
//			else if (coeffAstr == "-") {
//				coeffA = -1;
//			}
//			else coeffA = atoi(coeffAstr.c_str());
//			if (current_char == ')') {
//				funcDetect = false;
//				if (coeffBstr == "") coeffB = 1;
//				else if (coeffBstr == "-") coeffB = -1;
//				else if (func == "log") {
//					size_t remove = coeffBstr.find("10");
//					coeffBstr.replace(remove, 2, "");
//					if (coeffBstr == "") coeffB = 1;
//					else if (coeffBstr == "-") coeffB = -1;
//					else coeffB = atoi(coeffBstr.c_str());
//				}
//				else {
//					coeffB = atoi(coeffBstr.c_str());
//				}
//				if (func == "loge") {
//					Term* newterm = new LogE(coeffA, coeffB);
//					insertTerm(newterm);
//				}
//				else if (func == "log") {
//					Term* newterm = new Log10(coeffA, coeffB);
//					insertTerm(newterm);
//				}
//				else if (func == "sin") {
//					Term* newterm = new Sinusoidal(coeffA, coeffB);
//					insertTerm(newterm);
//				}
//				else if (func == "cos") {
//					Term* newterm = new Cosinusoidal(coeffA, coeffB);
//					insertTerm(newterm);
//				}
//				func = "";
//				coeffAstr = "";
//				coeffBstr = "";
//				powStr = "";
//				coeffA = 0;
//				coeffB = 0;
//				pow = 0;
//			}
//			else if (isalpha(current_char) && current_char != 'x') func += current_char;
//			else if (isdigit(current_char) || current_char == '-')coeffBstr += current_char;
//		}
//
//	}
//
//}
//void Poly::printResult() {
//	string output = "result: ";
//	Term* current = head;
//	bool isFirstNumber = false;
//	while (current != NULL) {
//		current->differentiate();
//		int coeff = current->getCoeff();
//		if (!isFirstNumber) {
//			output += "";
//			isFirstNumber = true;
//			output += current->getResult();
//		}
//		else if (coeff > 0) {
//			output += "+";
//			output += current->getResult();
//		}
//		else if (coeff == 0 && current->getResult() != "0") {
//
//			output += "";
//		}
//		else if (coeff == 0) {
//			output += "";
//		}
//		else {
//			output += current->getResult();
//		}
//		current = current->getNext();
//	}
//
//	cout << endl;
//	cout << output << endl;
//}
//bool Poly::scanCharacter()
//{
//
//	int strLength = userInput.length();
//	for (int i = 0; i < strLength; i++) {
//		char current_char = userInput[i];
//		if (current_char != 'x' && !isdigit(current_char) && current_char != '*' && current_char != ')'
//			&& current_char != '(' && current_char != 'l' && current_char != 'o' && current_char != 'g'
//			&& current_char != 'e' && current_char != 's' && current_char != 'i' && current_char != 'n'
//			&& current_char != 'c' && current_char != '^' && current_char != '+' && current_char != '-') {
//			cout << "Error: Invalid character: " << current_char << " at index " << i << endl;
//			return false;
//		}
//	}
//	return true;
//}
//
//bool Poly::checkPoly()
//{
//	int strLength = userInput.length();
//	bool bracketFound = false;
//	bool mulDetect = false;
//	bool digitDetect = false;
//	bool signDetect = false;
//	string term = "";
//	for (int i = 0; i < strLength; i++) {
//		char current_char = userInput[i];
//		if ((current_char == '+' || current_char == '-') && i != 0 && userInput[i - 1] != '(') {
//
//			if (term == "" || i == strLength - 1) return false;
//			else {
//				if (!checkTerm(term)) {
//					cout << "invalid term: " << term << endl;
//					return false;
//				}
//				term = "";
//
//			}
//
//
//		}
//		else {
//			if (current_char != '+' && current_char != '-') term += current_char;
//			if (i == strLength - 1) {
//				if (!checkTerm(term)) {
//					cout << "invalid term: " << term << endl;
//					return false;
//				}
//			}
//		}
//
//	}
//	return true;
//}
//
//bool Poly::checkTerm(std::string term)
//{
//	int termLength = term.length();
//	bool coeffADetect = false;
//	bool coeffBDetect = false;
//	bool mulADetect = false;
//	bool mulBDetect = false;
//	bool xDetect = false;
//	bool powDetect = false;
//	bool openBracket = false;
//	bool closeBracket = false;
//	bool xBDetect = false;
//	bool eDetect = false;
//	bool logDetect = false;
//	bool sinDetect = false;
//	bool cosDetect = false;
//	bool secondxDetect = false;
//	for (int i = 0; i < termLength; i++) {
//		char current_char = term[i];
//		if (coeffADetect && !isdigit(current_char) && current_char != '*' && current_char != ')') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if (mulADetect && current_char != 'x' && current_char != 'e' && current_char != 'l'
//			&& current_char != 's' && current_char != 'c') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if ((eDetect == true) && current_char != '^' && current_char != '(' && !secondxDetect && current_char == ')') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if (powDetect && current_char != '(') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//
//		if (openBracket && current_char != 'x' && !isdigit(current_char)) {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if (coeffBDetect && !isdigit(current_char) && current_char != ')' && current_char != '*') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if (mulBDetect && current_char != 'x') {
//			cout << "Invalid char: " << current_char << endl;
//			return false;
//		}
//		if (xBDetect && current_char != ')') {
//			cout << "Invalid char:" << current_char << endl;
//			return false;
//		}
//		if (logDetect) {
//			if (current_char == 'o' && term[i + 1] == 'g') {
//				if (term[i + 2] == '1' && term[i + 3] == '0' && term[i + 4] == '(') {
//					i = i + 3;
//				}
//				else if (term[i + 2] == 'e' && term[i + 3] == '(') {
//					i = i + 2;
//				}
//				else {
//					return false;
//				}
//			}
//			else if (secondxDetect) {
//				return false;
//			}
//		}
//		if (sinDetect) {
//			if (current_char == 'i' && term[i + 1] == 'n' && term[i + 2] == '(') {
//				i = i + 1;
//			}
//			else if (secondxDetect) {
//				return false;
//			}
//		}
//		if (cosDetect) {
//			if (current_char == 'o' && term[i + 1] == 's' && term[i + 2] == '(') {
//				i = i + 1;
//			}
//			else if (secondxDetect) {
//				return false;
//			}
//		}
//
//		if (!coeffADetect && isdigit(current_char) && !openBracket) {
//			coeffADetect = true;
//		}
//		if (coeffADetect && current_char == '*' && !mulADetect) {
//			mulADetect = true;
//			coeffADetect = false;
//		}
//
//
//		if (current_char == 'x' && !xDetect) {
//			mulADetect = false;
//			xDetect = true;
//		}
//		if (current_char == 'e' && !eDetect) {
//			if (i == termLength - 1) {
//				return false;
//			}
//			eDetect = true;
//			mulADetect = false;
//		}
//		if (current_char == 'l' && !logDetect) {
//			if (i == termLength - 1) {
//				return false;
//			}
//			mulADetect = false;
//			logDetect = true;
//		}
//		if (current_char == 's' && !sinDetect) {
//			if (i == termLength - 1) {
//				return false;
//			}
//			mulADetect = false;
//			sinDetect = true;
//		}
//		if (current_char == 'c' && !cosDetect) {
//			if (i == termLength - 1) {
//				return false;
//			}
//			mulADetect = false;
//			cosDetect = true;
//		}
//		if (current_char == '^' && !powDetect) {
//			if (i == termLength - 1) {
//				return false;
//			}
//			if (!xDetect) {
//				powDetect = true;
//			}
//			else {
//				powDetect = false;
//			}
//		}
//		if ((sinDetect || cosDetect || logDetect) && !secondxDetect && current_char == 'x') {
//			secondxDetect = true;
//		}
//		if (eDetect && !secondxDetect && current_char == 'x') {
//			secondxDetect = true;
//			eDetect = false;
//		}
//		if (current_char == '(' && !openBracket) {
//			if (i == termLength - 1) {
//				cout << "open bracket detect invalid end" << endl;
//				return false;
//			}
//			powDetect = false;
//			openBracket = true;
//		}
//		if (isdigit(current_char) && openBracket) {
//			if (i == termLength - 1) {
//				cout << "coeff B detect invalid end" << endl;
//				return false;
//			}
//			openBracket = false;
//			coeffBDetect = true;
//		}
//
//		if (coeffBDetect && current_char == '*') {
//			if (i == termLength - 1) {
//				cout << "multiply B detect invalid end" << endl;
//				return false;
//			}
//			mulBDetect = true;
//			coeffBDetect = false;
//		}
//		if (coeffBDetect && i == termLength - 1 && current_char != ')') {
//			return false;
//		}
//		if ((sinDetect || cosDetect || logDetect) && !secondxDetect && current_char == ')') {
//			cout << "Wrong input format at term: " << term << endl;
//			return false;
//		}
//		if ((mulBDetect || openBracket) && current_char == 'x') {
//			if (i == termLength - 1) {
//				return false;
//			}
//			xDetect = false;
//			xBDetect = true;
//			mulBDetect = false;
//			openBracket = false;
//			secondxDetect = false;
//			cosDetect = false;
//			sinDetect = false;
//			logDetect = false;
//
//		}
//	}
//	return true;
//}
