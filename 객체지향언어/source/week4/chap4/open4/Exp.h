#ifndef EXP_H
#define EXP_H

class Exp {
	int base, exp;
public:
	Exp();
	Exp(int b);
	Exp(int b, int e);
	int getValue();
	bool equals(Exp b);
	int getBase() { return base; };
	int getExp() { return exp; };
};

#endif