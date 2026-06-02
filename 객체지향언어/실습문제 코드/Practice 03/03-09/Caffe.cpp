#include <iostream>
#include <cstring>
using namespace std;

class Caffe {
	const int PRICE_ESPRESSO = 3000;
	const int PRICE_AMERICANO = 3500;
	const int PRICE_CAPPUCCINO = 4000;
	const int MAX_SALES = 30000;
	int totalSale = 0; // 현재까지 판매 총 금액
	int getOrder();
	void printMenu();
	void serviceOrder();
public:
	void run();
};

void Caffe::run() {
	printMenu();
	serviceOrder();
}

void Caffe::printMenu() {
	cout << "에스프레소 " << PRICE_ESPRESSO << "원,";
	cout << "아메리카노 " << PRICE_AMERICANO << "원,";
	cout << "카푸치노 " << PRICE_CAPPUCCINO << "원입니다." << endl;
}

int Caffe::getOrder() {
	int order; // 주문한 금액
	char coffee[100]; // 주문한 커피 종류
	int num; // 잔 수

	cout << "주문>>";
	cin >> coffee >> num;
	if (num <= 0) { // 잔 수를 양수가 아니게 입력한 경우
		cout << "잔 수는 양수를 입력해주세요" << endl;
		return -1;
	}
	if (strcmp(coffee, "에스프레소") == 0) {
		order = PRICE_ESPRESSO * num;
	}
	else if (strcmp(coffee, "아메리카노") == 0) {
		order = PRICE_AMERICANO * num;
	}
	else if (strcmp(coffee, "카푸치노") == 0) {
		order = PRICE_CAPPUCCINO * num;
	}
	else {
		order = 0;
	}

	return order;
}
void Caffe::serviceOrder() {
	while (true) {
		int order = getOrder();
		if (order == -1)
			continue; //  다시 입력

		// 사용자에게 주문한 가격 출력
		if (order > 0) { // 정상적인 주문의 경우
			cout << order << "원입니다. 맛있게 드세요" << endl;
		}
		else // 없는 커피 주문한 경우
			cout << "없는 커피입니다. 다시 입력해주세요" << endl;

		// MAX_SALES원 이상 벌었는지 판단
		totalSale += order;
		if (totalSale >= MAX_SALES) {
			cout << "오늘 " << totalSale << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
			break;
		}
	} // end of while
}

int main() {
	Caffe myCaffe;
	myCaffe.run();
}