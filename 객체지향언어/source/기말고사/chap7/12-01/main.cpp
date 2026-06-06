#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("test.txt");
	if (!fout) {
		return 0;
	}
	fout << "0123456789" << endl;
	fout << "Integer" << endl;

	fout.close();

	ifstream fin("test.txt");
	if (!fin) {
		return 0;
	}
	int c;
	while ((c = fin.get()) != EOF) {
		cout.put(c);
	}

	
	fin.close();
}