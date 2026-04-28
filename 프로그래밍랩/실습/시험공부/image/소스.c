#include <stdio.h>
#define SIZE 5

// 이미지를 3자리 숫자로 예쁘게 출력하는 함수
void print_image(int image[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%03d ", image[i][j]); // 3자리 확보, 빈칸은 0으로 채움
		}
		printf("\n");
	}
	printf("\n");
}

// 포인터를 사용하여 이미지의 밝기를 10만큼 증가시키는 함수
void brighten_image(int image[SIZE][SIZE]) {
	int* ptr;
	// 2차원 배열의 시작 주소를 1차원 포인터에 대입
	ptr = &image[0][0];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			*ptr += 10; // 포인터가 가리키는 곳의 값을 10 증가
			ptr++;      // 다음 메모리 주소(다음 칸)로 이동
		}
	}
}

int main(void) {
	// 5x5 이미지 데이터 초기화
	int image[SIZE][SIZE] = {
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50}
	};

	printf("변경 전 이미지:\n");
	print_image(image);

	brighten_image(image); // 밝기 조절 함수 호출

	printf("변경 후 이미지 (밝기 +10):\n");
	print_image(image);

	return 0;
}