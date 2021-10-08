#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
void main()
{
	int a[12];
	int c=0;
	int sum = 0;

	
	printf("Enter numbers\n");
	for (int i = 0; i < 12; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] < 0)
		{
			sum += a[i];
		}
		if ((a[i] % 2) != 0)
		{
			c++;
		}
	}

	printf("\nSumma otric= %d\n", sum);
	printf("\nKolichestvo nechet %d\n", c);
}