#include <iostream>
using namespace std;

#include "Storage.h"

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