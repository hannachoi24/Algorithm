#include <iostream>
using namespace std;

// Direct Address Datatable

int black[2][4] = {
    5,
    7,
    9,
    55,
    30,
    10,
    6,
    8,
};

int town[2][4] = {
    1,
    2,
    3,
    4,
    5,
    7,
    10,
    15,
};

int per;
int crim;

int dat[100];

int main()
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dat[black[i][j]] = 1;
        }
    }

    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (dat[town[x][y]] == 1)
            {
                crim++;
            }
            else
                per++;
        }
    }

    cout << "person : " << per << endl;
    cout << "crim : " << crim;

    return 0;
}