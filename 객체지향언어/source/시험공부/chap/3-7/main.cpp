#include <iostream>
using namespace std;

class Storage {
	double data[10];
	int next = 0;
public:
	void put(double b);
	void dump();
	double getAvg();
};

void Storage::put(double b) {
	data[next] = b;
	next++;
}
void Storage::dump() {
	for (int i = 0; i < next; i++) {
		cout << data[i] << "\t";
	}
	cout << endl;
}
double Storage::getAvg() {
	double sum=0;
	for (int i = 0; i < next; i++) {
		sum += data[i];
	}
	return sum / next;
}

int main() {
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
}