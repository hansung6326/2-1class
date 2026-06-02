#include <iostream>
#include <string>
using namespace std;

bool equals(string x, string y) {
	return x == y;
}

bool equals(string x, string y, int n) {
	string subX = x.substr(0, n);
	string subY = y.substr(0, n);
	return subX == subY;
}

bool equals(string x, string y, int n, string z) {
	string subX = x.substr(0, n);
	string subY = y.substr(0, n);
	string subZ = z.substr(0, n);
	return subX == subY && subX == subZ;
}

int main() {
	string x = "Prof. Hwang";
	string y = "Prof. Kim";
	string z = "Prof. Lee";
	if (equals(x, y)) cout << "같음" << endl;
	if (equals(x, y, 3)) cout << "앞 3글자 같음" << endl;
	if (equals(x, y, 5, z)) cout << "앞 5글자 같음" << endl;
}