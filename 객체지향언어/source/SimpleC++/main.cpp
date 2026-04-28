#include <iostream>
using namespace std;
int f(); //선언부

int main() {
	int width, height;
	cout << "너비는 ";		//cout은 출력 스트림 객체
	cin >> width;			//cin은 입력 스트림 객체
	cout << "높이는 ";
	cin >> height;
	int area = width * height;
	cout << "면적은 " << area << endl;

	return 0;
}


/* 과제를 할 때 줄 마다 주석문을 다는데
	변수 선언 이렇게 말고 나이를 저장하는을 붙여서
	어떤 변수를 선언하는지 설명하는 주석문을 달아야함
*/

