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

    for (int i = 0; i < n; i++)
    {
        bool has = false;
        if (s[i].math < 3) has = true;
        if (s[i].phys < 3) has = true;
        if (s[i].cherch < 3) has = true;
        if (s[i].him < 3) has = true;
        if (s[i].sopr < 3) has = true;
        if (has) c++;
    }

    cout << n-c << " студентов не имеют задолженности" << endl;
}