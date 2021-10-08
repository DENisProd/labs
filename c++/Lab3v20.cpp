#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps, pi2 = 3.1415 / 2.0;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	double F = x, a = x;
	double n = 3;
	while (abs(a / n) >= eps)
	{
		a *= -x * x;
		F += a / n;
		n += 2;
	}

	F = pi2 - F;
	cout << "Приближенное значение arcctg x = " << F << endl;
	cout << "Точное значение arcctg x = " << pi2 - atan(x);
}