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

class Platinum : public AbstractPoint {
	int base, bonus;
public:
	Platinum(string name, int ratio, int base, int bonus) : AbstractPoint(name, ratio) {
		this->base = base;
		this->bonus = bonus;
	}
	void earn(int pay);
	void show();
	void combine(Platinum& op);
};
void Platinum::earn(int pay) {
	if (pay > base)
		point += pay * bonus / 100;
	else
		point += pay * ratio / 100;
}
void Platinum::show() {
	cout << name << "님*** 적립 포인트는 " << getPoint() << "점입니다." << endl;
}
void Platinum::combine(Platinum& op) {
	point += op.point;
	op.point = 0;
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
}