#include <stdio.h>

int main(void) { //예제3
	char str[] = "A barking dog never bites";
	int i = 0;
	while (str[i] != 0) //0의 의미는 NULL, NULL이 될 때까지 while 반복 하라는 의미
		i++;
	printf("문자열 %s의 길이는 %d\n", str, i);
}

int main(void) { //예제2
	char str[] = "komputer";
	printf("%s\n", str);
	str[0] = 'c';
	printf("%s\n", str);
}

int main(void) { //예제 1
	char str1[6] = "Seoul";
	char str2[3] = { 'i','s','\0' };
	char str3[] = "the capital city of Korea."; //배열의 크기 = 문자 개수 + NULL(1개) 27개

	printf("%s %s %s", str1, str2, str3);
	return 0;
}