#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	
	if (!fin) {
		cout << "파일 읽기 실패" << endl;
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)toupper(c);
	}
	fin.close();
}