#include <iostream>
#include <string>
using namespace std;

int main() {
	string line, dest = "";
	char ch;
	cout << "텍스트 입력(한글 안 됨) >> ";
	getline(cin, line, '\n');
	for (int i = 0; i < line.size(); i++) {
		ch = line[i];
		if (isalpha(ch) || ch == ' ') {
			dest.append(1, ch);
		}
	}
	cout << dest << endl;
	return 0;
}