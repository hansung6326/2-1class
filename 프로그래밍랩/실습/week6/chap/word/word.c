#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define WORDS 5

int main() {
	int i;
	char dic[WORDS][2][30] = {
		{"book", "책"},
		{ "boy", "소년"},
		{"computer", "컴퓨터"},
		{"language", "언어"},
		{"rain", "비"}
	};
	char word[30];
	while (1) {
		printf("단어를 입력하시오 (종료 : exit): ");
		scanf("%s", word);
		if (strcmp(word, "exit") == 0) {
			printf("프로그램 종료\n");
			break;
		}
		int found = 0;
		for (i = 0; i < WORDS; i++) {
			if (strcmp(word, dic[i][0]) == 0) {
				printf("%s: %s\n", dic[i][0], dic[i][1]);
				found = 1;
				break;
			}
			else if (strcmp(word, dic[i][1]) == 0) {
				printf("%s: %s\n", dic[i][1], dic[i][0]);
				found = 1;
				break;
			}
		}
		if (!found) {
			printf("사전에 없는 단어입니다.\n");
		}	
	}
	return 0;
}
