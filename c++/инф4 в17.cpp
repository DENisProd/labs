#include<iostream>
void main()
{
	double a[10];
	double sum = 0;
	int c = 0;
	printf("Enter numbers\n");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%lf", &a[i]);
		if (a[i] < 0)
		{
			sum += a[i];
		}
		else if (a[i] >= 2.5 && a[i] <= 3.5)
		{
			c++;
		}
	}
		

	printf("Summa oricatelnih= %lf\n", sum);
	printf("Kolichestvo= %d", c);
}
