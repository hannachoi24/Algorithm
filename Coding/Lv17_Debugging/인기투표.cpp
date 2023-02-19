#include <iostream>
using namespace std;

int main()
{
    int vect[3][3] = {
        3,
        7,
        4,
        2,
        2,
        4,
        2,
        2,
        5,
    };

    int target[3] = {0};

    for (int a = 0; a < 3; a++)
    {
        cin >> target[a];
    }

    int dat[9] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dat[vect[i][j]]++;
        }
    }

    int maxIdx = 0;
    for (int k = 0; k < 3; k++)
    {
        int input = target[k];
        if (dat[input] > dat[maxIdx])
        {
            maxIdx = input;
        }
    }

    cout << maxIdx;

    return 0;
}