#include <iostream>
using namespace std;

class Coffee {
	int coffee, sugar, milk, water;
public:
	Coffee() {
		coffee = 10;
		sugar = 0;
		milk = 0;
		water = 0;
	}
	Coffee(int coffee, int sugar, int milk, int water) {
		this->coffee = coffee;
		this->sugar = sugar;
		this->milk = milk;
		this->water = water;
	}
	void show() {
		cout << "coffee ";
		for (int i = 0; i < coffee; i++) {
			cout << '*';
		}
		cout << endl;
		cout << "sugar ";
		for (int i = 0; i < sugar; i++) {
			cout << '*';
		}
		cout << endl;
		cout << "milk ";
		for (int i = 0; i < milk; i++) {
			cout << '*';
		}
		cout << endl;
		cout << "water ";
		for (int i = 0; i < water; i++) {
			cout << '*';
		}
		cout << endl;
	}
};

int main() {
	Coffee espresso;
	Coffee americano(5, 0, 0, 10);
	Coffee cappucchino(5, 1, 5, 2);
	Coffee mySweet(3, 7, 5, 5);

	espresso.show();
	cout << endl;
	mySweet.show();
}