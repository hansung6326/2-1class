#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("c:\\temp\\src.png", ios::binary);
    if (!fin) {
        cout << "소스 파일 열기 실패" << endl;
        exit(0);
    }

    ofstream fout("c:\\temp\\copy.png", ios::binary);
    if (!fout) {
        cout << "목적 파일 열기 실패" << endl;
        exit(0);
    }
    
    char buf[1024];
    while (!fin.eof()) {
        fin.read(buf, 1024);
        int n = fin.gcount();
        fout.write(buf, 1024);
        if (n < 1024)
            break;
    }
    fin.close();
    fout.close();
}