#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	FILE* fp1, * fp2;
	char f1[100], f2[100];
	char line1[1000], line2[1000];
	char diff1[1000] = { 0 };
	char diff2[1000] = { 0 };
	int found = 0;

	printf("첫번째 파일 이름: ");
	scanf("%s", f1);
	printf("두번째 파일 이름: ");
	scanf("%s", f2);

	fp1 = fopen(f1, "r");
	fp2 = fopen(f2, "r");

	if (!fp1 || !fp2) {
		printf("파일 열기 실패\n");
		return 1;
	}

	while (fgets(line1, sizeof(line1), fp1) && fgets(line2, sizeof(line2), fp2)) {
		if (strcmp(line1, line2) != 0) {
			found = 1;

			char* context1;
			char* context2;

			char* p1 = strtok_s(line1, " \n\r", &context1);
			char* p2 = strtok_s(line2, " \n\r", &context2);

			while (p1 != NULL || p2 != NULL) {
				if (p1 && p2) {
					if (strcmp(p1, p2) != 0) {
						strcat(diff1, p1);
						strcat(diff1, " ");
						strcat(diff2, p2);
						strcat(diff2, " ");
					}
				}
				else if (p1) {
					strcat(diff1, p1);
					strcat(diff1, " ");
				}
				else if (p2) {
					strcat(diff2, p2);
					strcat(diff2, " ");
				}

				p1 = strtok_s(NULL, " \n\r", &context1);
				p2 = strtok_s(NULL, " \n\r", &context2);
			}
			break;
		}
	}

	if (found) {
		printf("<< %s>> %s\n", diff1, diff2);
	}
	else {
		printf("파일은 서로 일치함\n");
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}