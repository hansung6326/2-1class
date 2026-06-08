#include <iostream>
using namespace std;

class Schedule {
protected:
	int count;
	int* jobs;
	int curLoc;
public:
	Schedule(int curloc, int n[], int count) {
		this->curLoc = curloc;
		this->count = count;
		jobs = new int[count]();
		for (int i = 0; i < count; i++) {
			jobs[i] = n[i];
		}
	}
	~Schedule() {
		delete[] jobs;
	}
	void run() {
		int sum = 0;

		cout << "현재 위치는 " << getCurLoc() << "동: 배달 시작 ..." << getCurLoc();
		for (int i = 0; i < count; i++) {
			sum += abs(getCurLoc() - jobs[i]);
			curLoc = jobs[i];
			cout << " -> " << getCurLoc();
		}
		cout << endl;
		cout << "전체 움직인 거리는 " << sum << ", ";
		cout << "현재 위치는 " << getCurLoc() << "동" << endl;
	}
	int getJobs() {
		return count;
	}
	int getCurLoc() {
		return curLoc;
	}
};

int main() {
	int jobs[6];
	cout << "택배를 픽업할 동을 요청 순서대로 6개 입력>>";
	for (int i = 0; i < 6; i++)
		cin >> jobs[i];
	Schedule fcfs(10, jobs, 6);
	fcfs.run();
}