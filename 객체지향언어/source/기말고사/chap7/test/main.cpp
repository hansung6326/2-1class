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

