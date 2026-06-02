#include <iostream>
using namespace std;

#include "Collector.h"

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