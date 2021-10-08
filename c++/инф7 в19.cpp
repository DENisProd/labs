#include <iostream>

#include <string.h>

using namespace std;

struct STUDENT {

char surname[25]; // Фамилия

char name[25]; //Имя

int math;// Математика

int phiz;//Физика

int cherch; // Черчение

int him; // Химия

int sopr; // Сопромат

};

int main()

{

setlocale(0, "Russian");

STUDENT student[100];

int n;

cout << "Введите количество студентов:\n";

cin >> n;

for (int i = 0; i < n; i++)

{

cout << "Введите фамилию студента "<< i + 1 << "\n";

cin >> student[i].surname;

cout << "Введите имя студента " << i + 1 << "\n";

cin >> student[i].name;

cout << "Введите оценку по математике студента " << i + 1 << "\n";

cin >> student[i].math;

cout << "Введите оценку по физике студента " << i + 1 << "\n";

cin >> student[i].phiz;

cout << "Введите оценку по черчению студента " << i + 1 << "\n";

cin >> student[i].cherch;

cout << "Введите оценку по химии студента " << i + 1 << "\n";

cin >> student[i].him;

cout << "Введите оценку по сопромату студента " << i + 1 << "\n";

cin >> student[i].sopr;

}

double sredn = 0;

for (int i = 0; i < n; i++)

{

sredn += student[i].phiz;

}

sredn /= n;

cout << "Средний балл группы по физике : " << sredn;

}