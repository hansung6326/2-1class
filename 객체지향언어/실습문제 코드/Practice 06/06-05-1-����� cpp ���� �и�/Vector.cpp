#include <iostream>
#include <cstdlib>
using namespace std;

#include "Vector.h"

Vector::Vector() {
	size = 5;
	mem = new int[size];
	if (mem == NULL)
		exit(0);

	for (int i = 0; i < size; i++) mem[i] = 0;
}

Vector::Vector(int size, int val) {
	this->size = size;
	mem = new int[size];
	if (mem == NULL)
		exit(0);

	for (int i = 0; i < size; i++) mem[i] = val;
}

Vector::~Vector() {
	if (mem != NULL) delete[] mem;
}

void Vector::show() {
	show(size); // 중복 함수 show(int n) 호출
}

void Vector::show(int n) {
	if (n > size) n = size;
	for (int i = 0; i < n; i++) cout << mem[i] << ' ';
	cout << endl;
}