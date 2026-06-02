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
        jobs = new int[count];
        for (int i = 0; i < count; i++)
            jobs[i] = n[i];
        cout << "현재 위치는 " << curloc << "동: 배달 시작 ..." << curloc;
        for (int i = 0; i < count; i++)
            cout << " -> " << jobs[i];
        cout << endl;
    }
    ~Schedule() {
        delete[] jobs;
    }
    int run() {
        int sum = 0, add = 0;
        for (int i = 0; i < count; i++) {
            add = abs(curLoc - jobs[i]);
            curLoc = jobs[i];
            sum += add;
        }
        return sum;
    }
    int getJobs() { return count; }
    int getCurLoc() { return curLoc; }
};

class ShortestFirst : public Schedule {
    bool* visited;
public:
    ShortestFirst(int curloc, int n[], int count) : Schedule(curloc, n, count) {
        int p = 0;

        for (int i = 0; i < count; i++) {
            int shortest = -1;
            for (int j = 0; j < count; j++) {
                if (shortest == -1 || (abs(curLoc - n[j]) < abs(curLoc - n[shortest])))
                    shortest = j;
            }
            jobs[p] = n[shortest];
            p++;
        }


        cout << "현재 위치는 " << curloc << "동: 배달 시작 ..." << curloc;

        for (int i = 0; i < count; i++) {
            int shortest = -1;
            for (int j = 0; j < count; j++) {
                if (!tmpVisited[j]) {
                    if (shortest == -1 || abs(tmpLoc - jobs[j]) < abs(tmpLoc - jobs[shortest]))
                        shortest = j;
                }
            }
            
            cout << " -> " << jobs[shortest];
            tmpLoc = jobs[shortest];
            tmpVisited[shortest] = true;
        }
        cout << endl;
        delete[] tmpVisited;
    }

    ~ShortestFirst() {
        delete[] visited;
    }

    int run() {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            int shortest = -1;
            for (int j = 0; j < count; j++) {
                if (!visited[j]) {
                    if (shortest == -1 || abs(curLoc - jobs[j]) < abs(curLoc - jobs[shortest]))
                        shortest = j;
                }
            }
            sum += abs(curLoc - jobs[shortest]);
            curLoc = jobs[shortest];
            visited[shortest] = true;
        }
        return sum;
    }
};

int main() {
    int jobs[6];
    cout << "택배를 픽업할 동을 요청 순서대로 6개 입력>>";
    for (int i = 0; i < 6; i++)
        cin >> jobs[i];

    Schedule fcfs(10, jobs, 6);
    cout << "전체 움직인 거리는 " << fcfs.run() << ", ";
    cout << "현재 위치는 " << fcfs.getCurLoc() << "동" << endl;

    ShortestFirst sf(10, jobs, 6);
    cout << "전체 움직인 거리는 " << sf.run() << ", ";
    cout << "현재 위치는 " << sf.getCurLoc() << "동" << endl;
}