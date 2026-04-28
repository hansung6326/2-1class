#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		// 원판이 1개일 때는 바로 출발지에서 목적지로 옮깁니다.
		printf("원판 1을 %c에서 %c로 옮깁니다.\n", from, to);
	}
	else {
		// 1. 위에 있는 n-1개의 원판을 목적지(to)를 거쳐 비어있는 곳(tmp)으로 옮깁니다.
		hanoi_tower(n - 1, from, to, tmp);

		// 2. 맨 아래에 있는 가장 큰 n번 원판을 목적지(to)로 옮깁니다.
		printf("원판 %d를 %c에서 %c로 옮깁니다.\n", n, from, to);

		// 3. 비어있는 곳(tmp)에 두었던 n-1개의 원판을 목적지(to)로 옮깁니다.
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main(void) {
	hanoi_tower(3, 'A', 'B', 'C');

	return 0;
}