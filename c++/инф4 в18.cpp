#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
void main()
{
	int a[15];
	int c = 0;
	printf("Enter numbers\n");
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] == 0)
		{
			c++;
		}
		else if (a[i]>=-5 && a[i]<=5)
		{
			a[i] *= a[i];
		}
		printf("%d ", a[i]);
	}


	
	printf("\nKolichestvo nuley= %d\n", c);
}