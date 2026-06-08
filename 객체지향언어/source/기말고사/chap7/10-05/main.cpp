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

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string grades[] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };
	double scores[] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0 };
	vector<string> v;

	string n;
	for (int i = 0; i < 6; i++) {
		cin >> n;
		v.push_back(n);
	}

	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int j;
		for (j = 0; j < 9; j++) {
			if (v[i] == grades[j]) {
				sum += scores[j];
				break;
			}

		}
		if (j == 9) {
			exit(1);
		}
	}

	cout << sum / v.size();

}

*/