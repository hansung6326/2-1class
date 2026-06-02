#include <iostream>
#include <fstream>
using namespace std;

void write() {
    char name[100], dept[100];
    int id;

    cout << "이름>>";
    cin >> name;
    cout << "학번>>";
    cin >> id;
    cout << "학과>>";
    cin >> dept;

    ofstream fout("c:\\temp\\student.txt", ios::app); //fstream 객체 생성, student.txt 파일 열기
    // fout.open("c:\\temp\\student.txt", ios::out);  // ios::in 사용하면 오류남
    if (!fout) { // fout.!() fout == NULL 이면 true 반환
        cout << "파일 열기 실패" << endl;
        exit(0);
    }

    fout << name << endl;
    fout << id << endl;
    fout << dept << endl;

    fout.close(); // 파일을 열었으니까 파일 닫기
}

void read() {
    char name[100], dept[100];
    int id;

    ifstream fin("c:\\temp\\student.txt");
    // fin.open("c:\\temp\\student.txt", ios::in);
    if (!fin) {
        cout << "파일 열기 실패" << endl;
        exit(0);
    }

    fin >> name >> id >> dept;
    cout << name << ' ' << id << ' ' << dept << endl;

    fin.close();
}

int main() {
    write();

}