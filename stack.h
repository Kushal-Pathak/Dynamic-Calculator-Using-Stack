#pragma once
#include<iostream>
using namespace std;

class Stack {
private:
	int tos = -1;
	char stack[100] = {};
	int max = 100;
public:
	void push(char value) {
		if (!isFull()) {
			tos++;
			stack[tos] = value;
		}
	}

	char pop() {
		if (!isEmpty()) {
			char temp;
			temp = stack[tos];
			tos--;
			return temp;
		}
		return ' ';
	}

	char top() {
		if (!isEmpty()) {
			return stack[tos];
		}
		return ' ';
	}

	void display() {
		for (int i = 0; i <= tos; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}

	int isEmpty() {
		if (tos == -1) return 1;
		return 0;
	}

	int isFull() {
		if (tos == max - 1) return 1;
		return 0;
	}
};

class Num_Stack {
private:
	int tos = -1;
	float stack[100] = {};
	int max = 100;
public:
	void push(float value) {
		if (!isFull()) {
			tos++;
			stack[tos] = value;
		}
	}

	float pop() {
		if (!isEmpty()) {
			float temp;
			temp = stack[tos];
			tos--;
			return temp;
		}
		return 0;
	}

	float top() {
		if (!isEmpty()) {
			return stack[tos];
		}
		return 0;
	}

	void display() {
		for (int i = 0; i <= tos; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}

	int isEmpty() {
		if (tos == -1) return 1;
		return 0;
	}

	int isFull() {
		if (tos == max - 1) return 1;
		return 0;
	}
};

