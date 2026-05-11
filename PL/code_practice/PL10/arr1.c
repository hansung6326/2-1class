#include <stdio.h>

int main()
{
	char str1[32];
	char str2[32] = "Hansung";
	char str3[] = "Hansung";

	printf("hello\n");

	char name1[][32] = {"Kim", "Lee", "Choi", "Park"};
	char *name2[] = {"Kim", "Lee", "Choi", "Park"};
	printf("hello\n");
}
