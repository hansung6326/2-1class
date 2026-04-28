#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp1, * fp2;
    char file1[100], file2[100];
    char line1[1000], line2[1000];
    int is_equal = 1;

    printf("첫번째 파일 이름: ");
    scanf("%s", file1);

    printf("두번째 파일 이름: ");
    scanf("%s", file2);

    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("%s 파일을 열지 못했습니다.\n", file1);
        exit(1);
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("%s 파일을 열지 못했습니다.\n", file2);
        fclose(fp1);
        exit(1);
    }

    while (1) {
        char* p1 = fgets(line1, sizeof(line1), fp1);
        char* p2 = fgets(line2, sizeof(line2), fp2);

        if (p1 == NULL && p2 == NULL) {
            break;
        }

        if (p1 == NULL || p2 == NULL) {
            is_equal = 0;

            printf("<< %s >> %s", (p1 == NULL) ? "" : line1, (p2 == NULL) ? "" : line2);
            break;
        }

        if (strcmp(line1, line2) != 0) {
            printf("<< %s >> %s", line1, line2);
            is_equal = 0;
            break;
        }
    }

    if (is_equal)
        printf("파일은 서로 일치함\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}