#include <iostream>
#include <vector>
using namespace std;

//void print(vector<int>& v) { //call by value 로 하면 vector개수가 무수히 많아질 때 복사본이 계속해서 생기기 때문에 call by reference로
//	vector<int>::iterator it;
//	for (it = v.begin(); it != v.end(); it++) {
//		cout << *it << ' ';
//	}
//	cout << endl;
//
//
//	int size = v.size();
//	for (int i = 0; i < size; i++) {
//		cout << v.at(i) << ' ';
//	}
//	cout << endl;
//
//}

//int biggest(vector<int>& v) {
//	vector<int>::iterator it;
//	it = v.begin();
//	int big = *it;
//	it++;
//	for (; it != v.end(); it++) {
//		if (big < *it)
//			big = *it;
//	}
//	return big;
//
//	int size = v.size();
//	int big = v[0];
//	for (int i = 1; i < size; i++) {
//		if (big < v[i])
//			big = v[i];
//	}
//	return big;
//}

template<class T>
void print(vector<T>& v) {
	typename vector<T>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

}

template <class T>
T biggest(vector<T>& v) {
	typename vector<T>::iterator it;
	it = v.begin();
	T big = *it;
	it++;
	for (; it != v.end(); it++) {
		if (big < *it)
			big = *it;
	}
	return big;
}

int main() {
	//vector<int> v;
	//cout << " >> ";
	//while (true) {
	//	int n;
	//	cin >> n;
	//	if (n == -1) break;
	//	v.push_back(n);
	//}

	//vector<int>::iterator it;
	//it = v.begin(); // it에 v의 첫번째 원소를 가리키는 포인터 할당
	//v.erase(it + 2);

	//print(v);
	//int big = biggest(v);
	//cout << "biggest is " << big << endl;

	vector<string> s;
	while (true) {
		string a;
		cin >> a;
		if (a == "-1") break;
		s.push_back(a);
	}
	print(s);

	string bigger = biggest(s);
	cout << "biggest is " << bigger << endl;
	
}