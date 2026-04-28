#include <iostream>
using namespace std;

class MyPipe {
	int putIndex = 0;
	int p[5];
public:
	MyPipe() {
		putIndex = 0;
	}
	bool put(int n) {
		if (putIndex >= 5)
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
	MyPipe pipe;
	for (int i = 0; i < 6; i++) {
		if (pipe.put(i))
			cout << i << ' ';
		else
			cout << endl << i + 1 << "번째 put 실패! 파이프 꽉 참" << endl;
	}
	cout << "현재 파이프 크기 : " << pipe.getSize() << endl;
	int n;
	for (int i = 0; i < 6; i++) {
		if (pipe.get(n))
			cout << n << ' ';
		else
			cout << endl << i + 1 << "번째 get 실패! 파이프 비어 있음" << endl;
	}
	cout << "현재 파이프 크기 : " << pipe.getSize() << endl;
}