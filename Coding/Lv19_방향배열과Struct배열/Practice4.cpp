#include <iostream>
using namespace std;

int arr[3][5] = {
    4,
    5,
    1,
    9,
    1,
    2,
    2,
    3,
    1,
    9,
    1,
    3,
    1,
    9,
    1,
};

int tar[3] = {1, 9, 1};

int isSame(int dx, int dy)
{
    for (int i = 0; i < 3; i++)
    {
        if (tar[i] != arr[dx][dy + i])
            return 0;
    }

    return 1;
}

int main()
{

    int cnt = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 5 - 3; j++)
        {
            if ((isSame(i, j)))
                cnt++;
        }
    }

    cout << cnt;
    return 0;
}