#include <iostream>
using namespace std;

class Collector {
	int* p; // 데이터를 저장하는 동적 배열
	int size = 0; // 데이터 개수
public:
	Collector(int size, int values[]); // 생성자
	Collector(const Collector& src); // 복사 생성자
	~Collector(); // 소멸자
	void show(); // 데이터 개수와 value[]를 화면에 출력
	int getSize() { return size; }
	int get(int index) { return p[index]; }
};

Collector::Collector(int size, int values[]) { 
	this->size = size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = values[i];
}

Collector::Collector(const Collector& src) { // 복사 생성자
	size = src.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = src.p[i];
}

Collector::~Collector() { // 소멸자
	if(p != NULL)
		delete[] p; // 동적 할당받은 메모리 반환
}


void Collector::show() {
	cout << "데이터 수 " << size << ": ";
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}

double calcAvg(Collector s) {
	int sum = 0;
	for (int i = 0; i < s.getSize(); i++)
		sum += s.get(i);
	return ((double)sum) / s.getSize();
}

int main() {
	int temp[] = { 69, 70, 71, 72, 74 };
	Collector weight(4, temp);
	double avg = calcAvg(weight);
	weight.show();
	cout << "평균은 " << avg << endl;
}