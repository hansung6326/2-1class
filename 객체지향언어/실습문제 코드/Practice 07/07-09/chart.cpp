#include <iostream>
#include <cstring>
using namespace std;

class Chart {
	int* p = NULL;
	int size = 0;
	int nextIndex = 0; // 다음에 저장할 위치. 
public:
	Chart(int size);
	~Chart();
	void show();

	bool operator !();
	Chart& operator << (int n);
	int operator ~ ();
};

Chart::Chart(int size) {
	this->size = size;
	p = new int[size];
	if (p == NULL)
		exit(0);
}

Chart::~Chart() {
	if (p != NULL)
		delete[] p;
}

void Chart::show() {
	cout << "차트 데이터: ";
	for (int i = 0; i < nextIndex; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}


bool Chart::operator!() {
	if (nextIndex == 0) return true;
	else return false;
}

Chart& Chart::operator << (int n) {
	if (nextIndex >= size) // 더 이상 삽입 불가
		return *this;

	p[nextIndex] = n;
	nextIndex++;
	return *this;
}

int Chart::operator ~ () {
	int sum = 0;
	for (int i = 0; i < nextIndex; i++)
		sum += p[i];

	return sum / nextIndex;
}

int main() {
	Chart chart(100); // 100개의 정수 저장이 가능한 차트 객체
	if (!chart) cout << "차트가 비었습니다." << endl;

	int n; 
	cout << "정수 4개 입력>>";
	for (int i = 0; i < 4; i++) {
		cin >> n; // 정수 입력
		chart << n; // chart에 입력받은 정수 저장
	}
	int avg = ~chart; // chart 데이터의 평균 값 리턴
	cout << "평균은 " << avg << endl;
	chart.show(); // 현재 저장된 차트 데이터 출력
}