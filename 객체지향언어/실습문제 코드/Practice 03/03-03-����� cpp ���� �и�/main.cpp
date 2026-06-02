#include <iostream>
#include <string>
using namespace std;

#include "Account.h"

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