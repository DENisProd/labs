#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int main() {
	int i, j;
	char t[6], a[10][6] = { "qwark","mango","table","prinz","sport", "aboba", "hello", "world", "redis", "cover" };
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9 - i; j++)
			if (strcmp(a[j], a[j + 1]) > 0)
			{
				strcpy(t, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], t);
			}
	for (i = 0; i < 10; i++)
		printf("%s ", a[i]);
	printf("\n");
	return 0;
}