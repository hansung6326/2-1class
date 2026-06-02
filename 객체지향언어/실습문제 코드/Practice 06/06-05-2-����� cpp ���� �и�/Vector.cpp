#include <iostream>
#include <cstdlib>
using namespace std;

#include "Vector.h"

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

void Vector::show(int n) {
	// n이 0이면 모두 출력하기 위해 n = size
	// n이 size 보다 작으면 n=size
	if (n == 0 || n > size)
		n = size;
	for (int i = 0; i < n; i++) cout << mem[i] << ' ';
	cout << endl;
}