#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "구입할 물품의 개수>>";
	cin >> n;
	int* price = new int[n];
	cout << "물품" << n << "개의 가격 입력>>";
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	int min = price[0];
	int max = price[0];

	for (int i = 1; i < n; i++) {
		if (min > price[i])
			min = price[i];
		if (max < price[i])
			max = price[i];
	}
	cout << "제일 싼 가격은 " << min << endl;
	cout << "제일 비싼 가격은 " << max << endl;

	delete[] price;
	return 0;
}