#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    fin.open("c:\\windows\\system.ini", ios::in);

    if (!fin) {
        cout << "열기 실패" << endl;
        exit(0);
    }

    /*int c, count = 0;
    while ((c = fin.get()) != EOF) {
        cout.put(c);
        count++;
    }*/

    string buf;
    while (getline(fin, buf)) {
        cout << buf << endl;
    }
    
    fin.close();

}