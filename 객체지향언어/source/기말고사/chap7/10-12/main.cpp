#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Moving {
	string location;
	int distance;
public:
	Moving(string location, int distance);
	string showLocation();
	int showDistance();
};
Moving::Moving(string location, int distance) {
	this->location = location;
	this->distance = distance;
}
string Moving::showLocation() {
	return location;
}
int Moving::showDistance() {
	return distance;
}

int main() {
	vector<Moving> v;
	string location;
	int distance;
	while (true) {
		cout << "목적지와 이동거리 입력>>";
		cin >> location >> distance;
		v.push_back(Moving(location, distance));
		if (location == "우리집")
			break;
	}
	
	int sum = 0;
	vector<Moving>::iterator it = v.begin();
	cout << it->showLocation() << ":" << it->showDistance() << "km";
	sum += it->showDistance();
	it++;
	for (; it != v.end(); it++) {
		cout << "->" << it->showLocation() << ":" << it->showDistance() << "km";
		sum += it->showDistance();
	}
	cout << endl;
	cout << "총 이동 거리는 " << sum << "km" << endl;

}