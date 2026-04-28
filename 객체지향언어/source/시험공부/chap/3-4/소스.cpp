#include <iostream>
using namespace std;

class Cube {
	int width, length, height;
public:
	Cube(int width, int length, int height) {
		this->width = width;
		this->length = length;
		this->height = height;
	}
	void increase(int w, int l, int h) {
		width += w;
		length += l;
		height += h;
	}
	int getVolume() {
		return width * length * height;
	}
	bool isZero() {
		if ((width * length * height) == 0)
			return true;
		return false;
	}
};

int main() {
	Cube cube(1, 2, 3);
	cout << "큐브의 부피는 " << cube.getVolume() << endl;
	cube.increase(1, 2, 3);
	cout << cube.getVolume() << endl;
	if (cube.isZero())
		cout << "큐브의 부피는 0" << endl;
	else
		cout << "큐브의 부피는 0이 아님" << endl;

}