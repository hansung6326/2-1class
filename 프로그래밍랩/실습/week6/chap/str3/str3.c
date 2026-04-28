#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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