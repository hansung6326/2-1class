#include <iostream>
using namespace std;

class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 1, int coffee = 3, int sugar = 0, int cream = 0) {
		this->water = water; this->espresso = coffee;
		this->sugar = sugar; this->cream = cream;
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso;
		cout << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	friend Coffee operator + (Coffee a, Coffee b);
	friend Coffee operator + (Coffee a, int espresso);
};

Coffee operator + (Coffee a, Coffee b) {
	Coffee temp = a; // a를 temp에 복사
	temp.water += b.water;
	temp.espresso += b.espresso;
	temp.sugar += b.sugar;
	temp.cream += b.cream;

	return temp;
}

Coffee operator + (Coffee a, int espresso) {
	Coffee temp = a;
	temp.espresso += espresso;
	return temp;
}

int main() {
	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
	c = black + dabang;
	d = c + 1; // espresso 샷 1개 추가
	c.show();
	d.show();
}