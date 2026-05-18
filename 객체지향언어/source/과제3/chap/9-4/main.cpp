#include "Platinum.h" //Platinum 클래스 선언 헤더 포함
#include <iostream> //입출력 기능을 위한 표준 헤더 파일

using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함

int main() {

	//매개변수 생성자를 호출하여 Platinum 객체 생성
	Platinum hwang("황기태", 5, 100000, 7);
	Platinum park("박채원", 5, 100000, 7);

	hwang.earn(50000); // 황기태 회원에게 50000원 결제 포인트 적립
	hwang.earn(200000); // 황기태 회원에게 200000원 결제 포인트 적립
	
	park.earn(500000); // 박채원 회원에게 500000원 결제 포인트 적립
	
	hwang.show(); // 황기태 회원 정보 출력
	park.show(); // 박채원 회원 정보 출력

	hwang.combine(park); // 박채원 회원 포인트를 황기태 회원에게 합산

	hwang.show(); // 합산 후 황기태 회원 정보 출력
	park.show(); // 합산 후 박채원 회원 정보 출력

	return 0; // 프로그램을 종료하고 운영체제에 0을 반환
}