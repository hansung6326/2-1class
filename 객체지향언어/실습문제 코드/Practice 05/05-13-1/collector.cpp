#include <iostream>
using namespace std;

class Collector {
	int* p; // 데이터를 저장하는 동적 배열
	int size = 0; // 데이터 개수
public:
	Collector(int size, int values[]); // 생성자
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