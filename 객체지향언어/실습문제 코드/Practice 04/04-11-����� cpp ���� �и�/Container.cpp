#include "Container.h"

void Container::fill(int n) { // n 만큼 채우기
	size = n;
}

bool Container::consume(int n) { // n 만큼 소모하기
	if (size < n)
		return false;
	else {
		size -= n;
		return true;
	}
}

int Container::getSize() { // 현재 크기 리턴
	return size;
}