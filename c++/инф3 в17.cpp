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
		a *= x*x;
		F += a / n;
		n += 2;
	}
	cout << "Приближенное значение arth x = " << F << endl;
	cout << "Точное значение arth x = " << atanh(x);
}