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
	friend bool operator ! (Coffee c);
	friend bool operator > (Coffee a, Coffee b);
};

bool operator !(Coffee c) {
	if (c.sugar == 0) return true;
	else return false;
}

bool operator > (Coffee a, Coffee b) {
	if (a.water + a.espresso + a.sugar + a.cream >
		b.water + b.espresso + b.sugar + b.cream)
		return true;
	else
		return false;
}

int main() {
	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
	if (!a) // 설탕이 없으면
		cout << "No sugar!" << endl;
	if (a > b) cout << "커피 a가 양이 더 많아요.";
	else cout << "커피 b가 양이 더 많아요.";
}