#include <iostream>
using namespace std;

#include "MyStack.h"

MyStack::MyStack() { }

bool MyStack::push(int n) {
	if (tos == 10)
		return false; // stack full
	p[tos] = n;
	tos++;
	return true;
}

bool MyStack::pop(int& n) {
	if (tos == 0)
		return false; // stack empty
	tos--;
	n = p[tos];
	return true;
}