#include <iostream>
using namespace std;

class Vector {
	int* mem;
	int size;
public:
	Vector(int size = 5, int a = 0) {
		this->size = size;
		mem = new int[size];
		for (int i = 0; i < size; i++) {
			mem[i] = a;
		}
	}
	~Vector() {
		delete[] mem;
	}
	void show(int b = 0) {
		if (b == 0 || b > size)
			b = size;
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