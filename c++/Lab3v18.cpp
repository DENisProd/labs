#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	long double F = 1 / x, a = 1/x;
	long double n = 3;

	while (abs(a / n) > eps)
	{
		a *= 1 / (x*x);
		F += a / n;
		n += 2;
	}

	cout << "Приближенное значение arcth x = " << F << endl;
	cout << "Точное значение arcth x = " << 0.5 * log((x + 1.0) / (x - 1.0));
}