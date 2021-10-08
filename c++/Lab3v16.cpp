#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	double F = x, a = x;
	double n = 3;
	while (abs(a / n) >= eps)
	{
		a *= -x * x*(n-2)/(n-1);
		F += a / n;
		n += 2;
	}
	cout << "Приближенное значение arsh x = " << F << endl;
	cout << "Точное значение arsh x = " << asinh(x);
}