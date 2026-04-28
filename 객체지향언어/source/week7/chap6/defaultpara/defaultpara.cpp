#include <iostream>
#include <string>
using namespace std;

void star(int n=5) { //n에 아무값도 넘어오지 않으면 5가 넘어온것으로 하라
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << endl;
}
void msg(int id=1, string text="blank") {
	cout << id << ' ' << text << endl;
}

int main() {
	star(10);
	star();

	msg(10, "Hello");
	msg(5);
	msg();
}