// Файлы
/*  Дана структура, в которой хранятся данные о полетах самолетов: название пункта назначения рейса, номер рейса, тип самолета. 
	Определите, сколько студентов имеют неудовлетворительную оценку хотя бы по одному предмету. */

/*  1.	На основе заданий лабораторной 7 выполнить запись и чтение данных в текстовый и бинарный файлы, используя методы 
		потокового ввода-вывода и ввода-вывода нижнего уровня.
	2.	Сделать тестовый пример, показывающий умение редактировать файл: изменять запись, вставлять данные, удалять данные. */


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct STUDENT {
	char fam[15];
	char name[15];
	char otch[15];
	int math;
	int phys;
	int cherch;
	int him;
	int sopr;
};

void printStrudent();
void printStudents(STUDENT* stud1, int n);
STUDENT* readFromFile(int* n);
void writeToFile(STUDENT* stud, int n);

int main()
{
	setlocale(0, "Russian");
	int n = 0, type;

	cout << "1. Создать\n2. Удалить\n3. Редактировать\n4. Вставить\n5. Прочитать\n";
	cin >> type;
	STUDENT* stud = NULL;
	if (type == 1) {
		cout << "Количество студентов: " << endl;
		cin >> n;
		stud = new STUDENT[n];

		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "]" << " Введите фамилию, имя, отчество и оценки по математике, физике, черчении, химии и сопромату" << endl;
			cin >> stud[i].fam;
			cin >> stud[i].name;
			cin >> stud[i].otch;
			cin >> stud[i].math;
			cin >> stud[i].phys;
			cin >> stud[i].cherch;
			cin >> stud[i].him;
			cin >> stud[i].sopr;
		}

		writeToFile(stud, n);
	}
	else if (type == 2) {
		int n = 0;
		int i;
		stud = readFromFile(&n);

		printStudents(stud, n);

		cout << "Введите позицию:";
		int pos = 0;
		cin >> pos;

		STUDENT* stdt = new STUDENT[n - 1];

		int index = 0;
		STUDENT temp;
		for (i = 0; i < n; i++)
		{
			if (i != pos) {
				temp = stud[i];
				stdt[index] = temp;
				index++;
			}
		}

		writeToFile(stdt, n-1);
	}
	else if (type == 3) {
		int n = 0;
		int i;
		stud = readFromFile(&n);

		printStudents(stud, n);

		cout << "Введите позицию:";
		int pos = 0;
		cin >> pos;

		cout << "1. Изменить ФИО\n2. Изменить Баллы\n";
		int edit = 0;
		cin >> edit;

		std::fstream file("text.bin", std::ios::out | std::ios::binary | std::ios::in);
		int kkk;
		file.seekp(0);
		file.seekg(sizeof(int));
		for (int i = 0; i < pos; i++)
			file.seekg(65, std::ios::cur);
		if (edit == 1) {
			char str1[15], str2[15], str3[15];
			cout << "Введите Новое ФИО: " << endl;
			cin >> str1;
			cin >> str2;
			cin >> str3;
			file.write((char*)&str1, sizeof(str1));
			file.write((char*)&str2, sizeof(str2));
			file.write((char*)&str3, sizeof(str3));
		}
		else {
			file.seekg(45, std::ios::cur);
			int m, p, c, h, s;
			cin >> m;
			cin >> p;
			cin >> c;
			cin >> h;
			cin >> s;
			file.write((char*)&m, sizeof(m));
			file.write((char*)&p, sizeof(p));
			file.write((char*)&c, sizeof(c));
			file.write((char*)&h, sizeof(h));
			file.write((char*)&s, sizeof(s));
		}

		file.close();
	}
	else if (type == 4) {
		int n = 0;
		int i;
		stud = readFromFile(&n);

		STUDENT stu;

		cout << " Введите фамилию, имя, отчество и оценки по математике, физике, черчении, химии и сопромату" << endl;
		cin >> stu.fam;
		cin >> stu.name;
		cin >> stu.otch;
		cin >> stu.math;
		cin >> stu.phys;
		cin >> stu.cherch;
		cin >> stu.him;
		cin >> stu.sopr;

		printStudents(stud, n);

		cout << "Введите позицию:";
		int pos = 0;
		cin >> pos;

		STUDENT* stdt = new STUDENT[n + 1];

		int index = 0;
		STUDENT temp;
		for (i = 0; i < n; i++)
		{
			if (i != pos) {
				temp = stud[i];
				stdt[index] = temp;
				index++;
			}
			else if (i == pos) {
				stdt[index] = stu;
				index++;
				temp = stud[i];
				stdt[index] = temp;
				index++;
			}
		}

		writeToFile(stdt, n+1);
	}
	else if (type == 5) {
		printStrudent();
	}
}

void printStrudent() {
	int n;
	STUDENT* stud1 = readFromFile(&n);

	printStudents(stud1, n);

	int c = 0;

	for (int i = 0; i < n; i++)
	{
		bool has = false;
		if (stud1[i].math < 3) has = true;
		if (stud1[i].phys < 3) has = true;
		if (stud1[i].cherch < 3) has = true;
		if (stud1[i].him < 3) has = true;
		if (stud1[i].sopr < 3) has = true;
		if (has) c++;
	}

	cout << "Количество неудовлетворительных оценок: " << c << endl;
}

void printStudents(STUDENT* stud1, int n) {
	for (int i = 0; i < n; i++) {
		cout << i << " Фамилия:   " << stud1[i].fam << " Имя:   " << stud1[i].name << " Отчество:   " << stud1[i].otch
			<< " Балов по математике:   " << stud1[i].math << " по физике:   " << stud1[i].phys << " по черчению:   "
			<< stud1[i].cherch << " по химии:   " << stud1[i].him << " по сопромату:   " << stud1[i].sopr << endl;
	}
}

STUDENT* readFromFile(int* n) {
	ifstream fin("text.bin", ios::binary | ios::in);
	*n = 0;
	int i;
	fin.read((char*)&(*n), sizeof(int));
	STUDENT* stud = new STUDENT[*n];

	for (i = 0; i < *n; i++) {
		fin.read((char*)&stud[i].fam, sizeof(stud[i].fam));
		fin.read((char*)&stud[i].name, sizeof(stud[i].name));
		fin.read((char*)&stud[i].otch, sizeof(stud[i].otch));
		fin.read((char*)&stud[i].math, sizeof(stud[i].math));
		fin.read((char*)&stud[i].phys, sizeof(stud[i].phys));
		fin.read((char*)&stud[i].cherch, sizeof(stud[i].cherch));
		fin.read((char*)&stud[i].him, sizeof(stud[i].him));
		fin.read((char*)&stud[i].sopr, sizeof(stud[i].sopr));
	}
	fin.close();

	return stud;
}

void writeToFile(STUDENT* stud, int n) {
	std::remove("text.bin");
	ofstream file("text.bin", ios::binary | ios::out | ios::trunc);
	file.write((char*)&n, sizeof(n));

	for (int i = 0; i < n; i++) {
		file.write((char*)&stud[i].fam, sizeof(stud[i].fam));
		file.write((char*)&stud[i].name, sizeof(stud[i].name));
		file.write((char*)&stud[i].otch, sizeof(stud[i].otch));
		file.write((char*)&stud[i].math, sizeof(stud[i].math));
		file.write((char*)&stud[i].phys, sizeof(stud[i].phys));
		file.write((char*)&stud[i].cherch, sizeof(stud[i].cherch));
		file.write((char*)&stud[i].him, sizeof(stud[i].him));
		file.write((char*)&stud[i].sopr, sizeof(stud[i].sopr));
	}

	file.close();
}