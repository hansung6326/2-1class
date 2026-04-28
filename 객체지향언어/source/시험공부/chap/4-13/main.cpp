#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Histogram {
    string text;     // 전체 문자열 저장
    int count[26];   // a~z 개수

public:
    Histogram(string s = "") {
        text = s;
        for (int i = 0; i < 26; i++)
            count[i] = 0;
    }

    // 문자열 추가
    void add(string s) {
        text += s;
    }

    // 문자 하나 추가
    void add(char c) {
        text += c;
    }

    // 히스토그램 출력
    void draw() {
        // 카운트 초기화
        for (int i = 0; i < 26; i++)
            count[i] = 0;

        int total = 0;

        // 문자 분석
        for (int i = 0; i < text.length(); i++) {
            char c = tolower(text[i]); // 소문자 변환

            if (isalpha(c)) { // 알파벳만
                count[c - 'a']++;
                total++;
            }
        }

        // 원문 출력
        cout << text << endl;
        cout << endl;

        // 총 알파벳 수
        cout << "총 알파벳 수 " << total << endl << endl;

        // 히스토그램 출력
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            cout << ch << " (" << count[i] << ") : ";

            for (int j = 0; j < count[i]; j++)
                cout << "*";

            cout << endl;
        }
    }
};

int main() {
    Histogram histo("You fill up my senses, like a night in a forest\n");
    histo.add("Like the mountains in springtime, like a walk in the rain\n");
    histo.add('-');
    histo.add("Annie's Song by John Denver");

    histo.draw();

    return 0;
}