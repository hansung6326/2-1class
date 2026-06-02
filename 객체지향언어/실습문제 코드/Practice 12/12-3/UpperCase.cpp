#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("C:\\windows\\system.ini");

	if(!fin) {
		cout << "열기 오류";
		return 0;
	}

	int ch;
	while((ch=fin.get()) != EOF) {
		cout << (char)toupper(ch);
	}

	fin.close();
}