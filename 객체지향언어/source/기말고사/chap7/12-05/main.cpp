#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\ShowNoComment.cpp");
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	int c;
	bool found = false;
	while ((c = fin.get()) != EOF) {
		if (c == '/') {
			if (found == false) {
				found = true;
			}
			else {
				fin.ignore(100, '\n');
				cout.put('\n');
				found = false;
			}
		}
		else {
			if (found == true) {
				found = false;
				cout.put('/');
			}
			cout.put(c);
		}
	}
	fin.close();
}