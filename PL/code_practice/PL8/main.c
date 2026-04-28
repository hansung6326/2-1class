#include <stdio.h>

void get_your_name(char name[]);


void main()
{
	char name[64];

	get_your_name(name);
	printf("Nice to meet you, %s\n", name);
}
