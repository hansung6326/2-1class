#include <stdio.h>

int main(void) {
	char line[100] = "";  // 원본 문자열 저장 배열
	char line2[100] = ""; // 영문자만 골라 저장할 배열

	printf("문자열 입력: ");
	gets_s(line, sizeof(line)); // 공백을 포함하여 문자열 입력 받음

	int k = 0;
	for (int i = 0; line[i] != '\0'; ++i) {
		// 현재 문자가 영문자인지 확인 (알파벳 범위 체크)
		// 주의: 'A' ~ 'z' 사이에는 특수문자 [ \ ] ^ _ ` 도 포함되어 있습니다.
		while ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
			line2[k++] = line[i++]; // 영문자라면 line2에 복사하고 인덱스 증가

			// 문자열의 끝('\0')을 만났을 때 while문을 안전하게 빠져나오기 위한 체크
			if (line[i] == '\0') break;
		}
	}
	line2[k] = '\0'; // 새로운 문자열의 끝을 알리는 널 문자 추가

	printf("출력 문자열: %s\n", line2);
	return 0;
}