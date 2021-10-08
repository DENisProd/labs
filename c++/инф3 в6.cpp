/* Программирование циклов с неизвестным заранее числом повторений */
/* sh x */
/* Разложение в ряд: x + (x^3 /3!) + (x^5/5!) - (x^7 /7!) + ... */

#include <iostream>
#include <math.h>

using namespace std;

void main()
{
	double x, eps;

	setlocale(0, "Russian");

	cout << "Введите значение аргумента и точности\n";
	cin >> x >> eps;

	double F = x, a = x;
	double n = 3;
	while (fabs(a) >= eps)
	{
		a *= (x * x)/(n*(n-1));
		F += a;
		n += 2;
	}

	cout << "Приближенное значение sh x = " << F << endl;
	cout << "Точное значение sh x = " << sinh(x);
}