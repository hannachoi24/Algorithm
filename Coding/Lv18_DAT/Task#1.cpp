#include <iostream>
using namespace std;

int main()
{
    int map[3][4] = {
        {65000, 35, 42, 70},
        {70, 35, 65000, 1300},
        {65000, 30000, 38, 42}};

    int dat[80000] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dat[map[i][j]]++;
        }
    }

    int maxIndex = 0;

    for (int k = 0; k < 80000; k++)
    {
        if (dat[k] > dat[maxIndex])
        {
            maxIndex = k;
        }
    }

    cout << maxIndex;

    return 0;
}