#include <iostream>
using namespace std;

class Oval {
	int width, height;
public:
	Oval() { width = height = 1; }
	Oval(int w, int h) { width = w; height = h; }
	~Oval(); // 소멸자
	int getWidth() { return width; }
	int getHeight() { return height; }
	void set(int w, int h);
	double area();
	void show();
};

Oval::~Oval() {
	cout << "Oval 소멸: " << getWidth() << "x" << getHeight() << endl;
}

void Oval::set(int w, int h) {
	width = w; height = h;
}

double Oval::area() {
	return 3.14 * ((double)width) / 2 * ((double)height) / 2;
}

void Oval::show() {
	cout << "Oval: " << "width=" << width << ", height=" << height << endl;
}

int main() {
	Oval kitae, jane(10, 15);
	kitae.set(3, 4); // kitae 타원 너비와 높이는 3x4로 변경
	kitae.show(); // kitae 타원의 모양 출력
	cout << jane.getWidth() << "x" << jane.getHeight() << ", 면적 " << jane.area() << endl;
}