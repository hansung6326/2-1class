#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

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

#endif