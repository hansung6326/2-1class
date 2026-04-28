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

void addBubble(Bubble& c, Bubble a, Bubble b) {
	int sum = c.getRadius() + a.getRadius() + b.getRadius();
	c.setRadius(sum);
}

int main() {
	Bubble a(5), b(10), c(130);
	addBubble(c, a, b);
	cout << "버블 c의 반지름 " << c.getRadius() << endl;
}