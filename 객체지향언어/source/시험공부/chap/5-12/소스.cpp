#include <iostream>
using namespace std;

class MyPipe {
	int size = 0;
	int putIndex = 0;
	int *p;
public:
	MyPipe() {
		size = 0;
		putIndex = 0;
	}
	MyPipe(int size) {
		this->size = size;
		putIndex = 0;
		p = new int[size];
	}
	MyPipe(const MyPipe& src) {
		size = src.size;
		putIndex = src.putIndex;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = src.p[i];
		}
	}
	~MyPipe() {
		delete[] p;
	}
	bool put(int n) {
		if (putIndex >= size)
			return false;
		p[putIndex++] = n;
		return true;
	}
	bool get(int& n) {
		if (putIndex <= 0)
			return false;
		n = p[0];
		for (int i = 0; i < putIndex - 1; i++) {
			p[i] = p[i + 1];
		}
		putIndex--;
		return true;
	}
	int getSize() {
		return putIndex;
	}
};

int main() {
	MyPipe a(5);
	a.put(10); a.put(20);

	MyPipe b = a;
	b.put(30);
	cout << "파이프 a에 저장된 개수: " << a.getSize() << endl;
	cout << "파이프 b에 저장된 개수: " << b.getSize() << endl;

	int n;
	a.get(n);
	cout << "파이프 a에서 빼온 값 " << n << endl;
	b.get(n);
	cout << "파이프 b에서 빼온 값 " << n << endl;

}