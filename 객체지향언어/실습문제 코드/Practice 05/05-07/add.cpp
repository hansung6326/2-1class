#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick, int punch); // 생성자
	Power& add(Power p); // 현재 파워에 매개변수 p의 파워를 더한다.
	void show(); // kick과 punch를 출력한다.
};

Power::Power(int kick, int punch) {
	this->kick = kick; this->punch = punch;
}

void Power::show() {
	cout << "kick=" << kick << ", punch=" << punch << endl;
}

Power& Power::add(Power p) {
	kick += p.kick;
	punch += p.punch;
	return *this;
}

int main() {
	Power a(1, 2), b(10, 20), c(100, 200);
	c.add(a).add(b).add(Power(1000, 2000));
	c.show();
}