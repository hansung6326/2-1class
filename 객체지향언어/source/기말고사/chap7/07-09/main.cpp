#include <iostream>
using namespace std;

class Chart {
	int* chart = NULL;
	int size;
	int index = 0;
public:
	Chart(int size) {
		this->size = size;
		chart = new int[size]();
	}
	bool operator !() {
		if (index == 0)
			return true;
		return false;
	}
	Chart& operator <<(int op) {
		if (index > size - 1)
			return *this;
		chart[index] = op;
		index++;
		return *this;
	}
	int operator ~() {
		int sum = 0;
		for (int i = 0; i < index; i++) {
			sum += chart[i];
		}
		return sum / index;
	}
	void show() {
		cout << "차트 데이터: ";
		for (int i = 0; i < index; i++) {
			cout << chart[i] << " ";
		}
		cout << endl;
	}
	~Chart() {
		delete[] chart;
	}

};

int main() {
	Chart chart(100);
	if (!chart)
		cout << "차트가 비었습니다." << endl;

	int n;
	cout << "정수 4개 입력>>";
	for (int i = 0; i < 4; i++) {
		cin >> n;
		chart << n;
	}
	int avg = ~chart;
	cout << "평균은 " << avg << endl;
	chart.show();
}