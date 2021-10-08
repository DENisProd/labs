#include <iostream>
#include <stdio.h>
#include <cmath>

int main(int argc, char* argv[]) {
	long double a, b, eps;

	setlocale(0, "Russian");

	printf("Введите значения a,b (-1<b/a*a<1) и точности\n");
	scanf_s("%lf%lf%lf", &a, &b, &eps);

	long double F = 1 + 0.5 * b / (a * a);
	long double l1 = 1 + 0.5 * b / (a * a);
	long double n = 2;
	while (fabs(l1) >= eps)
	{
		l1 *= -(3 - 2 * n) / ((1 - 2 * n) * n * 4) * b / (a * a);
		F += l1;
		n += 1;
	}
	F *= a;

	printf("Приближенное значение sqrt(a*a+b) = %lf\n", F);
	printf("Точное значение sqrt(a*a+b) = %lf\n", sqrt(a * a + b));
	return 0;
}