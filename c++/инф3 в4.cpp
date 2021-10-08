/* Программирование циклов с неизвестным заранее числом повторений */
/* cos x */
/* Разложение в ряд: 1-(x^2 /2!) + (x^4/4!) - (x^6/6!) + ... */

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
		a *= -x * x;
		F += a / n;
		n += 2;
	}
	cout << "Приближенное значение arctg x = " << F << endl;
	cout << "Точное значение arctg x = " << atan(x);
}