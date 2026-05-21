#ifndef PLATINUM_H // PLATINUM_H가 정의되어 있지 않다면
#define PLATINUM_H // PLATINUM_H를 정의함(중복 포함 방지)
#include "AbstractPoint.h" // 부모 클래스 AbstractPoint 헤더 파일 포함
//AbstractPoint 클래스를 상속받는 Platinum 클래스 선언
class Platinum : public AbstractPoint {
private: // 아래 멤버들을 private으로 접근 지정
	int base; // 기본 적립 기준 금액을 저장하는 멤버 변수
	int bonusRatio; // 추가 적립 비율을 저장하는 멤버 변수
public: // 아래 멤버들을 public으로 접근 지정
	// 회원 정보와 적립 기준을 초기화하는 생성자 선언
	Platinum(string name, int ratio, int base, int bonusRatio);
	virtual void earn(int paymentAmount); // 결제 금액에 따른 포인트 적립 함수 선언
	virtual void show(); // 회원 포인트 정보를 출력하는 함수 선언
	void combine(Platinum& otherAccount); // 다른 계정의 포인트를 합치는 함수 선언
};
#endif // 조건부 컴파일 종료