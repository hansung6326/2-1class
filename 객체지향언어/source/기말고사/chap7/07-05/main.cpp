#include <iostream>
using namespace std;

class Wallet {
	string name;
	int money;
public:
	Wallet(string name, int money = 0) {
		this->name = name;
		this->money = money;
	}
	void show() {
		cout << name << " 지갑에 " << money << "원 있어요." << endl;
	}
	Wallet& operator +=(int op) {
		money += op;
		return *this;
	}
	Wallet& operator -=(int op) {
		money -= op;
		return *this;
	}
	Wallet& operator =(int op) {
		money = op;
		return *this;
	}
	int operator +(Wallet op) {
		return money + op.money;
	}
	int operator +(int op) {
		return money + op;
	}
	friend int operator +(int op1, Wallet op2);
};

int operator +(int op1, Wallet op2) {
	return op1 + op2.money;
}

int main() {
	Wallet a("옥지윤", 2000), b("성주윤", 100), c("박채원");
	a += 1000;
	a.show();
	a -= 500;
	a.show();
	b = a + b + 100;
	b.show();
	c = 500 + b;
	c.show();
}