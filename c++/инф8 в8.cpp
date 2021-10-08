#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct Employee
{
	char family[15];
	char name[15];
	char street[15];
	int house;
	int flat;
	char departament[15];
};

void printEmployee();
void printEmployees(Employee* employees, int n);
Employee* readFromFile(int* n);
void writeToFile(Employee* employee, int n);

int main()
{
	setlocale(0, "Russian");
	int n = 0, type;

	cout << "1. Создать\n2. Удалить\n3. Редактировать\n4. Вставить\n5. Прочитать\n";
	cin >> type;
	Employee* employee = NULL;
	if (type == 1) {
		cout << "Количество Сотрудников: " << endl;
		cin >> n;
		employee = new Employee[n];

		for (int i = 0; i < n; i++)
		{
			printf("Введите фамилию сотрудника %d: ", i);
			cin >> employee[i].family;
			printf("Введите имя сотрудника %d: ", i);
			cin >> employee[i].name;
			printf("Введите улицу сотрудника %: ", i);
			cin >> employee[i].street;
			printf("Введите дом сотрудника %d: ", i);
			cin >> employee[i].house;
			printf("Введите квартиру сотрудника %d: ", i);
			cin >> employee[i].flat;
			printf("Введите отдел, где работает сотрудник %d: ", i);
			cin >> employee[i].departament;

		}

		writeToFile(employee, n);
	}
	else if (type == 2) {
		int n = 0, index = 0, i, pos = 0;
		employee = readFromFile(&n);

		printEmployees(employee, n);
		cout << "Введите позицию:";
		cin >> pos;

		Employee* stdt = new Employee[n - 1];
		Employee temp;
		for (i = 0; i < n; i++)
		{
			if (i != pos) {
				temp = employee[i];
				stdt[index] = temp;
				index++;
			}
		}

		writeToFile(stdt, n - 1);
	}
	else if (type == 3) {
		int n = 0, i, pos = 0, edit = 0;
		employee = readFromFile(&n);
		printEmployees(employee, n);

		cout << "Введите позицию:";
		cin >> pos;

		std::fstream file("text.bin", std::ios::out | std::ios::binary | std::ios::in);
		int kkk;
		file.seekp(0);
		file.seekg(sizeof(int));
		for (int i = 0; i < pos; i++)
			file.seekg(68, std::ios::cur);
		Employee empl;
		cout << "Введите новые данные: " << endl;
		printf("Введите фамилию сотрудника: ");
		cin >> empl.family;
		printf("Введите имя сотрудника: ");
		cin >> empl.name;
		printf("Введите улицу сотрудника: ");
		cin >> empl.street;
		printf("Введите дом сотрудника: ");
		cin >> empl.house;
		printf("Введите квартиру сотрудника: ");
		cin >> empl.flat;
		printf("Введите отдел, где работает сотрудник: ");
		cin >> empl.departament;
		
		file.write((char*)&empl.family, sizeof empl.family);
		file.write((char*)&empl.name, sizeof empl.name);
		file.write((char*)&empl.street, sizeof empl.street);
		file.write((char*)&empl.house, sizeof empl.house);
		file.write((char*)&empl.flat, sizeof empl.flat);
		file.write((char*)&empl.departament, sizeof empl.departament);

		file.close();
	}
	else if (type == 4) {
		int n = 0, i, pos = 0, index = 0;
		employee = readFromFile(&n);
		Employee emp;

		printf("Введите фамилию сотрудника: ");
		cin >> emp.family;
		printf("Введите имя сотрудника: ");
		cin >> emp.name;
		printf("Введите улицу сотрудника: ");
		cin >> emp.street;
		printf("Введите дом сотрудника: ");
		cin >> emp.house;
		printf("Введите квартиру сотрудника: ");
		cin >> emp.flat;
		printf("Введите отдел, где работает сотрудник: ");
		cin >> emp.departament;


		printEmployees(employee, n);

		cout << "Введите позицию:";
		cin >> pos;
		Employee* employees = new Employee[n + 1];
		Employee temp;
		for (i = 0; i < n; i++)
		{
			if (i != pos) {
				temp = employee[i];
				employees[index] = temp;
				index++;
			}
			else if (i == pos) {
				employees[index] = emp;
				index++;
				temp = employee[i];
				employees[index] = temp;
				index++;
			}
		}

		writeToFile(employees, n + 1);
	}
	else if (type == 5) {
		printEmployee();
	}
}

void printEmployee() {
	int n;
	Employee* employees = readFromFile(&n);
	printEmployees(employees, n);
	char departament[15];
	char street[15];

	cout << "Введите название отдела и улицу: " << endl;
	cin >> departament;
	cin >> street;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(employees[i].departament, departament) == 0)
			if (strcmp(employees[i].street, street) == 0)
				cout << " Фамилия: " << employees[i].family << endl;
	}

}

void printEmployees(Employee* employee, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << i << "   " << " Фамилия: " << employee[i].family << " Имя: " << employee[i].name << " Улица: " << employee[i].street << " Дом: " << employee[i].house << " Квартира: " << employee[i].flat << " Отдел: " << employee[i].departament << endl;
	}
}

Employee* readFromFile(int* n) {
	ifstream fin("text.bin", ios::binary | ios::in);
	*n = 0;
	int i;
	fin.read((char*)&(*n), sizeof(int));
	Employee* employee = new Employee[*n];
	for (i = 0; i < *n; i++) {
		fin.read((char*)&employee[i].family, sizeof(employee[i].family));
		fin.read((char*)&employee[i].name, sizeof(employee[i].name));
		fin.read((char*)&employee[i].street, sizeof(employee[i].street));
		fin.read((char*)&employee[i].house, sizeof(employee[i].house));
		fin.read((char*)&employee[i].flat, sizeof(employee[i].flat));
		fin.read((char*)&employee[i].departament, sizeof(employee[i].departament));
	}
	fin.close();

	return employee;
}

void writeToFile(Employee* employee, int n) {
	std::remove("text.bin");
	ofstream file("text.bin", ios::binary | ios::out | ios::trunc);
	file.write((char*)&n, sizeof(n));

	for (int i = 0; i < n; i++) {
		file.write((char*)&employee[i].family, sizeof employee[i].family);
		file.write((char*)&employee[i].name, sizeof employee[i].name);
		file.write((char*)&employee[i].street, sizeof employee[i].street);
		file.write((char*)&employee[i].house, sizeof employee[i].house);
		file.write((char*)&employee[i].flat, sizeof employee[i].flat);
		file.write((char*)&employee[i].departament, sizeof employee[i].departament);
	}

	file.close();
}