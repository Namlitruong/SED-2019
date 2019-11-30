// Ass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#define MAX 1000
//////////////////////////--Stack--/////////////////////////////
class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size = MAX);     // constructor
    ~Stack();                   // destructor
 
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Destructor to free memory allocated to the stack
Stack::~Stack()
{
    delete arr;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!!!";
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

//removes or pops elements out of the stack
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!!";
		return 0;
    }
 
    cout << "Removing " << peek() << endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

int Stack::size()
{
    return top + 1;
}

int Stack::peek()
{
    if (!isEmpty()){
        return arr[top];
	}
}
//check if stack is empty
bool Stack::isEmpty()
{
    return top == -1;    // or return size() == 0;
}
bool Stack::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}

//////////////////////////--Stack--/////////////////////////////

char iString[1000];
class Stack Expr;

char* SpaceEliminate(char*);
bool CheckExit(char *);
int InsertStack(char*, Stack&);
bool CheckOp(char);
bool CheckSciCalChar(char);

int constructEvalStack(string);
int opPrecedence(char);
int evaluateExp(int, int, char);


int main()
{
	while (1) {
		cout << "___________________________________________________________\n";
		cout << "\n#NOTE: Input String cannot larger than 100 character." << endl;					//Acknowledge user the input constraint
		cout << "Input the elements of simple 2-argument Calculator:  \r\n";
		// cin.getline(iString, 1000);

		strcpy(iString, "(4+5)");
		cout << constructEvalStack(iString);
		break;

		// if (CheckExit(iString)) return 0;

		// cout << "RETURN:   " << InsertStack(SpaceEliminate(iString), Expr) << endl;

		// while (!Expr.isEmpty())
		// {
		// 	cout << Expr.pop() << endl;
		// }
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

bool CheckSciCalChar(char op) {
	if (CheckOp(op) || (op == '.') || (op == 'e') || (op == 'E')) return true;
	return false;
}

int InsertStack(char* iData, Stack &Expr) {
	char subString[100];
	char temp[100];
	int count;
	bool flagOp = false;
	int Left = 0, Right = 0;

	for (int i = 0; i < strlen(iData); i++) {
		//Check for invalid char
		if (!(isdigit(iData[i]) || CheckSciCalChar(iData[i]) || iData[i] == ')' || iData[i] == '(')) return 10;
		//Check First index= 
		if ((iData[0] == '*' ||iData[0] == '/' ||iData[0] == '%' ||iData[0] == '^')) return 1;
		//Check empty parentheses
		if (iData[i] == ')' && iData[i - 1] == '(') return 1;
		if (iData[i-1] == ')' && iData[i] == '(') return 1;
		//Check Op
		cout << "CHECK:   " << iData[i] << "   CHECK2:   "<< flagOp << "   CHECK3:   " << !isdigit(iData[i]) <<endl;
		if (!isdigit(iData[i]) && flagOp) return 2;
		if ((CheckSciCalChar(iData[i]) && CheckSciCalChar(iData[i - 1])) || (CheckSciCalChar(iData[i]) && iData[i - 1] == '(') || CheckSciCalChar(iData[0])) flagOp = true;
		if (isdigit(iData[i]) || iData[i] == '(') flagOp = false;
		if ((iData[i] == '*' ||
			iData[i] == '/' ||
			iData[i] == '%' ||
			iData[i] == '^') &&
			CheckSciCalChar(iData[i-1])) return 3;
		//Check numb of parentheses
		if (iData[i] == '(') Left++;
		if (iData[i] == ')') Right++;
	}
	if (Left != Right) return 4;

	cout << "CHECK:   " << iData << endl;

	return 0;
}

/*int InsertStack(char* iData, Stack &Expr) {
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

			cout << "CHECK:   " << Expr.myStack << endl;
		}
	}

	return 0;
}*/

int constructEvalStack(string f_str){
	int idx = 0;
	Stack opt_stk(500), val_stk(500);

	for (idx = 0; idx < f_str.length(); idx++)
	{
		int tempVal = f_str[idx];

		// Input is Number
		if (isdigit(f_str[idx])){
			cout << "Input is Number\r\n";

			int val = 0; 
            while (idx < f_str.length() && isdigit(f_str[idx])) { 
				// Next decimal (* 10) + ASCII number of Integer
                val = (val * 10) + (f_str[idx] - '0'); 
				
				if (!isdigit(f_str[idx + 1]) ){
					break;
				}
				else {
					idx++;
				}
            } 
			val_stk.push(val);
		}

		// Input is Opening Parenthesis
		else if (f_str[idx] == '('){
			cout << "Input is Opening\r\n";

			opt_stk.push(f_str[idx]);
		}
		// Input is Closing Parenthesis
		else if (f_str[idx] == ')'){
			cout << "Input is Closing\r\n";

			while (!opt_stk.isEmpty() && opt_stk.pop() != '('){
				int arg2 = val_stk.pop();

				int arg1 = val_stk.pop();

				char op = opt_stk.pop();

				val_stk.push(evaluateExp(arg1,arg2,op));
			}

		}
		// Input is Operator 
		else {
			cout << "Input is Operator\r\n";

			while (!opt_stk.isEmpty() 
				&& opPrecedence(opt_stk.pop()) >= opPrecedence(f_str[idx]) ){ 

                int arg2 = val_stk.pop(); 

                int arg1 = val_stk.pop(); 
                  
                char op = opt_stk.pop(); 
                  
                val_stk.push(evaluateExp(arg1, arg2, op)); 
            } 
              
            opt_stk.push(f_str[idx]);
		}
	}

	while (!opt_stk.isEmpty()){
		int arg2 = val_stk.pop(); 

		int arg1 = val_stk.pop(); 
			
		char op = opt_stk.pop(); 
			
		val_stk.push(evaluateExp(arg1, arg2, op)); 		
	}
	int temp = val_stk.pop();
	return temp;
}

int opPrecedence(char op){ 
    if(op == '+'||op == '-') {
		return 1; 
	}

    if(op == '*'||op == '/') {
		return 2; 
	}
    
	// Else
	return 0; 
} 
  
int evaluateExp(int arg1, int arg2, char op){ 
    switch(op){ 
        case '+': return arg1 + arg2; 
        case '-': return arg1 - arg2; 
        case '*': return arg1 * arg2; 
        case '/': return arg1 / arg2;
		case '^': return arg1 ^ arg2;
    } 
} 