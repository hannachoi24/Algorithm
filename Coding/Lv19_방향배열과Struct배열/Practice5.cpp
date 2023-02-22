#include <iostream>
using namespace std;

int arr[2][4] = {
    4,
    5,
    4,
    5,
    5,
    5,
    4,
    5,
};

int tar[2][2]{
    4,
    5,
    4,
    5,
};

int isSame(int dx, int dy)
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            if (tar[x][y] != arr[x + dx][y + dy])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int cnt = 0;
    for (int i = 0; i <= 4 - 2; i++)
    {

        if (isSame(0, i))
            cnt++;
    }

    cout << cnt;
    return 0;
}