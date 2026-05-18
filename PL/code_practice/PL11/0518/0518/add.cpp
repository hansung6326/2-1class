#include <stdio.h>

extern int big;

void add(int &a, int &b) // 함수 정의
{
	big += 10;
	a += 2;
	b += 4;
}