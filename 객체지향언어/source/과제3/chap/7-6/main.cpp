#include <iostream>
using namespace std;

class Light {
	int size;
public:
	Light(int size = 1);
	Light& operator +=(Light& a);
	Light& operator +=(int n);
	void operator ~();
	Light operator --(int x);
	bool operator ==(int n);
};

Light::Light(int size) {
	this->size = size;
}

Light& Light::operator +=(Light& a) {
	this->size += a.size;
	a.size = 0;
	return *this;
}
Light& Light::operator +=(int n) {
	this->size += n;
	return *this;
}
void Light::operator ~() {
	cout << "빛 크기 " << size << endl;
}
Light Light::operator --(int x) {
	Light tmp = *this;
	size--;
	return tmp;
}
bool Light::operator ==(int n) {
	if (size == n)
		return true;
	else
		return false;
}

int main() {
	Light a(10), b(20), c, d(0);
	(a += b) += 10;
	~a; ~b; ~c;
	d = c--;
	~d;
	if (c == 0) cout << "빛 c는 꺼져 있습니다." << endl;
	if (d == 0) cout << "빛 d는 꺼져 있습니다." << endl;
}