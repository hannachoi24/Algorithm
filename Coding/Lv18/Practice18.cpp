#include <iostream>
#include <cstring>
using namespace std;

// Direct Address Datatable

int map[3][4] = {
    4,
    5,
    7,
    6,
    1,
    5,
    5,
    4,
    1,
    1,
    1,
    1,
};

int target[2][3] = {
    5,
    6,
    4,
    1,
    5,
    3,
};

int main()
{

    int dat[100] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dat[map[i][j]]++;
        }
    }

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << dat[target[x][y]];
        }
        cout << endl;
    }

    return 0;
}