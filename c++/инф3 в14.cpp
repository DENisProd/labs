#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	double pi = 3.1415926535;
	double F = x, a = x;
	double n = 3;
	while (abs(a / n) >= eps)
	{
		a *= ((n-2)*x*x)/(n-1);
		F += a / n;
		n += 2;
	}
	F = (pi / 2) - F;
	cout << "Приближенное значение arccos x = " << F << endl;
	cout << "Точное значение arccos x = " << acos(x);
}