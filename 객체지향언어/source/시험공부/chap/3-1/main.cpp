#include <iostream>
#include <string>
using namespace std;

class Picture {
	int x, y;
	string place;
public:
	Picture();
	Picture(int x, int y, string c);
	int getWidth() {
		return x;
	}
	int getHeight() {
		return y;
	}
	string getPlace() {
		return place;
	}
};
Picture::Picture() {
	x = 5;
	y = 7;
	place = "모름";
}
Picture::Picture(int x, int y, string c) {
	this->x = x;
	this->y = y;
	place = c;
}

int main() {
	Picture pic;
	Picture mt(10, 14, "한라산");
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;

}