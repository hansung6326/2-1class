#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void) {
	char** p;
	p = (char**)malloc(sizeof(char*) * 2);
	for (int i = 0; i < 2; i++) {
		*(p + i) = (char*)malloc(sizeof(char) * 3);
	}

	for (int i = 0; i < 2; i++) {
		// p[i] 포인터 변수 자체의 주소 출력
		printf("*(p + %d)에 해당하는 메모리 주소 = %p\n", i, p + i);
		for (int j = 0; j < 3; j++) {
			*(*(p + i) + j) = i * 3 + j; // 값 할당
			// 실제 데이터가 저장된 주소와 값 출력
			printf("*(*(p + %d) + %d)에 해당하는 메모리 주소(%p)와 값(%d)\n", i, j, *(p + i) + j, *(*(p + i) + j));
		}
	}

	// 해제 할 때는 할당한 것의 역순으로
	for (int i = 0; i < 2; i++) {
		free(*(p + i));
	}
	// *(p+0), *(p+1)을 가리키는 포인터 배열 메모리 해제
	free(p);

	return 0;
}