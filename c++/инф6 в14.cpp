#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(0, "Russian");
	string line;
	int c = 0;

	cout << "Введите строку ";
	getline(cin, line);

	int n = line.length();
	char* char_array = new char[n + 1];

	char_array = _strdup(line.c_str());

	char* p = strtok(char_array, " ");

	while (p) {
		if (p[0] == p[strlen(p) - 1]) c++;
		p = strtok(NULL, " ");
	}

	cout << "\n" << c << " слов начинаются и заканчиваются на одну букву.\n";

	return 0;
}