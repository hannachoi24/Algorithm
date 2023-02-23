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

    int directX[5] = {0, -1, -1, 1, 1};
    int directY[5] = {0, -1, 1, -1, 1};

    int mul = 1;
    for (int i = 0; i < 5; i++)
    {
        int nx = x + directX[i];
        int ny = y + directY[i];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 5)
            continue;
        mul *= map[nx][ny];
    }

    cout << mul;

    return 0;
}