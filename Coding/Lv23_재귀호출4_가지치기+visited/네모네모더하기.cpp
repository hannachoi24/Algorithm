#include <iostream>
using namespace std;

int map[4][4];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }

    int sum;

    // 가로줄
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += map[i][j];
        }
        map[i][3] = sum;
    }

    // 세로줄
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += map[j][i];
        }
        map[3][i] = sum;
    }

    // 대각선
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += map[i][i];
    }
    map[3][3] = sum;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}