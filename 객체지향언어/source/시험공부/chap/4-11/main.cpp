#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() {
		size = 10;
	}
	void fill(int n);
	bool consume(int n);
	int getSize();
};
void Container::fill(int n) {
	size = n;
}
bool Container::consume(int n) {
	
	if (size < n) {
		return false;
	}
	size -= n;
	return true;
}
int Container::getSize() {
	return size;
}

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void getEspresso();
	void getAmericano();
	void getSugarCoffee();
	void show();
public:
	void run();
};
void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10);
	}
}
void CoffeeVendingMachine::getEspresso() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
		cout << "원료가 부족합니다" << endl;
		return;
	}
	tong[0].consume(1);
	tong[1].consume(1);

	cout << "에스프레소 드세요" << endl;
}
void CoffeeVendingMachine::getAmericano() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
		cout << "원료가 부족합니다" << endl;
		return;
	}
	tong[0].consume(1);
	tong[1].consume(2);

	cout << "아메리카노 드세요" << endl;
}
void CoffeeVendingMachine::getSugarCoffee() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
		cout << "원료가 부족합니다" << endl;
		return;
	}
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);

	cout << "설탕커피 드세요" << endl;
}
void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << "," << "물 " << tong[1].getSize() << ","
		<< "설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	int choice;

	cout << "***** 커피자판기를 작동합니다. *****" << endl;

	while (1) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기, 0:종료) >> ";
		cin >> choice;
		switch (choice) {
		case 0:
			return;
		case 1:
			getEspresso();
			break;
		case 2:
			getAmericano();
			break;
		case 3:
			getSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		default:
			cout << "잘못된 입력입니다" << endl;
		}
	}
}

int main() {
	CoffeeVendingMachine coffee;
	coffee.run();

	return 0;
}