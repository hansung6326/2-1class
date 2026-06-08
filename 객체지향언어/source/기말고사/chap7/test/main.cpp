#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if (!fin) {
		exit(1);
	}
	ofstream fout("c:\\temp\\system.txt", ios::out | ios::binary);
	if (!fout) {
		exit(1);
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
