#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
public:
	Histogram(string text);
	Histogram& operator <<(string text);
	Histogram& operator <<(char text);
	void operator !();
};

Histogram::Histogram(string text) {
	this->text = text;
}

Histogram& Histogram::operator<<(string text) {
	this->text = this->text + text;
	return *this;
}

Histogram& Histogram::operator<<(char text) {
	this->text = this->text + text;
	return *this;
}

void Histogram::operator!() {
	cout << text << endl;
	
	int count[26] = { 0 };
	int total = 0;
	
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i])) {
			char c = tolower(text[i]);
			count[c - 'a']++;
			total++;
		}
	}

	cout << "총 알파벳 수 " << total << endl;
	for (int i = 0; i < 26; i++) {
		if (count[i] > 0) {
			cout << (char)('a' + i) << ": ";
			for (int j = 0; j < count[i]; j++) {
				cout << '*';
			}
			cout << endl;
		}
	}
}

int main() {
	Histogram song("Wise men say, \nonly fools rush int But I can't help, \n");
	song << "falling" << " in love with you." << "- by ";
	song << 'k' << 'i' << 't';
	!song;
}