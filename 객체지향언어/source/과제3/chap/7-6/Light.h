#ifndef LIGHT_H // LIGHT_H가 정의되어 있지 않다면
#define LIGHT_H // LIGHT_H를 정의함(중복 포함 방지)

#include <iostream> // 입출력 기능을 위한 표준 헤더 파일

using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함

class Light { //Light 클래스 선언
	int size; // 빛의 크기를 저장하는 멤버 변수
public: // 아래 멤버들을 public으로 접근 지정
	Light(int size = 1); // 빛 크기를 초기화하는 생성자 선언
	Light& operator +=(Light& a); // 다른 Light 객체의 크기를 합치는 연산자 함수 선언
	Light& operator +=(int n); // 정수 값을 빛 크기에 더하는 연산자 함수 선언
	void operator ~(); // 빛 크기를 출력하는 연산자 함수 선언
	Light operator --(int x); // 후위 감소 연산자 함수 선언
	bool operator ==(int n); // 빛 크기와 정수 값을 비교하는 연산자 함수 선언
};

#endif //조건부 컴파일 종료