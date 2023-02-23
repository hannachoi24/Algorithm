#include <iostream>
using namespace std;

int main()
{
    int map[4][5] = {
        1,
        1,
        1,
        1,
        1,
        2,
        2,
        2,
        2,
        2,
        1,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        1,
        0,
    };

    int x = 1;
    int y = 1;
    int sum = 0;
    sum += map[x - 1][y + 0];
    sum += map[x + 1][y + 0];
    sum += map[x + 0][y + 1];
    sum += map[x + 0][y - 1];

    int direct[4][2] = {
        -1, 0,
        1, 0,
        0, 1,
        0, -1};

    for (int i = 0; i < 4; i++)
    {
        int dx = x + direct[i][0];
        int dy = y + direct[i][1];

        if (dx >= 0 && dx < 4 && dy >= 0 && dy < 5)
        {
            sum += map[dx][dy];
        }
    }
    cout << sum;

    return 0;
}