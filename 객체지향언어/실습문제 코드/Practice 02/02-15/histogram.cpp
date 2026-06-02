#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char text[10000]; // 10000 개의 문자열 배열
	int histo[26] = { 0 }; // 영문자 26 글자의 누적수 저장. 초깃값은 모두 0

	cout << "히스토그램을 그립니다. 텍스트의 끝은 ; 이고 " << endl;
	cout << "10000개 문자까지 가능합니다. 영문 텍스트를 입력하세요. " << endl;
	cin.getline(text, 10000, ';');

	int len = strlen(text);
	for (int i = 0; i<len; i++) {
		if (isalpha(text[i])) {
			char c = tolower(text[i]);
			histo[c - 'a']++;
		}
	}

	int n = 0;
	for (int i = 0; i<26; i++) n += histo[i]; // 전체 알파벳 수 더하기
	cout << "총 알파벳 수 " << n << endl;
	cout << endl;

	for (int i = 0; i<26; i++) {
		cout << char('a' + i) << " (" << histo[i] << ")" << '\t' << ": ";
		for (int j = 0; j<histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}