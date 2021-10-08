#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;
	setlocale(0, "Russian");
	cout << "Введите значения аргумента и точности\n";
	cin >> x >> eps;
	double F = (x - 1), a = (x - 1);
	double n = 2;
	while (fabs(a/n) >= eps)
	{
		a *= -(x-1);
		F += a/n;
		n ++;
	}
	cout << "Приближенное значение ln x = " << F << endl;
	cout << "Точное значение ln x = " << log(x);
}