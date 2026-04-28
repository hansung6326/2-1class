#include <iostream>
using namespace std;

int main() {
	int* p;
	p = new int;
	//if (p == NULL) {//힙에 메모리가 부족하여 동적할당 실패
	if(!p){
		cout << "메모리 부족";
		return 0;
	}
	*p = 5;
	int n = *p;
	cout << *p << endl;
	cout << n << endl;

	delete p;
		
}