#include <iostream>
using namespace std;

class Storage {
	double data[10] = { 0 };
	int next=0;
public:
	Storage();
	void put(double n);
	double getAvg();
	void dump();
};

Storage::Storage() {
	next = 0;
}

void Storage::put(double n) {
	if (next == 10) {
		cout << "꽉참. 더 이상 저장 불가" << endl;
		return;
	}

	data[next] = n;
	next++;
}

double Storage::getAvg() {
	double sum = 0;
	for (int i = 0; i < next; i++) {
		sum += data[i];
	}
	return sum / next;
}


void Storage::dump() {
	for (int i = 0; i < next; i++)
		cout << data[i] << ' ';
	cout << endl;
}

int main() {
	Storage a;
	a.put(36.7); 
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
}