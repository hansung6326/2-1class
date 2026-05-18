#include "Light.h" // Light 클래스 선언 헤더 포함

//생성자 정의
Light::Light(int size) {
	this->size = size; // 매개변수 size 값을 멤버 변수에 저장
}

Light& Light::operator +=(Light& a) { // Light 객체끼리 더하는 연산자 함수 정의
	this->size += a.size; // 현재 객체 크기에 다른 객체 크기를 더함
	a.size = 0; // 합쳐진 객체의 크기를 0으로 초기화
	return *this; // 현재 객체를 반환
}

Light& Light::operator +=(int n) { // 정수를 더하는 연산자 함수 정의
	this->size += n; // 현재 객체 크기에 정수 값을 더함
	return *this; // 현재 객체를 반환
}

void Light::operator ~() { // 빛 크기를 출력하는 연산자 함수 정의
	cout << "빛 크기 " << size << endl;
}

Light Light::operator --(int x) { // 후위 감소 연산자 함수 정의
	Light tmp = *this; // 현재 객체를 임시 객체에 저장
	size--; // 현재 객체의 크기를 1 감소 
	return tmp; // 변경 전 객체를 반환
}

bool Light::operator ==(int n) { // 빛 크기와 정수를 비교하는 연산자 함수 정의
	if (size == n) // 빛 크기와 입력값이 같은 경우
		return true; // true 반환
	else // 빛 크기와 입력값이 다른 경우
		return false; // false 반환
}