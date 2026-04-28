#include <iostream>
using namespace std;

class Vector {
	int* mem;
	int size;
public:
	Vector() {
		size = 5;
		mem = new int[size];
		for (int i = 0; i < size; i++) {
			mem[i] = 0;
		}
	}
	Vector(int size, int a) {
		this->size = size;
		mem = new int[size];
		for (int i = 0; i < size; i++) {
			mem[i] = a;
		}
	}
	~Vector() {
		delete[] mem;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << mem[i] << " ";
		}
		cout << endl;
	}
	void show(int b) {
		if (b > size) {
			b = size;
		}
		for (int i = 0; i < b; i++) {
			cout << mem[i] << " ";
		}
		cout << endl;
	}

};

int main() {
	Vector x;
	Vector y(10, 8);
	x.show();
	y.show();
	y.show(3);
}