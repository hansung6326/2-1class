#include <iostream>
#include <string>
using namespace std;

bool equals(string x, string y, int size = 0, string z = "") {
	if (size == 0) {
		return x == y;
	}
	else if (z == "") {
		if (x.size() < size || y.size() < size)
			return false;
		return x.substr(0, size) == y.substr(0, size);
	}
	else {
		if (x.length() < size || y.length() < size || z.length() < size) // x.size() 와 x.length()는 동일한 함수
			return false;
		return x.substr(0, size) == y.substr(0, size) &&
			y.substr(0, size) == z.substr(0, size);
	}
}

int main() {
	string x = "Prof. Hwang";
	string y = "Prof. Kim";
	string z = "Prof. Lee";
	if (equals(x, y)) cout << "같음" << endl;
	if (equals(x, y, 3)) cout << "앞 3글자 같음" << endl;
	if (equals(x, y, 5, z)) cout << "앞 5글자 같음" << endl;
}