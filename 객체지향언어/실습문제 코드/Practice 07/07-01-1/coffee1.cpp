#include <iostream>
using namespace std;

class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water=1, int coffee=3, int sugar=0, int cream=0) {
		this->water = water; this->espresso = coffee;
		this->sugar = sugar; this->cream = cream; 
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso;
		cout << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	Coffee operator + (Coffee c);
	Coffee operator + (int espresso);
};

Coffee Coffee::operator + (Coffee c) {
	Coffee temp = *this;
	temp.water += c.water;
	temp.espresso += c.espresso;
	temp.sugar += c.sugar;
	temp.cream += c.cream;

	return temp;
}

Coffee Coffee::operator + (int espresso) {
	Coffee temp = *this;
	temp.espresso = this->espresso + espresso;
	return temp;
}

int main() {
	Coffee black(2,5,0,0), dabang(2,2,2,2), c, d;
	c = black + dabang;
	d = c + 1; // espresso 샷 1개 추가
	c.show();
	d.show();
}