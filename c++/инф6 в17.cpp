#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
	setlocale(0, "Russian");
	char text[100], *p;
	const char *razd = " .,";
	int dlina;
	puts("Введите текст ");
	gets_s(text);
	p = strtok(text, razd);
	int c = 2;
	while (p!=0 && c>0) {
		dlina = strlen(p);
		cout << "\n слово " << p << " длина = " << dlina << "\n";
		p = strtok(NULL, razd);
		c--;
	}
	system("pause");
	return 0;
}