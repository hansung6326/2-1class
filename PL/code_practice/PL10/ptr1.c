#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* str;

	str = (char*)malloc(sizeof(char)*32);
	strcpy(str, "this is a string");
	printf("%s\n", str);
}
