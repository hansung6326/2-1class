#include <iostream>
using namespace std;

class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0) {
		this->water = water;
		this->espresso = coffee;
		this->sugar = sugar;
		this->cream = cream;
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso;
		cout << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	friend Coffee& operator <<(Coffee& op1, Coffee op2);
	friend Coffee& operator <<(Coffee& op1, int op2);
};
Coffee& operator <<(Coffee& op1, Coffee op2) {
	op1.water += op2.water;
	op1.espresso += op2.espresso;
	op1.sugar += op2.sugar;
	op1.cream += op2.cream;
	return op1;
}
Coffee& operator <<(Coffee& op1, int op2) {
	op1.water += op2;
	return op1;
}

int main() {
	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
	a << b << 3;
	a.show();

}