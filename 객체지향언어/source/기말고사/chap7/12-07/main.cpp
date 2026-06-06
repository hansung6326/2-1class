#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	ofstream fout("c:\\temp\\system.txt", ios::out | ios::binary);
	if (!fout) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	fin.seekg(0, ios::end);
	int size = fin.tellg();

	int c;
	for (int i = 0; i < size; i++) {
		fin.seekg(size - i - 1, ios::beg);
		c = fin.get();
		fout.put(c);
	}

	fin.close();
	fout.close();


}