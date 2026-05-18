#include "Platinum.h" // Platinum 클래스 선언 헤더 포함

// 생성자 정의
// 부모 클래스 생성자를 호출하여 name과 ratio 초기화
Platinum::Platinum(string name, int ratio, int base, int bonusRatio) : AbstractPoint(name, ratio) {
	this->base = base; // 매개변수 base 값을 멤버 변수에 저장
	this->bonusRatio = bonusRatio; // 매개변수 bonusRatio 값을 멤버 변수에 저장
}

// 포인트 적립 함수 정의
void Platinum::earn(int paymentAmount) {
	
	if (paymentAmount <= base) {// 결제 금액이 기준 금액 이하인 경우
		point += paymentAmount * ratio / 100; // 기본 적립 비율로 포인트를 계산하여 저장
	}
	else { //결제 금액이 기준 금액을 초과하는 경우
		point += paymentAmount * bonusRatio / 100; // 추가 적립 비율로 포인트를 계산하여 저장
	}
}

//회원 정보를 출력하는 함수 정의
void Platinum::show() {
	cout << name << "님*** 적립 포인트는 " << getPoint() << "점입니다." << endl;
}
// 다른 계정의 포인트를 합치는 함수 정의
void Platinum::combine(Platinum& otherAccount) {
	point += otherAccount.point; // 현재 계정에 다른 계정 포인트를 합산
	otherAccount.point = 0; // 다른 계정 포인트를 0으로 초기화
}