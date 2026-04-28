#include <iostream>
#include <string>
using namespace std;

class Picture {
	int width, height;
	string place;
public:
	Picture();
	Picture(int w, int h, string s);
	int getWidth();
	int getHeight();
	string getPlace();
};

Picture::Picture() {
	width = 5;
	height = 7;
	place = "모름";
}
Picture::Picture(int w, int h, string s) {
	width = w;
	height = h;
	place = s;
}
int Picture::getWidth() {
	return width;
}
int Picture::getHeight() {
	return height;
}
string Picture::getPlace() {
	return place;
}

int main() {
	Picture pic;
	Picture mt(10, 14, "한라산");
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
}