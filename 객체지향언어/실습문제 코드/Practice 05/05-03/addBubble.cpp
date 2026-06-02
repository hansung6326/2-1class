#include <iostream>
using namespace std;

class Bubble {
	int radius;
public:
	Bubble(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int n) { radius = n; }
};

void addBubble(Bubble& c, Bubble a, Bubble b) {
	c.setRadius(c.getRadius() + a.getRadius() + b.getRadius());
}

int main() {
	Bubble a(5), b(10), c(130);
	addBubble(c, a, b); // 버블 c=c+a+b의 크기로 만들기
	cout << "버블 c의 반지름 " << c.getRadius() << endl;
}