#include <iostream>
#include <cstdlib>
using namespace std;

class Vector {
	int* mem; // 생성자에서 배열 할당. 할당받은 배열의 주소 저장
	int size; // 생성자에서 할당받은 배열의 크기
public:
	Vector(int size, int val); // mem에 size 크기의 동적 배열을 할당하고 val로 초기화
	Vector(); // mem에 5 크기의 동적 배열을 할당하고 0으로 초기화
	~Vector();
	void show(); // 동적 배열 mem을 모두 출력
	void show(int n); // 동적 배열 mem에서 앞 부분 n 개만 출력
};

Vector::Vector() {
	size = 5;
	mem = new int[size];
	if (mem == NULL)
		exit(0);

	for (int i = 0; i < size; i++) mem[i] = 0;
}

Vector::Vector(int size, int val) {
	this->size = size;
	mem = new int[size];
	if (mem == NULL)
		exit(0);

	for (int i = 0; i < size; i++) mem[i] = val;
}

Vector::~Vector() {
	if (mem != NULL) delete[] mem;
}

void Vector::show() {
	show(size); // 중복 함수 show(int n) 호출
}

void Vector::show(int n) {
	if (n > size) n = size;
	for (int i = 0; i < n; i++) cout << mem[i] << ' ';
	cout << endl;
}

int main() {
	Vector x; // 5 크기의 동적 배열을 할당하고 0으로 초기화
	Vector y(10, 8); // 10 크기의 동적 배열을 할당하고 8로 초기화
	x.show(); // 벡터 x를 모두 출력
	y.show(); // 벡터 y를 모두 출력
	y.show(3); // 벡터 y의 원소 중 앞의 3개 출력
}