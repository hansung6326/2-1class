#include <iostream>
#include <string>
using namespace std;

class Account {
	string name;
	int money = 0;
public:
	Account(string name);
	int deposit(int a) {
		money += a;
		return money;
	}
	string getOwner() {
		return name;
	}
	int inquiry() {
		return money;
	}
	int withdraw(int a) {
		if (money < a) {
			int tmp = money;
			money = 0;
			return tmp;
		}
		else {
			money -= a;
			return a;
		}
	}

};

Account::Account(string name) {
	this->name = name;
}

int main() {
	Account a("황수희");
	a.deposit(20000);
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(15000);
	cout << money << "원 출금, ";
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;
	money = a.withdraw(15000);
	cout << money << "원 출금, ";
	cout << a.getOwner() << "잔액은 " << a.inquiry() << endl;
}