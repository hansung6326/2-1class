#include <iostream>
using namespace std;

class Light {
	int light;
public:
	Light(int light = 1) {
		this->light = light;
	}
	Light& operator +=(Light& op) {
		light += op.light;
		op.light = 0;
		return *this;
	}
	Light& operator +=(int op) {
		light += op;
		return *this;
	}
	Light operator ~() {
		cout << "빛 크기 " << light << endl;
		return *this;
	}
	Light operator --(int n) {
		Light tmp = *this;
		light--;
		return tmp;
	}
	bool operator ==(int op) {
		if (light == op)
			return true;
		return false;
	}
};

int main() {
	Light a(10), b(20), c, d(0);
	(a += b) += 10;
	~a; ~b; ~c;
	d = c--;
	~d;
	if (c == 0)
		cout << "빛 c는 꺼져 있습니다." << endl;
	if (d == 0)
		cout << "빛 d는 꺼져 있습니다." << endl;
}