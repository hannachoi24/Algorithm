#include <iostream>
using namespace std;

int main()
{
    int mask1[4][4] = {
        0, 0, 0, 1,
        1, 1, 0, 1,
        1, 0, 0, 1,
        1, 1, 1, 1};

    int mask2[4][4] = {
        1, 1, 1, 1,
        1, 0, 1, 1,
        1, 0, 0, 0,
        1, 0, 0, 0};

    int result[4][4] = {0};

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (mask1[x][y] == 1 || mask2[x][y] == 1)
            {
                result[x][y] = 1;
            }
        }
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (result[x][y] == 0)
            {
                cout << "(" << x << "," << y << ")" << '\n';
            }
        }
    }

    return 0;
}