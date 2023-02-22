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
    sum += map[x - 1][y];
    sum += map[x + 1][y];
    sum += map[x][y + 1];
    sum += map[x][y - 1];

    cout << sum;
}