#include<iostream>
void main()
{
	double a[15];
	double raz = 0;
	int c = 0;
	printf("Enter numbers\n");
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%lf", &a[i]);
		if (a[i] < 0)
		{
			c++;
			
		}
		else if (a[i] > 0)
		{
			raz -= a[i];
		}
	}


	printf("Kolichestvo oricatelnih= %lf\n", c);
	printf("raznost polozhitelnih= %d", raz);
}
