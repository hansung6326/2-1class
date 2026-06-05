#include <iostream>
using namespace std;

class Exp {
	int base, exp;
public:
	Exp(int base = 1, int exp = 1);
	int calcValue();
	friend istream& operator >>(istream& ist, Exp& exp);
	friend ostream& operator <<(ostream& ost, Exp exp);
};

Exp::Exp(int base, int exp) {
	this->base = base;
	this->exp = exp;
}
int Exp::calcValue() {
	int sum = 1;
	for (int i = 0; i < exp; i++) {
		sum *= base;
	}
	return sum;
}

istream& operator >>(istream& ist, Exp& exp) {
	cout << "베이스: ";
	ist >> exp.base;
	cout << "지수: ";
	ist >> exp.exp;
	return ist;
}
ostream& operator <<(ostream& ost, Exp exp) {
	ost << exp.base << "의" << exp.exp << "승: " << exp.calcValue();
	return ost;
}

int main() {
	Exp a, b;
	cin >> a >> b;
	cout << a << endl << b << endl;
}
