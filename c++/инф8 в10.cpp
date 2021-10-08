#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct Student {
    char fam[15];
    char name[15];
    char otch[15];
    char street[15];
    int house;
    int flat;
    int tel;
};

void write(Student* students, int n) {
    std::remove("lab8.iluha");
    ofstream file("lab8.iluha", ios::binary | ios::out | ios::trunc);
    file.write((char*)&n, sizeof(n));

    for (int i = 0; i < n; i++) {
        file.write((char*)&students[i].fam, sizeof(students[i].fam));
        file.write((char*)&students[i].name, sizeof(students[i].name));
        file.write((char*)&students[i].otch, sizeof(students[i].otch));
        file.write((char*)&students[i].street, sizeof(students[i].street));
        file.write((char*)&students[i].house, sizeof(students[i].house));
        file.write((char*)&students[i].flat, sizeof(students[i].flat));
        file.write((char*)&students[i].tel, sizeof(students[i].tel));
    }

    file.close();
}

int main()
{
    setlocale(0, "Russian");
    int n = 0, i = 0;
    cout << "Количество студентов: " << endl;
    cin >> n;
    Student* students = new Student[n];

    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << " Введите фамилию, имя, отчество, адрес – улица, дом, квартира, домашний телефон " << endl;
        cin >> students[i].fam;
        cin >> students[i].name;
        cin >> students[i].otch;
        cin >> students[i].street;
        cin >> students[i].house;
        cin >> students[i].flat;
        cin >> students[i].tel;
    }
    cout << endl;

    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << " Фамилия: " << students[i].fam << " имя: " << students[i].name << " отчество: " << students[i].otch << " адрес – ул.:" << students[i].street << " дом: " << students[i].house << " квартира: " << students[i].flat << " домашний телефон: " << students[i].tel << endl;
    }

    cout << endl;

    for (i = 0; i < n; i++) {
        if (students[i].tel < 100000000) {
            cout << "До " << students[i].fam << " " << students[i].name << " ул. " << students[i].street << " нельзя дозвониться!\n";
        }
    }
    write(students, n);

    students = NULL;
    cout << "\nСписок студентов очищен.\n";
    cout << "Чтение из файла.\n";
    ifstream fin("lab8.iluha", ios::binary | ios::in);
    fin.read((char*)&n, sizeof(int));
    students = new Student[n];
    cout << "Чтение из файла..\n";
    for (i = 0; i < n; i++) {
        fin.read((char*)&students[i].fam, sizeof(students[i].fam));
        fin.read((char*)&students[i].name, sizeof(students[i].name));
        fin.read((char*)&students[i].otch, sizeof(students[i].otch));
        fin.read((char*)&students[i].street, sizeof(students[i].street));
        fin.read((char*)&students[i].house, sizeof(students[i].house));
        fin.read((char*)&students[i].flat, sizeof(students[i].flat));
        fin.read((char*)&students[i].tel, sizeof(students[i].tel));
    }
    cout << "Чтение из файла...\n";
    fin.close();
    cout << "Файл прочтён. Вывожу данные о студентах:\n";
    
    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << " Фамилия: "<< students[i].fam<<" имя: "<< students[i].name <<" отчество: "<< students[i].otch <<" адрес – ул.:"<< students[i].street <<" дом: "<< students[i].house <<" квартира: "<< students[i].flat <<" домашний телефон: " <<students[i].tel << endl;
    }
    cout << endl;

    for (i = 0; i < n; i++) {
        if (students[i].tel < 100000000) {
            cout << "До " << students[i].fam << " " << students[i].name << " ул. " << students[i].street << " нельзя дозвониться!\n";
        }
    }

    cout << "\n1. Удалить\n2. Вставить\n";
    int action = 0; cin >> action;
    int position = 0; cin >> position;

    if (action == 1) {
        Student* bufferArray = new Student[n - 1];
        Student temp;
        int j = 0;
        for (i = 0; i < n; i++)
        {
            if (i != position) {
                temp = students[i];
                bufferArray[j] = temp;
                j++;
            }
        }
        write(bufferArray, n-1);
    }
    else if (action == 2) {
        Student* bufferArray = new Student[n + 1];
        Student temp, newStudent;

        cout << " Введите фамилию, имя, отчество, адрес – улица, дом, квартира, домашний телефон " << endl;
        cin >> newStudent.fam;
        cin >> newStudent.name;
        cin >> newStudent.otch;
        cin >> newStudent.street;
        cin >> newStudent.house;
        cin >> newStudent.flat;
        cin >> newStudent.tel;

        int j = 0;
        for (i = 0; i < n; i++)
        {
            if (i != position) {
                temp = students[i];
                bufferArray[j] = temp;
                j++;
            }
            else if (i == position) {
                bufferArray[j] = newStudent;
                j++;
                temp = students[i];
                bufferArray[j] = temp;
                j++;
            }
        }
        write(bufferArray, n + 1);
    }

    cout << "Чтение из файла.\n";
    ifstream f("lab8.iluha", ios::binary | ios::in);
    f.read((char*)&n, sizeof(int));
    students = new Student[n];
    cout << "Чтение из файла..\n";
    for (i = 0; i < n; i++) {
        f.read((char*)&students[i].fam, sizeof(students[i].fam));
        f.read((char*)&students[i].name, sizeof(students[i].name));
        f.read((char*)&students[i].otch, sizeof(students[i].otch));
        f.read((char*)&students[i].street, sizeof(students[i].street));
        f.read((char*)&students[i].house, sizeof(students[i].house));
        f.read((char*)&students[i].flat, sizeof(students[i].flat));
        f.read((char*)&students[i].tel, sizeof(students[i].tel));
    }
    cout << "Чтение из файла...\n";
    f.close();
    cout << "Файл прочтён. Вывожу данные о студентах:\n";

    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << " Фамилия: " << students[i].fam << " имя: " << students[i].name << " отчество: " << students[i].otch << " адрес – ул.:" << students[i].street << " дом: " << students[i].house << " квартира: " << students[i].flat << " домашний телефон: " << students[i].tel << endl;
    }
    cout << endl;

    for (i = 0; i < n; i++) {
        if (students[i].tel < 100000000) {
            cout << "До " << students[i].fam << " " << students[i].name << " ул. " << students[i].street << " нельзя дозвониться!\n";
        }
    }

}


