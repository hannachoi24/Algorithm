#include <iostream>
using namespace std;

char map[4][5] = {
    "ABAB",
    "BTBT",
    "KABK",
    "KBTK"};

char tar[2][3] = {
    "AB",
    "BT"};

int isSame(int dx, int dy)
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (tar[x][y] != map[x + dx][y + dy])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int cnt = 0;
    for (int i = 0; i <= 4 - 2; i++)
    {
        for (int j = 0; j <= 4 - 2; j++)
        {
            if (isSame(i, j))
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}