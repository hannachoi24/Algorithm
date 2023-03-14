#include <iostream>
using namespace std;

char map[4][4];
int Ax, Ay, Bx, By;
int result;

int Distance()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] == 'A')
            {
                Ax = i;
                Ay = j;
            }

            if (map[i][j] == 'B')
            {
                Bx = i;
                By = j;
            }
        }
    }

    result = abs((Ax - Bx) + (Ay - By));

    return result;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }

    Distance();

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int abs(int value)
{
    if (value < 0) return -value;
    return value;
}

int main() {
    char map[4][4];

    for (int i = 0; i < 4; i++) {
        cin >> map[i];
    }

    int ax, ay, bx, by;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            if (map[y][x] == 'A') {
                ax = y;
                ay = x;
            }
            if (map[y][x] == 'B') {
                bx = y;
                by = x;
            }
        }
    }

    cout << abs(ax - bx) + abs(ay - by);
    return 0;
}
*/