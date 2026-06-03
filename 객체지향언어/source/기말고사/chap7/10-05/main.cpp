#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> v;

	cout << "6과목의 학점 입력>>";
	for (int i = 0; i < 6; i++) {
		string grade;
		cin >> grade;
		v.push_back(grade);
	}

	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "A+")
			sum += 4.5;
		else if (v[i] == "A")
			sum += 4;
		else if (v[i] == "B+")
			sum += 3.5;
		else if (v[i] == "B")
			sum += 3;
		else if (v[i] == "C+")
			sum += 2.5;
		else if (v[i] == "C")
			sum += 2;
		else if (v[i] == "D+")
			sum += 1.5;
		else if (v[i] == "D")
			sum += 1;
		else if (v[i] == "F")
			sum += 0;
	}
	cout << "학점 평균은 " << sum / v.size() << endl;
}