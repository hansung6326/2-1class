#include <iostream>
#include <string>
using namespace std;

int main() {
	string line, dest;
	cout << "텍스트 입력>>";
	getline(cin, line, '\n');

	for (int i = 0; i < (int)line.size(); i++) {
		char ch = line[i];
		if (ch == ' ') {
			if (dest.size() > 0 && dest[dest.size() - 1] == ' ') {
				continue;
			}
		}
		dest.append(1, ch);
	}

	cout << dest << endl;
	
}