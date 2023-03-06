#include <iostream>
using namespace std;

string name1;
string name2;

int isSame()
{
    int len1 = name1.length();

    for (int i = 0; i < len1; i++)
    {
        if (name1 == name2)
        {
            return 1;
        }
        else if (name1 != name2)
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    cin >> name1;
    cin >> name2;

    if (isExist())
    {
        cout << "동명";
    }
    else
    {
        cout << "남남";
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int isSame(char name1[100], char name2[100])
{
    int n1 = 0;
    int n2 = 0;

    for (int i = 0; i < 100; i++) {
        if (name1[i] == '\0') {
            n1 = i;
            break;
        }
    }

    for (int i = 0; i < 100; i++) {
        if (name2[i] == '\0') {
            n2 = i;
            break;
        }
    }

    //두 글자길이가 다르면 다른 문자열
    if (n1 != n2) return 0;

    //글자 길이만큼 한글자씩 비교
    for (int i = 0; i < n1; i++) {
        if (name1[i] != name2[i]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char name1[100] = { 0 };
    char name2[100] = { 0 };

    cin >> name1 >> name2;

    if (isSame(name1, name2) == 1) {
        cout << "동명";
    }
    else {
        cout << "남남";
    }
    return 0;
}
*/