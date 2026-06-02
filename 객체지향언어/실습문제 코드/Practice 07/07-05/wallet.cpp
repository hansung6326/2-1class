#include <iostream>
using namespace std;

class Wallet {
	string owner;
	int money;
public:
	Wallet(string owner="", int money = 0) {
		this->owner = owner;
		this->money = money;
	}
	void show() { cout << owner << " 지갑에 " << money << "원 있어요." << endl; }
	Wallet& operator += (int money); // += 연산자 함수
	Wallet& operator -= (int money); // -= 연산자 함수
	Wallet operator + (Wallet b); // + 연산자 함수
	Wallet operator + (int money); // + 연산자 함수
	Wallet& operator = (Wallet b); // = 연산자 함수
	friend Wallet operator + (int money, Wallet& b); // + 연산자 함수
};

Wallet& Wallet::operator += (int money) {
	this->money += money;
	return *this;
}

Wallet& Wallet::operator -= (int money) {
	this->money -= money;
	return *this;
}

Wallet Wallet::operator + (Wallet b) {
	Wallet tmp;
	tmp.money = money + b.money;
	return tmp;
}

Wallet Wallet::operator + (int money) {
	Wallet tmp;
	tmp.money = this->money + money;
	return tmp;
}

Wallet& Wallet::operator = (Wallet b) {
	// 지갑 주인의 이름을 복사하지 않는다.
	this->money = b.money;
	return *this;
}

// 외부 함수로 + 연산자 구현
Wallet operator + (int money, Wallet& b) {
	Wallet tmp;
	tmp.money = b.money + money;
	return tmp;
}

int main() {
	Wallet a("옥지윤", 2000), b("성주연", 100), c("박채원"); // 박채원 지갑은 0원
	a += 1000; a.show();
	a -= 500; a.show();
	b = a + b + 100;  // = 연산자는 금액만 복사
	b.show(); // b의 주인은 "성주연"으로 출력
	c = 500 + b; // = 연산자는 금액만 복사
	c.show(); // c의 주인은 "박채원"으로 출력
}