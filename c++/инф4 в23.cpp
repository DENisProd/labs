#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	double array1[15];

	double sum = 0;
	int c = 0;

	for (int counter = 0; counter < 15; counter++)
	{
		scanf_s("%lf", &array1[counter]);
		if (array1[counter] == 0)
		{
			c++;
		}
		if (array1[counter] <= 1 && array1[counter] >= -1)
		{
			array1[counter] *= array1[counter] * array1[counter];
		}
	}

	for (int counter = 0; counter < 15; counter++)
	{
		printf("%lf ", array1[counter]);
	}
	
	printf("\nKolichestvo= %d\n", c);

	system("pause");
	return 0;
}