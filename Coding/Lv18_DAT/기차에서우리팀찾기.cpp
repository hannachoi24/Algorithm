#include <iostream>
using namespace std;

int train[8] = {3, 7, 6, 4, 2, 9, 1, 7};
int team[3];

int isExit(int idx)
{
    for (int i = 0; i < 3; i++)
    {

        if (team[i] != train[idx + i])
            return 0;
    }
    return 1;
}

int main()
{

    for (int x = 0; x < 3; x++)
    {
        cin >> team[x];
    }

    for (int i = 0; i <= 8 - 3; i++)
    {
        if (isExit(i))
        {
            cout << i << "번~" << i + 2 << "번 칸";
            break;
        }
    }
    return 0;
}