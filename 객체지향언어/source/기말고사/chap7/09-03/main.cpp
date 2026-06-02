#include <iostream>
using namespace std;

class AbstractPoint {
protected:
	string name;
	int point = 0;
	int ratio;
public:
	AbstractPoint(string name, int ratio = 1);
	virtual void earn(int pay) = 0;
	virtual void show() = 0;
	int getPoint() {
		return point;
	}
};

AbstractPoint::AbstractPoint(string name, int ratio) {
	this->name = name;
	this->ratio = ratio;
}

class Silver : public AbstractPoint {
public:
	Silver(string name, int ratio = 3) : AbstractPoint(name, ratio) {}
	void earn(int pay);
	void show();
};
void Silver::earn(int pay) {
	point += pay * ratio / 100;
}
void Silver::show() {
	cout << name << "님* 적립 포인트는 " << getPoint() << "점입니다." << endl;
}

int main() {
	Silver hwang("황기태"), ok("옥지윤", 4);
	hwang.earn(10000);
	hwang.earn(20000);
	hwang.earn(5000);
	ok.earn(5000);
	hwang.show();
	ok.show();
}