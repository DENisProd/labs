#include <iostream>

using namespace std;

struct STUDENT {
    string fam;
    string name;
    string otch;
    int math;
    int phys;
    int cherch;
    int him;
    int sopr;
};

int main()
{
    setlocale(0, "Russian");
    int n = 0;
    cout << "Количество студентов: " << endl;
    cin >> n;
    STUDENT* s = new STUDENT[n];

    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << " Введите фамилию, имя, отчество и оценки по математике, физике, черчении, химии и сопромату" << endl;
        cin >> s[i].fam;
        cin >> s[i].name;
        cin >> s[i].otch;
        cin >> s[i].math;
        cin >> s[i].phys;
        cin >> s[i].cherch;
        cin >> s[i].him;
        cin >> s[i].sopr;
    }

    int c = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        b = s[i].math + s[i].phys + s[i].cherch + s[i].him + s[i].sopr;
        if (b == 25) c++;
    }

    cout << c << " студентов сдали все экзамены на 5 " << endl;
}