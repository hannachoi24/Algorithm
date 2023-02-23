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

    int direct[4][2] = {
        -1, 0,
        1, 0,
        0, 1,
        0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 5)
            continue;
        sum += map[nx][ny];
    }

    cout << sum;

    return 0;
}