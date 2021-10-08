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

    int math_max = 0, phys_max = 0, cherch_max = 0, him_max = 0, sopr_max = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i].math > 2) math_max += s[i].math;
        if (s[i].phys > 2) phys_max += s[i].phys;
        if (s[i].cherch > 2) cherch_max += s[i].cherch;
        if (s[i].him > 2) him_max += s[i].him;
        if (s[i].sopr > 2) sopr_max += s[i].sopr;
    }

    int current = math_max;
    string sub = "mathematics";
    if (current < phys_max)
    {
        current = phys_max;
        sub = "physics";
    }
    if (current < cherch_max)
    {
        current = cherch_max;
        sub = "drawing";
    }
    if (current < him_max)
    {
        current = him_max;
        sub = "chemistry";
    }
    if (current < sopr_max)
    {
        current = sopr_max;
        sub = "sopromat";
    }

    cout << "Лучше всего сдали " << sub << endl;
}