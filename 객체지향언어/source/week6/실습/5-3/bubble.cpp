#include <iostream>
using namespace std;

class Bubble {
	int radius;
public:
	Bubble(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	Bubble& addBubble(Bubble y) { // Bubble& y, Bubble& z 해도 오류 없음
		radius += y.getRadius();
		return *this;
	}

};
//void addBubble(Bubble& x, Bubble y, Bubble z) { // Bubble& y, Bubble& z 해도 오류 없음
//	x.setRadius(x.getRadius() + y.getRadius() + z.getRadius());
//
//}


int main() {
	Bubble a(5), b(10), c(130);
	/*c.addBubble(c, a, b);*/
	c.addBubble(a).addBubble(b).addBubble(Bubble(200));
	cout << "버블 c의 반지름 " << c.getRadius() << endl;
}