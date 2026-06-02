#include <iostream>
using namespace std;

#include "Container.h"

int main() {
	Container c(10); // 정수 10개를 저장할 객체 c 생성
	c.read(); // 키보드에서 정수 배열로 읽어 들이기
	c.write(); // 정수 배열 출력
	c.rotate(); // 정수 배열을 오른쪽으로 회전
	c.write(); // 정수 배열 출력
	cout << "평균은 " << c.avg() << endl;
}