#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
	string owner;
	int balance;
public:
	Account(string n);
	void deposit(int money);
	int withdraw(int money);
	int inquiry();
	string getOwner() { return owner; }
};

#endif
