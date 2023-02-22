#include <iostream>
using namespace std;

// 패턴 찾기

char da[10] = "ABTRC";
char db[4] = "BTR";

int isSame(int idx)
{
    for (int i = 0; i < 3; i++)
    {
        if (db[i] != da[idx + i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    if (isSame(1))
    {
        cout << "O";
    }
    else
    {
        cout << "X";
    }

    return 0;
}