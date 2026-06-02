#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char buf1[100];
	char buf2[100];

	cout << "문자열을 입력하세요>>";
	cin >> buf1;
	cout << "문자열을 입력하세요>>";
	cin >> buf2;
	if (strcmp(buf1, buf2) == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}