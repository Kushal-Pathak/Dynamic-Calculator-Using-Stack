#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

string infix;
char scan(int);
int isOperator(char);
int isOperand(char);
int isLeftParenthesis(char);
int isRightParenthesis(char);
int precedence(char);
int convert(char);
float apply_operator(float,char,float);
string postfix(string);
float evaluate(string);

int main() {
	cout << "Enter expression eg: 2+3*(2-1)+1 : ";
	cin >> infix;
	cout << evaluate(postfix(infix)) << endl;
	system("pause");
	return 0;
}

string postfix() {
	string post;
	int location = 0;
	char current_symbol = infix[location];
	while (current_symbol) {
		
		location++;
		current_symbol = infix[location];
	}
	return post;
}

int isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int isOperand(char c) {
	if (!isOperator(c) && !isLeftParenthesis(c) && !isRightParenthesis(c)) return 1;
	return 0;
}

int isLeftParenthesis(char c) {
	if (c == '(') return 1;
	return 0;
}

int isRightParenthesis(char c) {
	if (c == ')') return 1;
	return 0;
}

int precedence(char c) {
	switch (c) {
	case '/': return 4;
	case '*': return 4;
	case '+': return 3;
	case '-': return 3;
	default: return 0;
	}
}

string postfix(string s) {
	Stack temp2;
	string post;
	int location = 0;
	char current_symbol = s[location];
	while (current_symbol) {
		if (isOperand(current_symbol)) post += current_symbol;
		if (isLeftParenthesis(current_symbol)) temp2.push(current_symbol);
		if (isRightParenthesis(current_symbol)) { 
			while (temp2.top() != '(') {
				post += temp2.pop();
			}
			temp2.pop();
		}
		if (isOperator(current_symbol)) {
			while (precedence(temp2.top()) >= precedence(current_symbol)) {
				post += temp2.pop();
			}
			temp2.push(current_symbol);
		}
		location++;
		current_symbol = s[location];
	}
	while (!temp2.isEmpty()) {
		post += temp2.pop();
	}
	return post;
}

int convert(char c) {
	if (isOperand(c)) {
		switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
		}
	}
	return 0;
}

float apply_operator(float a, char op, float b) {
	switch (op) {
	case '+': return a + b; 
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: return 0;
	}
	return 0;
}

float evaluate(string s) {
	Num_Stack stack;
	char current_symbol = ' ';
	for(int i = 0; i < s.length(); i++){
		current_symbol = s[i];
		if (isOperand(current_symbol)) stack.push((float)convert(current_symbol));
		if (isOperator(current_symbol)) {
			float a = stack.pop(), b = stack.pop();
			float c = apply_operator(b, current_symbol, a);
			stack.push(c);
		}
	}
	return stack.pop();
}
