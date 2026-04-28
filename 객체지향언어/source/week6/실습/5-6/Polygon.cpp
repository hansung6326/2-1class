#include "Polygon.h" //Polygon 클래스 선언 헤더 포함
#include <iostream> // 입출력 기능을 위한 표준 헤더 파일
using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함
//매개변수가 있는 생성자 정의
Polygon::Polygon(int size) {
	this->size = size; // 매개변수 size 값을 멤버 변수 size에 저장
	xList = new int[size];// size 크기만큼 x좌표를 저장할 배열을 동적 할당
	yList = new int[size];// size 크기만큼 y좌표를 저장할 배열을 동적 할당
}
//소멸자 정의
Polygon::~Polygon() {
	delete[] xList; //동적 할당된 x좌표 배열 메모리 해제
	delete[] yList; //동적 할당된 y좌표 배열 메모리 해제
}
//좌표를 입력받는 함수 정의
void Polygon::read() {
	cout << "아래에 x, y 값으로 " << size << "개의 점을 입력하세요." << endl;
	for (int i = 0; i < size; i++) { // size만큼 반복하여 입력받음
		cin >> xList[i] >> yList[i]; // 입력된 값을 배열의 i번째 요소에 저장
	}
}
// 특정 번호의 점 좌표를 반환하는 함수 정의
bool Polygon::get(int n, int& x, int& y) {
	//입력된 번호가 유효한 범위(1~size)를 벗어나면 false 반환
	if (n < 1 || n > size)
		return false;
	x = xList[n - 1]; //배열의 n-1 인덱스에 저장된 x값을 참조 변수 x에 저장
	y = yList[n - 1]; //배열의 n-1 인덱스에 저장된 y값을 참조 변수 y에 저장
	return true; //성공적으로 값을 전달했으므로 true 반환
}