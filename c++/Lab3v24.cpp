#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	double F = 1, a = 1;
	double n = 1;
	while (fabs(a) >= eps)
	{
		a *= -x;
		F += a;
		n += 1;
	}
	cout << "Приближенное значение 1/(1+x) = " << F << endl;
	cout << "Точное значение 1/(1+x) = " << (1/(1+x));
}