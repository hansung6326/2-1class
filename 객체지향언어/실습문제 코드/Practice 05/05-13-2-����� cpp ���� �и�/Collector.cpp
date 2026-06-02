#include <iostream>
using namespace std;

#include "Collector-error.h"

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