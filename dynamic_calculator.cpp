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
	//infix = "1+(2-3)*4/5";
	infix = "(3+2*(3-1))/2";
	cout << infix<<endl;
	cout<<postfix(infix)<<endl;
	cout << evaluate(infix);
	//cout << "Question: " << infix << endl;

	cout << endl;
	system("pause");
	return 0;
}

char scan(int n) {
	return infix[n];
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
		if (isRightParenthesis(current_symbol)) { //right discard garni
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
	Num_Stack temp;
	float a, b, res, ans;
	int location = 0;
	char current_symbol = s[location];
	while (current_symbol) {
		if (isOperand(current_symbol)) {
			temp.push((float)convert(current_symbol));
		}
		if (isOperator(current_symbol)) {
			a = temp.pop();
			b = temp.pop();
			res = apply_operator(a, current_symbol, b);
			temp.push(res);
		}
		location++;
		current_symbol = s[location];
	}
	ans = temp.pop();
	return ans;
}