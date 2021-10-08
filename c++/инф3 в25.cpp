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
	while (fabs(a/n) >= eps)
	{
		a *= x*x;
		F += a/n;
		n += 2;
	}
	F *= 2;
	cout << "Приближенное значение ln((1+x)/(1-x)) = " << F << endl;
	cout << "Точное значение ln((1+x)/(1-x)) = " << log((1 + x) / (1 - x));
}