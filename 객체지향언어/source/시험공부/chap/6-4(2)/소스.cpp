#include <iostream>
#include <string>
using namespace std;

string erase(string s, string x="", string y="") {
	if (x.empty()) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				s.erase(i, 1);
				i--;
			}
		}
		return s;
	}

	int pos = 0;

	if (y.empty()) {
		while ((pos = s.find(x, pos)) != string::npos) {
			s.erase(pos, x.length());
		}
	}
	else {
		while ((pos = s.find(x, pos)) != string::npos) {
			s.replace(pos, x.length(), y);
			pos += y.length();
		}
	}
	
	return s;
}

int main() {
	string a = erase("Hello    world,   Yaho");
	cout << "모든 빈 칸 지운 결과\t" << a << endl;

	string b = erase("Hello    world,   Yaho", "ll");
	cout << "모든 ll을 지운 결과\t" << b << endl;

	string c = erase("Hello    world,   Yaho", "o", "77");
	cout << "모든 o를 77로 바꾼 결과\t" << c << endl;
}