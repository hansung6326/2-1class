#include <iostream>
#include <string>
using namespace std;

class StringTokenizer {
	string* tokens;
	int size = 0;
	int nextTokenIndex = 0;
public:
	StringTokenizer(string text, string delimiter);
	~StringTokenizer();
	int length() {
		return size;
	}
	string next();
	bool hasNext();
};
StringTokenizer::StringTokenizer(string text, string delimiter) {
	int count = 0;
	int pos = 0;
	while ((pos = text.find(delimiter, pos)) != string::npos) {
		count++;
		pos += delimiter.length();
	}
	size = count + 1;
	tokens = new string[size];

	int startIndex = 0;
	for (int i = 0; i < size; i++) {
		int endIndex = text.find(delimiter, startIndex);
		if (endIndex == string::npos)
			tokens[i] = text.substr(startIndex);
		else {
			tokens[i] = text.substr(startIndex, endIndex - startIndex);
			startIndex = (int)endIndex + (int)delimiter.length();
		}
	}
}
StringTokenizer::~StringTokenizer() {
	delete[] tokens;
}
string StringTokenizer::next() {
	if (nextTokenIndex < size) {
		return tokens[nextTokenIndex++];
	}
	return "";
}

// 남은 토큰이 있는지 확인
bool StringTokenizer::hasNext() {
	return nextTokenIndex < size;
}

int main() {
	StringTokenizer code("i++; for(); sum+=i;", " ");

	for (int i = 0; i < code.length(); i++)
		cout << code.next() << endl;

	StringTokenizer text("모짜르트,베토벤,슈베르트,황기태", ",");

	while (text.hasNext())
		cout << text.next() << endl;

	return 0;
}