#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "";
    cin >> str;

    string str1 = str.substr(0, str.length() / 2);
    string str2 = str.substr(str.length() / 2, str.length());

    if (str1 != str2)
    {
        cout << "다른문장";
    }
    else
    {
        cout << "동일한문장";
    }

    return 0;
}

/* 또 다른 정답 코드

#include <iostream>
using namespace std;

int main()
{
    char vect[11];
    int len;
    int middle;
    int flag;

    cin >> vect;

    for (int i = 0; i < 11; i++)
    {
        if (vect[i] == '\0')
        {
            len = i;
            break;
        }
    }

    middle = len / 2;
    if (middle * 2 != len)
    {
        cout << "다른문장";
        return 0;
    }

    int t = middle;

    for (int x = 0; x < middle; x++)
    {
        if (vect[x] != vect[t])
        {
            cout << "다른문장";
            return 0;
        }
        t++;
    }

    cout << "동일한문장";
    return 0;
}
*/