#include "AbstractPoint.h" // AbstractPoint 클래스 선언 헤더 포함
// 생성자 정의
AbstractPoint::AbstractPoint(string name, int ratio) {
	this->name = name; // 매개변수 name 값을 멤버 변수에 저장
	this->ratio = ratio; // 매개변수 ratio 값을 멤버 변수에 저장
}
//현재 포인트를 반환하는 함수 정의
int AbstractPoint::getPoint() {
	return point; //현재 포인트 값을 반환
}