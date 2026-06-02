#include <iostream>
#include <string>
using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int *p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray(); // p는 NULL로 size는 0으로 초기화
	SortedArray(const SortedArray& src); // 복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
	~SortedArray(); // 소멸자
	SortedArray operator + (const SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열을 복사
	void show(); // 배열의 원소 출력
};

SortedArray::SortedArray() {
	p = NULL; // NULL 대신 nullptr로 하는 것이 바람직함
	size = 0;
}

SortedArray::~SortedArray() {
	if (p != NULL) // NULL 대신 nullptr로 하는 것이 바람직함
		delete[] p;
}

SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}

	sort(); // 오름차순 정렬
}

SortedArray::SortedArray(const SortedArray& src) {
	this->size = src.size;
	if (src.size == 0) {
		this->p = NULL; // NULL 대신 nullptr로 하는 것이 바람직함
	}
	else {
		this->p = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->p[i] = src.p[i];
		}
	}
}

void SortedArray::sort() { // 오름차순 버블 정렬
	if (p == NULL || size == 0) // NULL 대신 nullptr로 하는 것이 바람직함
		return;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i; j < size - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void SortedArray::show() { // 모든 원소 출력
	cout << "배열 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;

}

SortedArray& SortedArray::operator = (const SortedArray& op2) {
	if (p != NULL) { // NULL 대신 nullptr로 하는 것이 바람직함
		delete[] p;
	}

	size = op2.size;
	if (size == 0) { // op2가 비어있는 경우
		p = NULL; // NULL 대신 nullptr로 하는 것이 바람직함
		return *this;
	}

	// op2가 비어있지 않는 경우
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = op2.p[i];
	return *this;
}

SortedArray SortedArray::operator + (const SortedArray& op2) {
	SortedArray temp;

	// 이 객체의 배열을 먼저 temp에 넣는다.
	if (this->size == 0) { // 이 객체가 비어 있는 경우
						   // op2를 temp에 복사하여 리턴
		temp.size = op2.size;
		if (temp.size == 0) { // op2도 비어있는 경우
			temp.p = NULL; // NULL 대신 nullptr로 하는 것이 바람직함
		}
		else { // op2가 비어있지 않는 경우
			temp.p = new int[temp.size];
			for (int i = 0; i < temp.size; i++)
				temp.p[i] = op2.p[i];
		}
	}
	else if (op2.size == 0) { // 이 객체가 비어있지 않고 op2가 비어있는경우
							  // 이 객체를 temp에 복사하여 리턴
		temp.size = this->size;
		temp.p = new int[temp.size];
		for (int i = 0; i < temp.size; i++)
			temp.p[i] = this->p[i];
	}
	else { // 둘다 비어있지 않는 경우
		temp.size = this->size + op2.size;
		temp.p = new int[temp.size];
		int i;
		for (i = 0; i < this->size; i++) // 이 객체의 배열 복사
			temp.p[i] = this->p[i];
		for (int j = 0; j < op2.size; j++) // 이 객체의 배열 복사
			temp.p[i + j] = op2.p[j];
	}
	temp.sort();
	return temp;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	
	c = a + b; // +, = 연산자 작성 필요
			   // + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();
}