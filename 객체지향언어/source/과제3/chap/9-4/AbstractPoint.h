#ifndef ABSTRACTPOINT_H // ABSTRACTPOINT_H가 정의되어 있지 않다면
#define ABSTRACTPOINT_H // ABSTRACTPOINT_H를 정의함(중복 포함 방지)
#include <iostream> // 입출력 기능을 위한 표준 헤더 파일
#include <string> // 문자열 사용을 위한 표준 헤더 파일
using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함
class AbstractPoint { // AbstractPoint 추상 클래스 선언
protected: // 자식 클래스에서 접근 가능하도록 protected 지정
	string name; // 회원 이름을 저장하는 멤버 변수
	int point = 0; // 적립 포인트를 저장하는 멤버 변수
	int ratio; // 포인트 적립 비율을 저장하는 멤버 변수
public: // 아래 멤버들을 public으로 접근 지정
	// 회원 이름과 적립 비율을 초기화하는 생성자 선언
	AbstractPoint(string name, int ratio = 1);
	// 결제 금액에 따른 포인트 적립 함수 선언(순수 가상 함수)
	virtual void earn(int paymentAmount) = 0;
	virtual void show() = 0; // 포인트 정보를 출력하는 함수 선언(순수 가상 함수)
	int getPoint(); // 현재 포인트를 반환하는 함수 선언
};
#endif // 조건부 컴파일 종료