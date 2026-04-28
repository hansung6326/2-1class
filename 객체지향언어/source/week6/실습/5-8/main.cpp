#include "Fitness.h"// Fitness 클래스 선언이 담긴 헤더 포함
#include <iostream>// 입출력 기능을 위한 표준 헤더 파일
using namespace std;// std 이름공간에 선언된 모든 이름에 std를 생략함
int main() {
	Fitness altong; // Fitness 객체 altong 생성
	//arrive 함수를 연속적으로 호출하여 남성 3명, 여성 6명, 남성 9명을 추가
	altong.arrive("남", 3).arrive("여", 6).arrive("남", 9);
	int m = 0, w = 0; // 회원 수를 담을 변수 m, w 선언 및 초기화
	altong.count("남", m);// count 함수를 호출하여 남자 회원 수를 m에 저장
	altong.count("여", w);// count 함수를 호출하여 여자 회원 수를 w에 저장
	//현재 저장된 남자와 여자 회원 수를 출력
	cout << "남자 회원 " << m << "명, 여자 회원 " << w << "명" << endl;
	altong.at("남") = 100; //at 함수가 반환한 참조를 통해 남자 회원 수를 100으로 수정
	m = altong.at("남"); // 수정된 남자 회원 수를 가져와 m에 저장
	w = altong.at("여"); // 현재 여자 회원 수를 가져와 w에 저장
	//수정 후의 남자와 여자 회원 수를 출력
	cout << "남자 회원 " << m << "명, 여자 회원 " << w << "명" << endl;
	return 0; //프로그램을 종료하고 운영체제에 0을 반환
}