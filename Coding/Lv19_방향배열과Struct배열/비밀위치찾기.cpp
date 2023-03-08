#include <iostream>
using namespace std;

char map[3][5] = {
    "ABGK",
    "TTAB",
    "ACCD"};

char target[2][3];

int isPattern(int dx, int dy)
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (target[x][y] != map[dx + x][dy + y])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> target[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i <= 3 - 2; i++)
    {
        for (int j = 0; j <= 4 - 2; j++)
        {
            if (isPattern(i, j))
            {
                cnt++;
            }
        }
    }

    if (cnt > 0)
    {
        cout << "발견(" << cnt << "개)";
    }
    else
    {
        cout << "미발견";
    }

    return 0;
}