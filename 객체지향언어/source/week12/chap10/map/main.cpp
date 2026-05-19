#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, string> dic;

	dic.insert(make_pair("love", "사랑"));
	dic["apple"] = "사과";
	dic["cherry"] = "체리";

	dic.erase("apple");
	
	cout << "저장된 단어 개수 " << dic.size() << "개" << endl;
	while (true) {
		string eng;
		cout << "영단어 >> ";
		cin >> eng;
		if (eng == "exit")
			break;
		if (dic.find(eng) == dic.end()) { //없는 경우
			cout << "없음" << endl;
		}
		else {
			string kor = dic[eng];
			cout << kor << endl;
		}
	}

}