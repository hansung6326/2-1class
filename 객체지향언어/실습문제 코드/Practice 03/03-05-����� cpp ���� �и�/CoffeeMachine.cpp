#include <iostream>
using namespace std;

#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee = c;
	water = w;
	sugar = s;
}
void CoffeeMachine::drinkEspresso() { // 커피 1, 물 1 소비
	if (coffee < 1 || water < 1)
		return;
	// 커피 1, 물 1 소비	
	coffee--;
	water--;
}
void CoffeeMachine::drinkAmericano() { // 커피 1, 물 2 소비
	if (coffee < 1 || water < 2)
		return;

	// 커피 1, 물 2 소비
	coffee--;
	water-=2;
}
void CoffeeMachine::drinkSugarCoffee() {// 커피 1, 물 2, 설탕 1 소비
	if (coffee < 1 || water < 2 || sugar < 1)
		return;

	// 커피 1, 물 2, 설탕 1 소비
	coffee--;
	water -= 2;
	sugar--;

}
void CoffeeMachine::fill() { // 커피 10, 물 10, 설탕 10으로 채우기
	coffee = 10;
	water = 10;
	sugar = 10;
}

void CoffeeMachine::show() { // 잔량 출력
	cout << "[머신 상태] 커피:" << coffee << "\t";
	cout << "물:" << water << "\t";
	cout << "설탕:" << sugar << "\t" << endl;
}