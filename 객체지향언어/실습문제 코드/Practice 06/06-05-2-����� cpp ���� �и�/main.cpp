#include <iostream>
#include <cstdlib>
using namespace std;

#include "Vector.h"

int main() {
	Vector x; // 5 크기의 동적 배열을 할당하고 0으로 초기화
	Vector y(10, 8); // 10 크기의 동적 배열을 할당하고 8로 초기화
	x.show(); // 벡터 x를 모두 출력
	y.show(); // 벡터 y를 모두 출력
	y.show(3); // 벡터 y의 원소 중 앞의 3개 출력
}