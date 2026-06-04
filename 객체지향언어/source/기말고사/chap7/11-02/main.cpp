#include <iostream>
using namespace std;



int main() {
	cout << "입력하세요>>";
	char ch;
	int c = 0;
	while (true) {
		cin.get(ch);
		if (cin.eof())
			break;
		if (ch >= '0' && ch <= '9')
			c++;
		if (ch == '\n')
			break;
	}
	cout << "숫자는 모두 " << c << "개 입력됨" << endl;
}