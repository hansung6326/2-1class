#include <iostream>
using namespace std;

class Bubble {
	int radius;
public:
	Bubble(int radius) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int n) {
		radius = n;
	}
};

bool combineBubble(Bubble& a, Bubble& b) {
	if (a.getRadius() == b.getRadius())
		return false;
	else {
		int sum = a.getRadius() + b.getRadius();
		if (a.getRadius() > b.getRadius()) {
			a.setRadius(sum);
			b.setRadius(0);
			return true;
		}
		else {
			a.setRadius(0);
			b.setRadius(sum);
			return true;
		}
			
	}
	return true;
}

int main() {
	Bubble a(5), b(10);
	if (combineBubble(a, b) == false)
		cout << "두 버블의 크기가 같음" << endl;
	else {
		cout << "큰 쪽으로 병합됨" << endl;
	}
	cout << "버블 a의 반지름 " << a.getRadius() << endl;
	cout << "버블 b의 반지름 " << b.getRadius() << endl;
}