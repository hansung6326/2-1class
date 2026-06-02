#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void read(ifstream& fin, vector<string>& v) {
    string line;
    int count = 0;
    while (getline(fin, line)) {
        v.push_back(line);
        count++;
    }
    cout << "파일 읽기 완료 .... 라인 " << count << endl;
}

void echo(vector<string>& v) {
    int num = 1;
    for (int i = 0; i < v.size(); i++) {
        string line = v[i];
        cout << num << ":\t" << line << endl;
        num++;
    }
}

void search(vector<string>& v, string word) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        string line = v[i];
        int index = line.find(word);
        if (index != -1) {
            cout << line << endl;
            count++;
        }
    }
    cout << "단어 " << count << "개를 찾았습니다." << endl;
}

int main() {
    vector<string> wordVec;
    ifstream fin;
    fin.open("c:\\temp\\words.txt");

    if (!fin) {
        cout << "파일 열기 실패" << endl;
        exit(0);
    }

    read(fin, wordVec);

    fin.close();
    //echo(wordVec);

    while (true) {
        cout << "단어 입력>>";
        string word;
        cin >> word;
        if (word == "exit")
            break;
        search(wordVec, word);
    }
}