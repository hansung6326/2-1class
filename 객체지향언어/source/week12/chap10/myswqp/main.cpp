#include <iostream>
#include <string>
using namespace std;

/*	템플릿 장점
	함수 코드의 재사용
	
	템플릿 단점
	포팅에 취약
	컴파일 오류 메시지 빈약, 디버깅에 많은 어려움 */

template <class T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//void myswap(int& a, int& b) {
//	int tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void myswap(double& c, double& d) {
//	double tmp;
//	tmp = c;
//	c = d;
//	d = tmp;
//}
//void myswap(char& e, char& f) {
//	char tmp;
//	tmp = e;
//	e = f;
//	f = tmp;
//}
//
//void myswap(string& x, string& y) {
//	string tmp;
//	tmp = x;
//	x = y;
//	y = tmp;
//}

int main() {
	int a = 4, b = 5;
	myswap(a, b);
	cout << a << '\t' << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << c << '\t' << d << endl;

	char e = 'A', f = 'B';
	myswap(e, f);
	cout << e << '\t' << f << endl;

	string x = "hello", y = "yoo";
	myswap(x, y);
	cout << x << '\t' << y << endl;

}