#include <iostream>
using namespace std;

int map[4][4];

int rectSum(int x, int y)
{
    int sum = 0;
    for (int i = x; i < x + 2; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            sum += map[i][j];
        }
    }

    return sum;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j];
        }
    }

    int MAX = -1;
    int maxX = -1;
    int maxY = -1;
    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - 2; j++)
        {
            int sum = rectSum(i, j);

            if (sum > MAX)
            {
                MAX = sum;
                maxX = i;
                maxY = j;
            }
        }
    }

    cout << "(" << maxX << "," << maxY << ")";

    return 0;
}