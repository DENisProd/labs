#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
void main()
{
	double a[15];
	int c=0,c1 = 0;
	double sum = 0;

	
	printf("Enter numbers\n");
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] < 0)
		{
			c++;
			sum += a[i];
		}
		else if (a[i] >= 0 && a[i] <= 5)
		{
			c1++;
		}
	}

	double sr = sum / c;

	printf("\nSrednee arifmeticheskoe oric= %d\n", sr);
	printf("\nKolichestvo [0..5]= %d\n", c1);
}