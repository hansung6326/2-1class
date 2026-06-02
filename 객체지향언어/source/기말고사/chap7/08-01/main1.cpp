#include <iostream>
using namespace std;

class EspressoCoffee {
	string name;
	int espresso, water;
public:
	EspressoCoffee(string name, int espresso, int water) {
		this->name = name;
		this->espresso = espresso;
		this->water = water;
	}
	void recipe() {
		cout << name << "는 에스프레스 " << espresso << "스푼, 물 " << water << "스푼" << endl;
	}
	void get(string& name, int& espresso, int& water) {
		name = this->name;
		espresso = this->espresso;
		water = this->water;
	}
};

class Cappuccino : public EspressoCoffee {
	int milk;
	bool isIce;
public:
	Cappuccino(string name, int espresso, int water, int milk, bool isIce) : EspressoCoffee(name, espresso, water) {
		this->milk = milk;
		this->isIce = isIce;
	}
	void recipe() {
		string name;
		int espresso, water;
		get(name, espresso, water);
		if (isIce)
			cout << name << "는 에스프레스 " << espresso << "스푼, 얼음물 " << water << "스푼, 우유 " << milk << "스푼, 얼음 충분히" << endl;
		else
			cout << name << "는 에스프레스 " << espresso << "스푼, 따뜻한 물 " << water << "스푼, 우유 " << milk << "스푼" << endl;
	}
};

int main() {
	EspressoCoffee espresso("에스프레소", 2, 0);
	EspressoCoffee americano("아메리카노", 2, 5);
	americano.recipe();

	Cappuccino myHotCap("따뜻한 카푸치노", 2, 2, 4, false);
	myHotCap.recipe();
	Cappuccino myIceCap("아이스 카푸치노", 2, 1, 5, true);
	myIceCap.recipe();
}