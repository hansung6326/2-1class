#include "Light.h" // Light 클래스 선언 헤더 포함
#include <iostream> // 입출력 기능을 위한 표준 헤더 파일
using namespace std; // std 이름공간에 선언된 모든 이름에 std를 생략함
int main() {
Light a(10), b(20), c, d(0); // 매개변수 생성자를 호출하여 Light 객체 생성
(a += b) += 10; // a와 b를 합친 후 10을 추가
~a; // a 객체 정보 출력
~b; // b 객체 정보 출력
~c; // c 객체 정보 출력
d = c--; // 후위 감소 연산 결과를 d에 저장
~d; // d 객체 정보 출력
if (c == 0) // c 객체의 크기가 0인지 비교
cout << "빛 c는 꺼져 있습니다." << endl;
if (d == 0) // d 객체의 크기가 0인지 비교
cout << "빛 d는 꺼져 있습니다." << endl;
return 0; // 프로그램을 종료하고 운영체제에 0을 반환
}