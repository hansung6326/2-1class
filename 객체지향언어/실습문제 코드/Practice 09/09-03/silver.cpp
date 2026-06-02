#include <iostream>
#include <string>
using namespace std; 

class AbstractPoint { // 추상 클래스
protected:
	string name; // 회원 명
	int point = 0; // 초기 포인트 0
	int ratio; // 포인트 적립률. 단위: %
	virtual void earn(int pay) = 0; // 순수 가상 함수. pay 금액에 대한 포인트 적립
	virtual void show() = 0; // 순수 가상 함수. 이름과 포인트 출력
public:
	AbstractPoint(string name, int ratio = 1) {
		this->name = name; this->ratio = ratio;
	}
};

class Silver : public AbstractPoint {
public:
	Silver(string name, int ratio = 3);
	virtual void earn(int pay); // pay 금액을 사용한 경우 포인트 적립
	virtual void show(); // 이름과 포인트 출력
};

Silver::Silver(string name, int ratio)
	:AbstractPoint(name, ratio)
{ }

void Silver::earn(int pay) {
	point += pay * ratio/100;
}

void Silver::show() {
	cout << name << "님* 적립 포인트는 " << point << "점입니다." << endl;
}

int main() {
	Silver hwang("황기태"), ok("옥지윤", 4);
	// 생성자 의미: 황기태 적립률 3%, 옥지윤 적립율 4%

	hwang.earn(10000); // 10000원을 지출한 경우, 포인트 300 적립
	hwang.earn(20000); // 20000원을 지출한 경우, 포인트 600 적립
	hwang.earn(5000); // 5000원을 지출한 경우, 포인트 150 적립
	ok.earn(5000); // 5000원을 지출한 경우, 포인트 200 적립
	hwang.show(); ok.show(); // 현재 누적 포인트 출력
}
