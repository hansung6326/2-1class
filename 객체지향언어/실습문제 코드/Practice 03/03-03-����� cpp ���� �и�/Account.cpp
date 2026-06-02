#include <iostream>
#include <string>
using namespace std;

#include "Account.h"

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

