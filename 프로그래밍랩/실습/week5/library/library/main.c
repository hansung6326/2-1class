#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>



typedef struct book {

    int id;

    char author[50];

    char title[100];

} book;



int main(void) {

    printf("2371172 안태호\n");

    book library[100];

    int count = 0;

    int select;

    char search_str[100];

    int search_id;

    int found;



    while (1) {

        printf("\n=======================================\n");

        printf("1. 도서 번호로 책 찾기\n");

        printf("2. 저자 이름으로 책 찾기\n");

        printf("3. 제목으로 책 찾기\n");

        printf("4. 새로운 책 추가\n");

        printf("5. 도서관이 소장한 도서의 수 표시\n");

        printf("6. 종료\n");

        printf("=======================================\n");

        printf("메뉴 중에서 하나를 선택하세요 : ");

        scanf("%d", &select);



        switch (select) {

        case 1:

            printf("도서 번호 입력 : ");

            scanf("%d", &search_id);

            found = 0;

            for (int i = 0; i < count; i++) {

                if (library[i].id == search_id) {

                    printf("책 제목 : %s\n", library[i].title);

                    printf("저자 : %s\n", library[i].author);

                    found = 1;

                }

            }

            if (!found) printf("해당 번호의 책이 없습니다.\n");

            break;

        case 2:

            printf("저자 이름 입력 : ");

            scanf("%s", search_str);

            found = 0;

            for (int i = 0; i < count; i++) {

                if (strcmp(library[i].author, search_str) == 0) {

                    printf("ID : %d | %s | %s\n", library[i].id, library[i].title, library[i].author);

                    found = 1;

                }

            }

            if (!found) printf("해당 저자의 책이 없습니다.\n");

            break;

        case 3:

            printf("책 제목 입력 : ");

            scanf("%s", search_str);

            found = 0;

            for (int i = 0; i < count; i++) {

                if (strcmp(library[i].title, search_str) == 0) {

                    printf("ID : %d | %s | %s\n", library[i].id, library[i].title, library[i].author);

                    found = 1;

                }

            }

            if (!found) printf("해당 제목의 책이 없습니다.\n");

            break;

        case 4:

            library[count].id = count;

            printf("책 이름 : ");

            scanf("%s", library[count].title);

            printf("저자 이름 : ");

            scanf("%s", library[count].author);

            printf("ID : %d | %s | %s\n", library[count].id, library[count].title, library[count].author);

            printf("추가 완료!\n");

            count++;

            break;

        case 5:

            printf("총 도서 수 : %d\n", count);

            for (int i = 0; i < count; i++) {

                printf("ID : %d | %s | %s\n", library[i].id, library[i].title, library[i].author);

            }

            break;

        case 6:

            printf("프로그램을 종료합니다\n");

            return 0;

        default:

            printf("잘못된 선택입니다.\n");

            break;

        }

    }



    return 0;

}