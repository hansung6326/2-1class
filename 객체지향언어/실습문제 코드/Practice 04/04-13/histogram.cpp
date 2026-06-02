#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int histo[26]; // 26개의 알파벳에 대해 각 글자당 개수 저장
public:
	Histogram();
	Histogram(string text); // 생성자에 히스토그램으로 분석할 문자열 전달
	void addc(char c); // 히스토그램에 문자 삽입
	void add(string text); // 히스토그램에 string 문자열 삽입
	void draw(); // 히스토그램의 화면 출력
	~Histogram() {}
};

Histogram::Histogram() {
	this->text = "";
}

Histogram::Histogram(string text) {
	this->text = text;
}

void Histogram::add(string text) {
	this->text.append(text); // 기존의 텍스트에 text 문자열 덧붙임
	//this->text += text; //와 동일
}

void Histogram::addc(char c) {
	char buf[] = {c, '\0'};
	this->text.append(buf); // 기존의 텍스트에 text 문자열 덧붙임

	// text += c; //와 동일
}

void Histogram::draw() {
	for(int i=0; i<26; i++)
		histo[i] = 0; // histo 배열을 0으로 초기화

	cout << text << endl << endl;

	for(int i=0; i<text.length(); i++) {
		if(isalpha(text[i])) { // 알파벳에 대해서만 처리
			char c = tolower(text[i]);
			histo[c - 'a']++;
		}
	}
		
	int n =0;
	for(int i=0; i<26; i++) n += histo[i]; // 전체 알파벳 수 더하기
	cout << "총 알파벳 수 " << n << endl;
	cout << endl;

	for(int i=0; i<26; i++) {
		cout << char('a'+i) << " (" << histo[i] << ")" << '\t' << ": ";
		for(int j=0; j<histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}

int main() {
	Histogram histo("You fill up my senses, like a night in a forest\n");
	histo.add("Like the mountains in springtime, like a walk in the rain\n");
	histo.addc('-');
	histo.add("Annie's Song by John Denver");
	histo.draw(); // 원문 텍스트와 히스토그램 모두 출력
}