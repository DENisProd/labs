#include <iostream>
using namespace std;
int main()
{
	double arr[10];

	double prod = 1;
	int c = 0;

	double *end = arr + 10;

	for (double* num = arr; num < end; num++)
	{
		scanf_s("%lf", num);
		if (*num < 15)
		{
			c++;
		}
		if (*num >= 10 && *num <= 15)
		{
			prod *= *num;
		}
	}

	printf("\nKolichestvo < 15 = %d\n", c);
	if (prod == 1) printf("Chisel [10..15] net");
	else printf("\nProd [10..15]= %lf\n", prod);

	system("pause");
	return 0;
}