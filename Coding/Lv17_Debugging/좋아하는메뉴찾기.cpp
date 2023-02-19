#include <iostream>
#include <cstring>
using namespace std;

char s1[5] = "MTKC";

int isExist(char a)
{
    for (int i = 0; i < 4; i++)
    {
        if (s1[i] == a)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char s;
    cin >> s;

    if (isExist(s))
    {
        cout << "발견";
    }
    else
        cout << "미발견";

    return 0;
}
