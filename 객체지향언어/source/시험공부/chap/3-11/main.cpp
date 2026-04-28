#include <iostream>
using namespace std;

class Oval {
	int width, height;
public:
	Oval() {
		width = 1;
		height = 1;
	}
	Oval(int w, int h) {
		width = w;
		height = h;
	}
	~Oval();
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	void set(int w, int h) {
		width = w;
		height = h;
	}
	void show() {
		cout << "Oval: width=" << width << ", height=" << height << endl;
	}
	double area();
};

Oval::~Oval() {
	cout << "Oval 소멸: " << width << "x" << height << endl;
}
double Oval::area() {
	return (width / 2.0) * (height / 2.0) * 3.14;
}	

int main() {
	Oval kitae, jane(10, 15);
	kitae.set(3, 4);
	kitae.show();
	cout << jane.getWidth() << "x" << jane.getHeight() << ", 면적 " << jane.area() << endl;
}