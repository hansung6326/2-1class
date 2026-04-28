#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	/*char buf1[100];
	char buf2[100];*/

	string buf1;
	string buf2;

	cout << "문자열을 입력하세요>> ";
	cin >> buf1;
	cout << "문자열을 입력하세요>> ";
	cin >> buf2;

	/*if (!strcmp(buf1, buf2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;*/

	if (buf1 == buf2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
}