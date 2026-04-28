#include <iostream>
#include <string>
using namespace std;

bool equals(string x, string y) {
	if (x == y)
		return 1;
	return 0;
}
bool equals(string x, string y, int size) {
	if (x.substr(0, size) == y.substr(0, size))
		return 1;
	return 0;
}
bool equals(string x, string y, int size, string z) {
	if (x.substr(0, size) == y.substr(0, size) && y.substr(0, size) == z.substr(0, size))
		return 1;
	return 0;
}

int main() {
	string x = "Prof. Hwang";
	string y = "Prof. Kim";
	string z = "Prof. Lee";
	if (equals(x, y)) cout << "같음" << endl;
	if (equals(x, y, 3)) cout << "앞 3글자 같음" << endl;
	if (equals(x, y, 5, z)) cout << "앞 5글자 같음" << endl;
}