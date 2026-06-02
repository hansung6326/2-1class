#include <iostream>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar; // 전체 커피, 물량, 설탕 량
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso(); // 커피 1, 물 1 소비	
	void drinkAmericano(); // 커피 1, 물 2 소비
	void drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
	void fill(); // 커피 10, 물 10, 설탕 10으로 채우기
	void show(); // 잔량 출력
};

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
	water -= 2;
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

int main() {
	CoffeeMachine java(5, 10, 6); // 커피:5, 물:10, 설탕:6으로 초기화
	java.drinkEspresso(); // 커피 1, 물 1 소비	
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkAmericano(); // 커피 1, 물 2 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
	java.show(); // 현재 커피 머신의 상태 출력
	java.fill(); // 커피 10, 물 10, 설탕 10으로 채우기
	java.show(); // 현재 커피 머신의 상태 출력
}