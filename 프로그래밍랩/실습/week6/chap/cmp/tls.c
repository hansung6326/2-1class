#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	const char s[] = "100";
	char t[100] = "";
	int i;
	printf("%d \n", atoi("100")); //atoi()는 문자열 "100"을 정수 100으로 바꿈
	sscanf(s, "%d", &i); //문자열 "100"을 정수 100으로 i에 저장
	sprintf(t, "%d", 100); //정수 100을 문자열 "100"으로 t에 저장
	return 0;
}