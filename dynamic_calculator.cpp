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
Stack postfix(string);
float evaluate(Stack);

int main() {
	Stack s1, s2;
	//infix = "1+2-3*4/5";
	cin >> infix;
	s1 = postfix(infix);
	cout << "Question: " << infix << endl;
	cout << "Ans: " << evaluate(s1);
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

Stack postfix(string s) {
	Stack temp1, temp2;
	int location = 0;
	char current_symbol = s[location];
	while (current_symbol) {
		if (isOperand(current_symbol)) temp1.push(current_symbol);
		if (isLeftParenthesis(current_symbol)) temp2.push(current_symbol);
		if (isRightParenthesis(current_symbol)) { //right discard garni
			while (temp2.top() != '(') {
				temp1.push(temp2.pop());
			}
			temp2.pop();
		}
		if (isOperator(current_symbol)) {
			while (precedence(temp2.top()) >= precedence(current_symbol)) {
				temp1.push(temp2.pop());
			}
			temp2.push(current_symbol);
		}
		location++;
		current_symbol = s[location];
	}
	while (!temp2.isEmpty()) {
		temp1.push(temp2.pop());
	}
	return temp1;
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

float evaluate(Stack s) {
	Num_Stack temp;
	float a, b, res;
	float ans;
	char current_symbol = s.pop();
	while (!s.isEmpty()) {
		if (isOperand(current_symbol)) {
			temp.push((float)convert(current_symbol));
		}
		if (isOperator(current_symbol)) {
			a = temp.pop();
			b = temp.pop();
			res = apply_operator(a, current_symbol, b);
			temp.push(res);
		}
		current_symbol = s.pop();
	}
	ans = temp.pop();
	return ans;
}