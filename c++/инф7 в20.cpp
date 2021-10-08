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
        if (s[i].math == 5) c++;
        if (s[i].phys == 5) c++;
        if (s[i].cherch == 5) c++;
        if (s[i].him == 5) c++;
        if (s[i].sopr == 5) c++;
    }

    cout << "Количество отличных оценок: " << c << endl;
}