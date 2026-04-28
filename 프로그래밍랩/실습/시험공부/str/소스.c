#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//int main(void) { //예제3
//	char str[] = "A barking dog never bites";
//	int i = 0;
//	while (str[i] != 0) //0의 의미는 NULL, NULL이 될 때까지 while 반복 하라는 의미
//		i++;
//	printf("문자열 %s의 길이는 %d\n", str, i);
//}

//int main(void) { //예제2
//	char str[] = "komputer";
//	printf("%s\n", str);
//	str[0] = 'c';
//	printf("%s\n", str);
//}

//int main(void) { //예제 1
//	char str1[6] = "Seoul";
//	char str2[3] = { 'i','s','\0' };
//	char str3[] = "the capital city of Korea."; //배열의 크기 = 문자 개수 + NULL(1개) 27개
//
//	printf("%s %s %s", str1, str2, str3);
//	return 0;
//}


//int main(void) {
//	char line[100] = "";  // 원본 문자열 저장 배열
//	char line2[100] = ""; // 영문자만 골라 저장할 배열
//
//	printf("문자열 입력: ");
//	gets_s(line, sizeof(line)); // 공백을 포함하여 문자열 입력 받음
//
//	int k = 0;
//	for (int i = 0; line[i] != '\0'; ++i) {
//		// 현재 문자가 영문자인지 확인 (알파벳 범위 체크)
//		// 주의: 'A' ~ 'z' 사이에는 특수문자 [ \ ] ^ _ ` 도 포함되어 있습니다.
//		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
//			line2[k++] = line[i]; // 영문자라면 line2에 복사하고 인덱스 증가
//
//			// 문자열의 끝('\0')을 만났을 때 while문을 안전하게 빠져나오기 위한 체크
//			if (line[i] == '\0') break;
//		}
//	}
//	line2[k] = '\0'; // 새로운 문자열의 끝을 알리는 널 문자 추가
//
//	printf("출력 문자열: %s\n", line2);
//	return 0;
//}

int main(void) {
	char password[10];
	int i;

	system("cls");
	printf("패스워드를 입력: ");
	for (i = 0; i < 8; i++) {
		password[i] = _getch();
		printf("*");
	}
	password[i] = '\0';
	printf("\n");

	printf("입력된 패스워드: %s\n", password);
	//_getch(); //콘솔창이 바로 닫히는 경우를 방지
	return 0;
}


//int main() {
//	const char s[] = "100";
//	char t[100] = "";
//	int i;
//	printf("%d \n", atoi("100")); //atoi()는 문자열 "100"을 정수 100으로 바꿈
//	sscanf(s, "%d", &i); //문자열 "100"을 정수 100으로 i에 저장
//	sprintf(t, "%d", 100); //정수 100을 문자열 "100"으로 t에 저장
//	return 0;
//}

//int main() {
//	char key[] = "C";
//	char buffer[80] = "";
//	do {
//		printf("임베디드 장치에 가장 많이 사용되는 언어는? ");
//		gets_s(buffer, sizeof(buffer));
//	} while (strcmp(key, buffer) != 0);
//	printf("맞았습니다!");
//	return 0;
//}