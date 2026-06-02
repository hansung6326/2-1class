#include <iostream>
#include <string>
using namespace std;

class Picture {
	int width;
	int height;
	string place;
public:
	Picture();
	Picture(int width, int height, string place);
	int getWidth() { return width; }
	int getHeight() { return height; }
	string getPlace() { return place; }
};

Picture::Picture() {
	width = 5;
	height = 7;
	place = "모름";
}

// 위임 생성자를 사용하는 사례
//Picture::Picture() : Picture(5, 7, "모름") {
	// 위의 생성자 대신 이 생성자 사용할 수 있음
//}

Picture::Picture(int w, int h, string p) {
	width = w;
	height = h;
	place = p;
}

int main() {
	Picture pic; // 5x7 크기로 촬영 장소 "모름"
	Picture mt(10, 14, "한라산");
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
}