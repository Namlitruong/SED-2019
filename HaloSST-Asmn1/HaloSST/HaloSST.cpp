// Ass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#define MAX 1000
//////////////////////////--Stack--/////////////////////////////
class Stack {
	int top;
public:
	char myStack[MAX];

	Stack() { top = -1; }
	bool push(char x);
	int pop();
	bool isEmpty();
	char Search(int index);
	int takeTop();
};

//pushes element on to the stack
bool Stack::push(char item)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow!!!";
		return false;
	}
	else {
		myStack[++top] = item;
		cout << item << endl;
		return true;
	}
}

//removes or pops elements out of the stack
int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow!!";
		return 0;
	}
	else {
		int item = myStack[top--];
		return item;
	}
}

int Stack::takeTop() {
	return top;
}

//check if stack is empty
bool Stack::isEmpty()
{
	return (top < 0);
}
//////////////////////////--Stack--/////////////////////////////

char iString[1000];
class Stack Expr;

char* SpaceEliminate(char*);
bool CheckExit(char *);
int InsertStack(char*, Stack&);
bool CheckOp(char);


int main()
{
	while (1) {
		cout << "___________________________________________________________\n";
		cout << "\n#NOTE: Input String cannot larger than 100 character." << endl;					//Acknowledge user the input constraint
		cout << "Input the elements of simple 2-argument Calculator:   ";
		cin.getline(iString, 1000);

		if (CheckExit(iString)) return 0;

		cout << "RETURN:   " << InsertStack(SpaceEliminate(iString), Expr) << endl;

		while (!Expr.isEmpty())
		{
			cout << Expr.pop() << endl;
		}
	}

	class Stack stack;
	cout << "The Stack Push " << endl;
	stack.push(2);
	stack.push(4);
	stack.push(6);
	cout << "The Stack Pop : " << endl;
	while (!stack.isEmpty())
	{
		cout << stack.pop() << endl;
	}
	return 0;

}

char* SpaceEliminate(char* iString) {
	int StartIndex = 0;
	int EndIndex = strlen(iString);
	char* Data = &(*iString);

	for (int i = 1; iString[i - 1] == ' '; i++) StartIndex = i;								// Check space from the front 
	for (int i = strlen(iString) - 1; iString[i] == ' '; i--) EndIndex = i - 1;				// Check space from the back  
	for (int i = 0; i <= (EndIndex - StartIndex); i++) Data[i] = iString[StartIndex + i];	// Take out the expression from 'Start Index' to 'End Index'
	Data[(EndIndex - StartIndex) + 1] = '\0';												// Add NULL at the end of the new string
	return Data;
}

bool CheckExit(char * iString) {
	if (!strcmp(iString, "Exit") || !strcmp(iString, "exit")) { // Consider both Capital (Exit) and non-capital (exit) of the first character to compare with the input string.
		cout << "LABORATORY GROUP HaloSST" << endl;
		cout << "s3518702, s3518702@rmit.edu.vn, Nam Truong" << endl;
		cout << "s3607833, s3607833@rmit.edu.vn, Tin Nguyen" << endl;
		cout << "s3618889, s3618889@rmit.edu.vn, Hoang Tran" << endl;
		return 1;
	}
	return 0;
}

bool CheckOp(char op) {
	if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '%') || (op == '^')) return true;
	return false;
}

int InsertStack(char* iData, Stack &Expr) {
	char subString[100];
	char temp[100];
	int count;
	for (int i = 0; i < strlen(iData); i++) {
		if (iData[i] != ' ') {
			Expr.push(iData[i]);
		}
		if (CheckOp(Expr.myStack[Expr.takeTop()]) && CheckOp(Expr.myStack[Expr.takeTop() - 1])) return 4;
		if (Expr.myStack[Expr.takeTop()] == ')' && Expr.myStack[Expr.takeTop() - 1] == '(') return 4;

		if (iData[i] == ')') {
			for (count = 0; Expr.myStack[Expr.takeTop()] != '('; count++) {
				temp[count] = Expr.pop();
			}
			temp[count] = '\0';

			for (unsigned int i = 0; i < strlen(temp); i++) {
				subString[i] = temp[strlen(temp) - i - 1];
			}
			subString[strlen(temp)-1] = '\0';

			cout << "CHECK:   " << subString << endl;
		}
	}

	return 0;
}
