#include <iostream>
#include <string>
using namespace std;

int main() {
	string buf1;
	string buf2;

	cout << "문자열을 입력하세요>>";
	cin >> buf1;
	cout << "문자열을 입력하세요>>";
	cin >> buf2;
	if (buf1 == buf2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}