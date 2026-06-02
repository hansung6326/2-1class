#include <iostream>
#include <string>
using namespace std;

class Account {
	string owner;
	int balance;
public:
	Account(string n);
	void deposit(int money);
	int withdraw(int money);
	int inquiry();
	string getOwner() { return owner; }
};

Account::Account(string n) {
	owner = n;
	balance = 0;
}

void Account::deposit(int money) {
	balance += money;
}

int Account::withdraw(int money) {
	if (money > balance) { // 저축된 돈이 찾는 금액보자 작은 경우
		money = balance;
		balance = 0;
	}
	else
		balance -= money;

	return money; // 실제 찾은 금액 리턴
}

int Account::inquiry() {
	return balance;
}

int main() {
	Account a("황수희"); // "황수희" 이름의 계좌 생성
	a.deposit(20000); // 20000원 저금
	cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(15000); // 15000원 출금. withdraw()는 15000 리턴
	cout << money << "원 출금, ";
	cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
	money = a.withdraw(8000); // 8000원 출금 시도. withdraw()는 잔액 5000 리턴
	cout << money << "원 출금, ";
	cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
}