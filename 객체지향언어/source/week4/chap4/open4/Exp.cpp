#include <iostream>
using namespace std;

#include "Exp.h"

Exp::Exp() {
	base = 1;
	exp = 1;
}
Exp::Exp(int b) {
	base = b;
	exp = 1;
}
Exp::Exp(int b, int e) {
	base = b;
	exp = e;
}
int Exp::getValue() {
	int sum=1;
	for (int i = 0; i < exp; i++)
		sum *= base;
	return sum;
}
bool Exp::equals(Exp b) {
	if (getValue() == b.getValue())
		return 1;
	else
		return 0;
}
/* int Exp::getBase() {
	return base;
}
int Exp::getExp() {
	return exp;
} */