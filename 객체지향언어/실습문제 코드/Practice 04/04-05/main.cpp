#include <iostream>
#include <cstdlib>
using namespace std;

class Container {
	int* p; // 정수 배열에 대한 포인터
	int size; // 정수 배열의 크기
public:
	Container(int size); //  생성자
	~Container(); // 소멸자
	void read(); // 배열의 크기만큼 정수를 키보드로부터 읽어들이기
	void write(); // 배열에 저장된 전체 정수 출력
	void rotate(); // 배열의 원소들 회전
	double avg(); // 평균 출력
};

Container::Container(int size) { //  생성자
	if (size <= 0)
		exit(0); // 저장 공간이 없으므로 프로그램 종료
			 // exit을 사용하려면 <cstdlib> 헤더파일 include 필요
	
	this->size = size;
	p = new int[size]; // size개 만큼의 정수 배열 동적 할당
	if (p == NULL) 
		exit(0); // 동적 할당 실패하면 프로그램 종료
}

Container::~Container() {
	if(p != NULL)
		delete[] p;
}

void Container::read() {
	cout << "정수 " << size << "개 입력>>";
	for (int i = 0; i < size; i++)
		cin >> p[i];
}

void Container::write() {
	for (int i=0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}

double Container::avg() {
	if (size == 0) 
		return 0;

	int sum = 0;
	for(int i = 0; i < size; i++)
		sum += p[i];

	return (double)sum / size;
}

void Container::rotate() {
	if (size == 0)
		return;
	int last = p[size - 1]; // 맨 끝의 원소 기억
	for (int i = 0; i < size - 1; i++) // 하나씩 뒤로 이동
		p[size - 1 - i] = p[size - 2 - i];

	p[0] = last; // 맨 끝의 원소를 맨 앞의 원소 값으로 저장
}

int main() {
	Container c(10); // 정수 10개를 저장할 객체 c 생성
	c.read(); // 키보드에서 정수 배열로 읽어 들이기
	c.write(); // 정수 배열 출력
	c.rotate(); // 정수 배열을 오른쪽으로 회전
	c.write(); // 정수 배열 출력
	cout << "평균은 " << c.avg() << endl;
}