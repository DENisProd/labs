#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, b, eps;

	setlocale(0, "Russian");

	cout << "Введите значение аргументов a,d и точности\n";
	cin >> a >> b >> eps;

	double M = 0.434294482;
	double F = (b / (2 * a + b)), x = (b / (2 * a + b));
	int n = 3;
	while (fabs(x / n) >= eps)
	{
		x *= (b / (2 * a + b)) * (b / (2 * a + b));
		F += x / n;
		n += 2;
	}
	F *= 2 * M;
	F += log10(a);

	cout << "Приближенное значение lg(a+b) = " << F << endl;
	cout << "Точное значение lg(a+b) = " << log10(a + b);

	return 0;
}