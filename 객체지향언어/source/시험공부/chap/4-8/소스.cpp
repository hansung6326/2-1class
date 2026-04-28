#include <iostream>
#include <string>
using namespace std;

int main() {
	string url;
	while (1) {
		cout << "웹 주소 입력>>";
		getline(cin, url);
		if (url == "그만")
			break;
		int protoEnd = url.find("://");
		string protocol = url.substr(0, protoEnd);

		string rest = url.substr(protoEnd + 3);

		int colonPos = rest.find(':');
		int slashPos = rest.find('/');

		string host;
		int port = 80;
		string remaining;

		if (colonPos != string::npos && (slashPos == string::npos || colonPos < slashPos)) {
			host = rest.substr(0, colonPos);
			string afterColon = rest.substr(colonPos + 1);

			int slashPos2 = afterColon.find('/');
			if (slashPos2 != string::npos) {
				port = stoi(afterColon.substr(0, slashPos2));
				remaining = afterColon.substr(slashPos2);
			}
			else {
				port = stoi(afterColon);
				remaining = "/";
			}
		}
		else {
			// 포트 번호가 없는 경우
			if (slashPos != string::npos) {
				host = rest.substr(0, slashPos);
				remaining = rest.substr(slashPos);
			}
			else {
				host = rest;
				remaining = "/";
			}
		}
		cout << "프로토콜: " << protocol << "\n";
		cout << "호스트: " << host << "\n";
		cout << "포트: " << port << "\n";
		cout << "나머지 부분: " << remaining << "\n";
	}

	return 0;
}