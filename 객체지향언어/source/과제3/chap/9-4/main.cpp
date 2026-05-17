#include <iostream>
#include <string>
using namespace std;

class AbstractPoint {
protected:
	string name;
	int point = 0; 
	int ratio;
public:
	AbstractPoint(string name, int ratio = 1);
	virtual void earn(int paymentAmount) = 0;
	virtual void show() = 0;
	int getPoint();
};

AbstractPoint::AbstractPoint(string name, int ratio) {
	this->name = name;
	this->ratio = ratio;
}

int AbstractPoint::getPoint() {
	return point;
}

class Platinum : public AbstractPoint {
private:
	int base; 
	int bonusRatio;
public:

	Platinum(string name, int ratio, int base, int bonusRatio);
	virtual void earn(int paymentAmount);
	virtual void show();
	void combine(Platinum& otherAccount);
};

Platinum::Platinum(string name, int ratio, int base, int bonusRatio) : AbstractPoint(name, ratio) {
	this->base = base;
	this->bonusRatio = bonusRatio;
}

void Platinum::earn(int paymentAmount) {
	if (paymentAmount <= base) {
		point += paymentAmount * ratio / 100;
	}
	else {
		point += paymentAmount * bonusRatio / 100;
	}
}

void Platinum::show() {
	cout << name << "님*** 적립 포인트는 " << point << "점입니다." << endl;
}

void Platinum::combine(Platinum& otherAccount) {
	point += otherAccount.point;
	otherAccount.point = 0;
}

int main() {
	Platinum hwang("황기태", 5, 100000, 7), park("박채원", 5, 100000, 7);

	hwang.earn(50000);
	hwang.earn(200000);
	park.earn(500000);
	hwang.show();
	park.show();

	hwang.combine(park);
	hwang.show();
	park.show();

	return 0;
}