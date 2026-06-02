#ifndef CAFFE_H
#define CAFFE_H

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

#endif
