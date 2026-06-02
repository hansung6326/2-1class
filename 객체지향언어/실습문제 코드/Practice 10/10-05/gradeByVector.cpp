#include <iostream>
#include <vector>
using namespace std;

int main() {
	const string grades[] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };
	const double scores[] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0 };
	vector<string> v;

	// 6과목의 성적 읽어 vector에 저장
	cout << "6과목의 학점 입력>>";
	for (int i = 0; i < 6; i++) {
		string grade;
		cin >> grade;
		v.push_back(grade);
	}

	// 성적의 평균 계산
	double sum = 0;
	for (int i = 0; i < v.size(); i++) { // 벡터에 들어 있는 모든 학점 계산
		int j = 0;
		for (j = 0; j < 9; j++) { // 학점 이름 검색
			// grades 배열에서 찾기
			if (v.at(i) == grades[j]) {
				sum += scores[j];
				break;
			}
		}
		if (j == 9) {
			cout << v.at(i) << "의 학점이 잘못 입력되었습니다." << endl;
			exit(0); // 프로그램 종료
		}
	}
	cout << "학점 평균은 " << sum / v.size();
}