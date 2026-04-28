#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    double grade;
} Student;

int main() {
    int n;
    printf("학생 수를 입력하세요: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("유효한 학생 수를 입력하세요.\n");
        return 1;
    }

    Student *students = (Student *)malloc(sizeof(Student) * n);
    if (students == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d번째 학생의 이름을 입력하세요: ", i + 1);
        scanf("%s", students[i].name);

        printf("%d번째 학생의 나이를 입력하세요: ", i + 1);
        scanf("%d", &students[i].age);

        printf("%d번째 학생의 성적을 입력하세요: ", i + 1);
        scanf("%lf", &students[i].grade);
    }

    printf("\n입력한 학생 정보:\n");
    for (int i = 0; i < n; i++) {
        printf("이름: %s, 나이: %d, 성적: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    free(students);
    return 0;
}