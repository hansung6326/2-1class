#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");

	if (!fin) {
		cout << "파일 읽기 실패" << endl;
		return 0;
	}

	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
	fin.close();
}