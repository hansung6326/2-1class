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
	fin.seekg(0, ios::beg);

	int c, count = 0, nextPer = 10, per;
	cout << "복사 시작..." << endl;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
		count++;
		per = count * 100 / size;
		if (per >= nextPer) {
			cout << '.' << size / 10 << "B " << per << "%" << endl;
			nextPer += 10;
		}
	}
	cout << count << "B 복사 완료" << endl;

	fin.close();
	fout.close();
}