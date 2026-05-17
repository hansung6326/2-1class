#include <iostream>
using namespace std;

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}

	friend bool equals(Rect a, Rect b);
};
bool equals(Rect a, Rect b) {
	if (a.width == b.width && a.height == b.height)
		return true;
	else
		return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
}