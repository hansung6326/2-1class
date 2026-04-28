#include <iostream>
using namespace std;

class Collector {
	int* p;
	int size = 0;
public:
	Collector(int size, int values[]);
	Collector(const Collector& src);
	~Collector() {
		delete[] p;
	}
	void show();
	int getSize() {
		return size;
	}
	int get(int index) {
		return p[index];
	}
};

Collector::Collector(int size, int values[]) {
	this->size = size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		p[i] = values[i];
	}
}
Collector::Collector(const Collector& src) {
	this->size = src.size;
	this->p = new int[size];
	for (int i = 0; i < this->size; i++) {
		this->p[i] = src.p[i];
	}
}
void Collector::show() {
	cout << "데이터 수 " << size << ": ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
double calcAvg(Collector c) {
	double sum = 0;
	for (int i = 0; i < c.getSize(); i++) {
		sum += c.get(i);
	}
	return sum / c.getSize();
}

int main() {
	int temp[] = { 69, 70, 71, 72, 74 };
	Collector weight(4, temp);
	double avg = calcAvg(weight);
	weight.show();
	cout << "평균은 " << avg << endl;
}