#include <iostream>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();

};
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee = c;
	water = w;
	sugar = s;
	
}

void CoffeeMachine::drinkEspresso() {
	if (coffee < 1 || water < 1) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	coffee--;
	water--;
	cout << "에스프레소 나왔습니다" << endl;
}
void CoffeeMachine::drinkAmericano() {
	if (coffee < 1 || water < 2) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	coffee--;
	water -= 2;
	cout << "아메리카노 나왔습니다" << endl;
}
void CoffeeMachine::drinkSugarCoffee() {
	if (coffee < 1 || water < 2 || sugar < 1) {
		cout << "원료가 부족합니다." << endl;
		return;
	}
	coffee--;
	water -= 2;
	sugar--;
	cout << "설탕 커피 나왔습니다" << endl;
}
void CoffeeMachine::show() {
	cout << "[머신 상태] 커피:" << coffee << "\t 물:" << water << "\t 설탕:" << sugar << endl;
}
void CoffeeMachine::fill() {
	coffee = water = sugar = 10;
}



int main() {
	CoffeeMachine java(2, 3 ,1);
/*	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show(); */

	while (true) {
		cout << "에:1, 아:2, 설:3, show:4, fill:5 >>";
		int menu;
		cin >> menu;
		switch (menu) {
		case 1: java.drinkEspresso(); break;
		case 2: java.drinkAmericano(); break;
		case 3: java.drinkSugarCoffee(); break;
		case 4: java.show(); break;
		case 5: java.fill(); break;
		case 6: return 0;
		}
	}
}