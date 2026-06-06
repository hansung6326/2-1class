#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}
	ofstream fout("c:\\temp\\system.txt");
	if (!fout) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout << (char)toupper(c);
	}

	fin.close();
	fout.close();

}