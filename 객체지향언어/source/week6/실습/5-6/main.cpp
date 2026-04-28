#include "Polygon.h" // Polygon 클래스 선언이 담긴 헤더 포함
#include <iostream> // 입출력 기능을 위한 표준 헤더 파일
using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함
int main() {
	// 매개변수 생성자를 호출하여 점이 6개인 poly 객체 생성
	Polygon poly(6);
	poly.read(); //poly 객체의 read 함수를 호출하여 점의 좌표를 입력받음
	int n = 6, x, y;// 점의 번호와 좌표를 저장할 변수 선언
	//get 함수를 호출하여 n번째 점의 좌표를 가져오고 성공 여부를 res에 저장
	bool res = poly.get(n, x, y);
	if (res) // 점을 성공적으로 찾았다면 실행
		cout << n << "번째 점은 " << "(" << x << ", " << y << ")" << endl;
	else // 범위를 벗어나 점을 찾지 못했다면 실행
		cout << n << "번째 점은 없습니다." << endl;
	return 0; //프로그램을 종료하고 운영체제에 0을 반환
}
