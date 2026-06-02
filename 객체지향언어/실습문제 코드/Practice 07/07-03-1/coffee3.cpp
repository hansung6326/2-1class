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
	bool operator ! ();
	bool operator > (Coffee b);
};

bool Coffee::operator !() {
	if (sugar == 0) return true;
	else return false;
}

bool Coffee::operator > (Coffee b) {
	if (water + espresso + sugar + cream >
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